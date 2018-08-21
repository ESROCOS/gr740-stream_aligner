/*
 * Conversion functions for asn1SccBase_Time.
 */

#ifndef BASE_TIME_CONVERT
#define BASE_TIME_CONVERT

#include "baseTypes.h"
#include "Time.hpp"
#include <string.h>
#include <stdio.h>


//Conversion functions from asn1 to c++ type
void asn1SccBase_Time_fromAsn1(base::Time& result, const asn1SccBase_Time& asnVal);

//Conversion functions from C++ to Asn1 type
void asn1SccBase_Time_toAsn1(asn1SccBase_Time& result, const base::Time& baseObj);


#endif //BASE_TIME_CONVERT
