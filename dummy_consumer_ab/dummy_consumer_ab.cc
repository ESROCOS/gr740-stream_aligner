/* User code: This file will not be overwritten by TASTE. */

#include "dummy_consumer_ab.h"
#include <iostream>

static int64_t last_timestamp_a = 0;
static int64_t last_timestamp_b = 0;

void dummy_consumer_ab_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void dummy_consumer_ab_PI_A(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    /* Write your code here! */
    std::cout << IN_smpl->time.microseconds << ": A\n";
    if ((last_timestamp_a > IN_smpl->time.microseconds) || (last_timestamp_b > IN_smpl->time.microseconds))
    {
	std::cout << "Invalid sample on A\n";
    }
    last_timestamp_a = IN_smpl->time.microseconds;
}

void dummy_consumer_ab_PI_B(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    /* Write your code here! */
    std::cout << IN_smpl->time.microseconds << ": B\n";
    if ((last_timestamp_a > IN_smpl->time.microseconds) || (last_timestamp_b > IN_smpl->time.microseconds))
    {
	std::cout << "Invalid sample on B\n";
    }
    last_timestamp_b = IN_smpl->time.microseconds;
}

