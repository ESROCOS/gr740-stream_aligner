/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_gr740_stream_aligner__
#define __USER_CODE_H_gr740_stream_aligner__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void gr740_stream_aligner_startup();

void gr740_stream_aligner_PI_A(const asn1SccBase_samples_RigidBodyState *);

void gr740_stream_aligner_PI_B(const asn1SccBase_samples_RigidBodyState *);

extern void gr740_stream_aligner_RI_aligned_A(const asn1SccBase_samples_RigidBodyState *);

extern void gr740_stream_aligner_RI_aligned_B(const asn1SccBase_samples_RigidBodyState *);

#ifdef __cplusplus
}
#endif


#endif
