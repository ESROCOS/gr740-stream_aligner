/* User code: This file will not be overwritten by TASTE. */

#include "dummy_producer_b.h"
#include <ctime>

asn1SccBase_samples_RigidBodyState smpl;

void dummy_producer_b_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void dummy_producer_b_PI_period()
{
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);
    smpl.time.microseconds = spec.tv_nsec / 1000 + spec.tv_sec * 1000000;
    dummy_producer_b_RI_B(&smpl);
}

