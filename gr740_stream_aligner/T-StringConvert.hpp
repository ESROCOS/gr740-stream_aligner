/*
 * Conversion functions for asn1SccT_String.
 */

#ifndef T_STRING_CONVERT
#define T_STRING_CONVERT

#include "baseTypes.h"
#include <string.h>
#include <stdio.h>


//Conversion functions from asn1 to c++ type

template <typename T>
void asn1SccT_String_fromAsn1(std::string& result, const T & asnVal,    asn1SccT_UInt32 length_numT_String=numT_String)
{

    char cstr[length_numT_String+1];

    memcpy(cstr, asnVal.arr,asnVal.nCount);
    cstr[asnVal.nCount] = '\0';

    result = std::string(cstr);


}

//Conversion functions from C++ to Asn1 type

template <typename T>
void asn1SccT_String_toAsn1(T & result, const std::string& baseObj,    asn1SccT_UInt32 length_numT_String=numT_String)
{

     // Limit length to the maximum supported

    asn1SccT_UInt32 len = strlen(baseObj.c_str());
    if (len+1 > length_numT_String)
    {
        len = length_numT_String-1;
        fprintf(stderr, "WARNING: string truncated to %lld characters.\n",length_numT_String );
    }

    memcpy(result.arr, baseObj.c_str() , len);
    result.nCount = len;
    result.arr[len]='\0';

}


#endif //T_STRING_CONVERT
