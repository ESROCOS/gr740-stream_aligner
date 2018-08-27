/* User code: This file will not be overwritten by TASTE. */

#include "delay.h"
#include <iostream>
#include <queue>

/* Function static data is declared in this file : */
#include "Context-delay.h"

static std::queue< asn1SccBase_samples_RigidBodyState > samples;
static asn1SccBase_samples_RigidBodyState outSample;

void delay_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void delay_PI_X(const asn1SccBase_samples_RigidBodyState *IN_smpl)
{
    samples.push(*IN_smpl);
    if (samples.size() >= delay_ctxt.nodelayedvalues)
    {
	outSample = samples.front();
	//std::cout << "delay_PI_X: " << outSample.time.microseconds << ", X\n";
	delay_RI_Y(&outSample);
	samples.pop();	
    }
}

