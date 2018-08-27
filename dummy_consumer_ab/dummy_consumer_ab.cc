/* User code: This file will not be overwritten by TASTE. */

#include "dummy_consumer_ab.h"
#include <iostream>
#include <ctime>

static int64_t reference_timestamp = 0;
static int64_t last_timestamp_a = 0;
static int64_t last_timestamp_b = 0;

void dummy_consumer_ab_startup()
{
    std::cout << "dummy_consumer_ab_startup\n";
    std::cout << "Timestamp [us], Port Identifier\n";

    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    reference_timestamp = spec.tv_nsec / 1000 + spec.tv_sec * 1000000;
}

void dummy_consumer_ab_PI_A(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    std::cout << "OUT: " << ((IN_smpl->time.microseconds - reference_timestamp) / 1000000.f) << ", A\n";
    if ((last_timestamp_a > IN_smpl->time.microseconds) || (last_timestamp_b > IN_smpl->time.microseconds))
    {
	std::cout << "Invalid sample on A\n";
    }
    last_timestamp_a = IN_smpl->time.microseconds;
}

void dummy_consumer_ab_PI_B(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    std::cout << "OUT: " << ((IN_smpl->time.microseconds - reference_timestamp) / 1000000.f) << ", B\n";
    if ((last_timestamp_a > IN_smpl->time.microseconds) || (last_timestamp_b > IN_smpl->time.microseconds))
    {
	std::cout << "Invalid sample on B\n";
    }
    last_timestamp_b = IN_smpl->time.microseconds;
}

