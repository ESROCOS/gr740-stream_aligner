
#include "Base-TimeConvert.hpp"

//Conversion functions from asn1 to c++ type



void asn1SccBase_Time_fromAsn1(base::Time& result, const asn1SccBase_Time& asnVal)
{
    result.microseconds = asnVal.microseconds;

}

//Conversion functions from c++ type to asn1

void asn1SccBase_Time_toAsn1(asn1SccBase_Time& result, const base::Time& baseObj)
{
    result.microseconds = baseObj.microseconds;

}


