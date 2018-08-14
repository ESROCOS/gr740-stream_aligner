#ifndef GENERATED_ASN1SCC_Context_gr740_stream_aligner_H
#define GENERATED_ASN1SCC_Context_gr740_stream_aligner_H
/*
Code automatically generated by asn1scc tool
*/
#include "dataview-uniq.h"
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif



typedef struct {
    asn1SccT_Double perioda;
    asn1SccT_Double periodb;
} asn1SccContext_gr740_stream_aligner;

flag asn1SccContext_gr740_stream_aligner_Equal(const asn1SccContext_gr740_stream_aligner* pVal1, const asn1SccContext_gr740_stream_aligner* pVal2);

void asn1SccContext_gr740_stream_aligner_Initialize(asn1SccContext_gr740_stream_aligner* pVal);

#define ERR_CONTEXT_GR740_STREAM_ALIGNER_PERIODA		1  /**/
#define ERR_CONTEXT_GR740_STREAM_ALIGNER_PERIODB		12  /**/
flag asn1SccContext_gr740_stream_aligner_IsConstraintValid(const asn1SccContext_gr740_stream_aligner* pVal, int* pErrCode);

extern const asn1SccContext_gr740_stream_aligner gr740_stream_aligner_ctxt; 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif