/* User code: This file will not be overwritten by TASTE. */

#include "gr740_stream_aligner.h"
#include "Context-gr740-stream-aligner.h"
#include "base_support/Base-samples-RigidBodyStateConvert.hpp"
#include "stream_aligner/TimestampEstimator.hpp"
#include "stream_aligner/StreamAligner.hpp"
#include <algorithm>
#include <iostream>

// Instance of the stream aligner with 2 independent streams
stream_aligner::StreamAligner<2> aligner;
// Unfortunately, we have to set the buffer size as a constant expression. Otherwise, we cannot deduce the template ...
const unsigned int buf_size(20);
const double timeout(std::max(gr740_stream_aligner_ctxt.perioda, gr740_stream_aligner_ctxt.periodb));
const double window_size(2. * timeout);
int streamA, streamB;
base::samples::RigidBodyState smplA, smplB;
asn1SccBase_samples_RigidBodyState outA, outB;
bool buf_size_ok = false;

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
}

void gr740_stream_aligner_PI_A(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    if (!buf_size_ok)
        return;
    asn1SccBase_samples_RigidBodyState_fromAsn1(smplA, *IN_smpl);
    aligner.push<base::samples::RigidBodyState, buf_size>(streamA, smplA.time, smplA);
    while (aligner.step()) ;
}

void gr740_stream_aligner_PI_B(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    if (!buf_size_ok)
        return;
    asn1SccBase_samples_RigidBodyState_fromAsn1(smplB, *IN_smpl);
    aligner.push<base::samples::RigidBodyState, buf_size>(streamB, smplB.time, smplB);
    while (aligner.step()) ;
}

