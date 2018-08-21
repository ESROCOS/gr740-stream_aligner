/*
 * Conversion functions for asn1SccBase_samples_RigidBodyState.
 */

#ifndef BASE_SAMPLES_RIGIDBODYSTATE_CONVERT
#define BASE_SAMPLES_RIGIDBODYSTATE_CONVERT

#include "baseTypes.h"
#include "RigidBodyState.hpp"
#include <string.h>
#include <stdio.h>

#include "Base-TimeConvert.hpp"
#include "T-StringConvert.hpp"
#include "T-StringConvert.hpp"
#include "Wrappers-Vector3dConvert.hpp"
#include "Wrappers-Matrix3dConvert.hpp"
#include "Wrappers-QuaterniondConvert.hpp"
#include "Wrappers-Matrix3dConvert.hpp"
#include "Wrappers-Vector3dConvert.hpp"
#include "Wrappers-Matrix3dConvert.hpp"
#include "Wrappers-Vector3dConvert.hpp"
#include "Wrappers-Matrix3dConvert.hpp"

//Conversion functions from asn1 to c++ type
void asn1SccBase_samples_RigidBodyState_fromAsn1(base::samples::RigidBodyState& result, const asn1SccBase_samples_RigidBodyState& asnVal);

//Conversion functions from C++ to Asn1 type
void asn1SccBase_samples_RigidBodyState_toAsn1(asn1SccBase_samples_RigidBodyState& result, const base::samples::RigidBodyState& baseObj);


#endif //BASE_SAMPLES_RIGIDBODYSTATE_CONVERT
