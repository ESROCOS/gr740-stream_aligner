/* User code: This file will not be overwritten by TASTE. */

#include "gr740_stream_aligner.h"
#include "Context-gr740-stream-aligner.h"
#include "base_support/Base-samples-RigidBodyStateConvert.hpp"
#include "stream_aligner/TimestampEstimator.hpp"
#include "stream_aligner/StreamAligner.hpp"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstring>

#define DEBUG

#ifdef DEBUG
static int64_t reference_timestamp = 0;
#endif
// Instance of the stream aligner with 2 independent streams
stream_aligner::StreamAligner<2> aligner;
// Unfortunately, we have to set the buffer size as a constant expression. Otherwise, we cannot deduce the template ...
static const unsigned int buf_size(20);
static const double maxPeriod(std::max(gr740_stream_aligner_ctxt.perioda, gr740_stream_aligner_ctxt.periodb));
static const double timeout(maxPeriod + maxPeriod * 0.1f);
static const double window_size(2. * timeout);
static int streamA, streamB;
static base::samples::RigidBodyState smplA, smplB;
static asn1SccBase_samples_RigidBodyState outA, outB;
static bool buf_size_ok = false;

void init_rbs(asn1SccBase_samples_RigidBodyState *rbs)
{
   memset(rbs, 0, sizeof(asn1SccBase_samples_RigidBodyState));
   rbs->position.data.nCount = 3;
   rbs->cov_position.data.nCount = 9;
   rbs->orientation.im.nCount = 3;
   rbs->cov_orientation.data.nCount = 9;
   rbs->velocity.data.nCount = 3;
   rbs->cov_velocity.data.nCount = 9;
   rbs->angular_velocity.data.nCount = 3;
   rbs->cov_angular_velocity.data.nCount = 9;
}

// These callbacks are called in order of the timestamps producing to aligned streams
void rbs_callback_a(const base::Time& time, const base::samples::RigidBodyState& rbs)
{
    asn1SccBase_samples_RigidBodyState_toAsn1(outA, rbs);
    gr740_stream_aligner_RI_aligned_A(&outA);
}

void rbs_callback_b(const base::Time& time, const base::samples::RigidBodyState& rbs)
{
    asn1SccBase_samples_RigidBodyState_toAsn1(outB, rbs);
    gr740_stream_aligner_RI_aligned_B(&outB);
}

void gr740_stream_aligner_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
    init_rbs(&outA);
    init_rbs(&outB);
    std::cout << "[gr740_stream_aligner_startup] startup\n";

    std::cout << "Buffer size: " << buf_size << "\n";
    std::cout << "Timeout [s]: " << timeout << "\n";
    std::cout << "Window [s]: " << window_size << "\n";
    aligner.setTimeout(base::Time::fromSeconds(timeout));

    // Check buffer size
    const unsigned int bufA(window_size / gr740_stream_aligner_ctxt.perioda);
    const unsigned int bufB(window_size / gr740_stream_aligner_ctxt.periodb);
    if (bufA > buf_size)
    {
	std::cout << "Error: buffer size " << buf_size << " too small. Need " << bufA << "\n";
	return;
    }
    if (bufB > buf_size)
    {
	std::cout << "Error: buffer size " << buf_size << " too small. Need " << bufB << "\n";
	return;
    }
    buf_size_ok = true;

    // Register streams
    streamA = aligner.registerStream<base::samples::RigidBodyState, buf_size>(&rbs_callback_a, base::Time::fromSeconds(gr740_stream_aligner_ctxt.perioda), 1);
    streamB = aligner.registerStream<base::samples::RigidBodyState, buf_size>(&rbs_callback_b, base::Time::fromSeconds(gr740_stream_aligner_ctxt.periodb), 2);

#ifdef DEBUG
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    reference_timestamp = spec.tv_nsec / 1000 + spec.tv_sec * 1000000;
#endif
}

void gr740_stream_aligner_PI_A(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    if (!buf_size_ok)
        return;
    asn1SccBase_samples_RigidBodyState_fromAsn1(smplA, *IN_smpl);
#ifdef DEBUG
    std::cout << "[gr740_stream_aligner_PI_A] ts: " << ((IN_smpl->time.microseconds - reference_timestamp) / 1000000.f) << "\n";
    std::cout << "[gr740_stream_aligner_PI_A] pos: " << smplA.position.transpose() << " orient: " << smplA.orientation.vec().transpose() << std::endl;
#endif
    aligner.push<base::samples::RigidBodyState, buf_size>(streamA, smplA.time, smplA);
    while (aligner.step()) ;
}

void gr740_stream_aligner_PI_B(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    if (!buf_size_ok)
        return;
    asn1SccBase_samples_RigidBodyState_fromAsn1(smplB, *IN_smpl);
#ifdef DEBUG
    std::cout << "[gr740_stream_aligner_PI_B] ts: " << ((IN_smpl->time.microseconds - reference_timestamp) / 1000000.f) << "\n";
    std::cout << "[gr740_stream_aligner_PI_B] pos: " << smplB.position.transpose() << " orient: " << smplB.orientation.vec().transpose() << std::endl;
#endif
    aligner.push<base::samples::RigidBodyState, buf_size>(streamB, smplB.time, smplB);
    while (aligner.step()) ;
}

