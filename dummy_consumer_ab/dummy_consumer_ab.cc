/* User code: This file will not be overwritten by TASTE. */

#include "dummy_consumer_ab.h"
#include <iostream>

void dummy_consumer_ab_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void dummy_consumer_ab_PI_A(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    /* Write your code here! */
    std::cout << "A: " << IN_smpl->time.microseconds << "\n";
}

void dummy_consumer_ab_PI_B(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    /* Write your code here! */
    std::cout << "B: " << IN_smpl->time.microseconds << "\n";
}

