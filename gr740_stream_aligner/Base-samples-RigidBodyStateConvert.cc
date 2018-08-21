
#include "Base-samples-RigidBodyStateConvert.hpp"

#include "OpaqueConversion.hpp"

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



void asn1SccBase_samples_RigidBodyState_fromAsn1(base::samples::RigidBodyState& result, const asn1SccBase_samples_RigidBodyState& asnVal)
{
    asn1SccBase_Time_fromAsn1(result.time, asnVal.time);

    asn1SccT_String_fromAsn1(result.sourceFrame, asnVal.sourceframe);

    asn1SccT_String_fromAsn1(result.targetFrame, asnVal.targetframe);


    wrappers::Vector3d position_intermediate;
    asn1SccWrappers_Vector3d_fromAsn1(position_intermediate, asnVal.position);
    Base_Vector3d_fromIntermediate(result.position, position_intermediate);


    wrappers::Matrix3d cov_position_intermediate;
    asn1SccWrappers_Matrix3d_fromAsn1(cov_position_intermediate, asnVal.cov_position);
    Base_Matrix3d_fromIntermediate(result.cov_position, cov_position_intermediate);


    wrappers::Quaterniond orientation_intermediate;
    asn1SccWrappers_Quaterniond_fromAsn1(orientation_intermediate, asnVal.orientation);
    Base_Quaterniond_fromIntermediate(result.orientation, orientation_intermediate);


    wrappers::Matrix3d cov_orientation_intermediate;
    asn1SccWrappers_Matrix3d_fromAsn1(cov_orientation_intermediate, asnVal.cov_orientation);
    Base_Matrix3d_fromIntermediate(result.cov_orientation, cov_orientation_intermediate);


    wrappers::Vector3d velocity_intermediate;
    asn1SccWrappers_Vector3d_fromAsn1(velocity_intermediate, asnVal.velocity);
    Base_Vector3d_fromIntermediate(result.velocity, velocity_intermediate);


    wrappers::Matrix3d cov_velocity_intermediate;
    asn1SccWrappers_Matrix3d_fromAsn1(cov_velocity_intermediate, asnVal.cov_velocity);
    Base_Matrix3d_fromIntermediate(result.cov_velocity, cov_velocity_intermediate);


    wrappers::Vector3d angular_velocity_intermediate;
    asn1SccWrappers_Vector3d_fromAsn1(angular_velocity_intermediate, asnVal.angular_velocity);
    Base_Vector3d_fromIntermediate(result.angular_velocity, angular_velocity_intermediate);


    wrappers::Matrix3d cov_angular_velocity_intermediate;
    asn1SccWrappers_Matrix3d_fromAsn1(cov_angular_velocity_intermediate, asnVal.cov_angular_velocity);
    Base_Matrix3d_fromIntermediate(result.cov_angular_velocity, cov_angular_velocity_intermediate);

}

//Conversion functions from c++ type to asn1

void asn1SccBase_samples_RigidBodyState_toAsn1(asn1SccBase_samples_RigidBodyState& result, const base::samples::RigidBodyState& baseObj)
{
    asn1SccBase_Time_toAsn1(result.time, baseObj.time);

    asn1SccT_String_toAsn1(result.sourceframe, baseObj.sourceFrame);

    asn1SccT_String_toAsn1(result.targetframe, baseObj.targetFrame);


    wrappers::Vector3d position_intermediate;
    Base_Vector3d_toIntermediate(position_intermediate, baseObj.position);
    asn1SccWrappers_Vector3d_toAsn1(result.position, position_intermediate);


    wrappers::Matrix3d cov_position_intermediate;
    Base_Matrix3d_toIntermediate(cov_position_intermediate, baseObj.cov_position);
    asn1SccWrappers_Matrix3d_toAsn1(result.cov_position, cov_position_intermediate);


    wrappers::Quaterniond orientation_intermediate;
    Base_Quaterniond_toIntermediate(orientation_intermediate, baseObj.orientation);
    asn1SccWrappers_Quaterniond_toAsn1(result.orientation, orientation_intermediate);


    wrappers::Matrix3d cov_orientation_intermediate;
    Base_Matrix3d_toIntermediate(cov_orientation_intermediate, baseObj.cov_orientation);
    asn1SccWrappers_Matrix3d_toAsn1(result.cov_orientation, cov_orientation_intermediate);


    wrappers::Vector3d velocity_intermediate;
    Base_Vector3d_toIntermediate(velocity_intermediate, baseObj.velocity);
    asn1SccWrappers_Vector3d_toAsn1(result.velocity, velocity_intermediate);


    wrappers::Matrix3d cov_velocity_intermediate;
    Base_Matrix3d_toIntermediate(cov_velocity_intermediate, baseObj.cov_velocity);
    asn1SccWrappers_Matrix3d_toAsn1(result.cov_velocity, cov_velocity_intermediate);


    wrappers::Vector3d angular_velocity_intermediate;
    Base_Vector3d_toIntermediate(angular_velocity_intermediate, baseObj.angular_velocity);
    asn1SccWrappers_Vector3d_toAsn1(result.angular_velocity, angular_velocity_intermediate);


    wrappers::Matrix3d cov_angular_velocity_intermediate;
    Base_Matrix3d_toIntermediate(cov_angular_velocity_intermediate, baseObj.cov_angular_velocity);
    asn1SccWrappers_Matrix3d_toAsn1(result.cov_angular_velocity, cov_angular_velocity_intermediate);

}


