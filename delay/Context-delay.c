/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "Context-delay.h"


const asn1SccContext_delay delay_ctxt = {
    .nodelayedvalues = 5
};


flag asn1SccContext_delay_Equal(const asn1SccContext_delay* pVal1, const asn1SccContext_delay* pVal2)
{
	flag ret=TRUE;

    ret = (pVal1->nodelayedvalues == pVal2->nodelayedvalues);

	return ret;

}

void asn1SccContext_delay_Initialize(asn1SccContext_delay* pVal)
{


	/*set nodelayedvalues */
	asn1SccT_UInt16_Initialize((&(pVal->nodelayedvalues)));
}

flag asn1SccContext_delay_IsConstraintValid(const asn1SccContext_delay *pVal, int* pErrCode)
{
    flag ret = TRUE;
	
    ret = (pVal->nodelayedvalues <= 65535UL);
    *pErrCode = ret ? 0 :  ERR_CONTEXT_DELAY_NODELAYEDVALUES;

	return ret;
}

