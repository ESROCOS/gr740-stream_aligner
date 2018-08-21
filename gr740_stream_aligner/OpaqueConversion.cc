
#include "OpaqueConversion.hpp"
//#include "Wrappers-Vector2dConvert.hpp"
#include "Wrappers-Vector3dConvert.hpp"
//#include "Wrappers-Vector4dConvert.hpp"
//#include "Wrappers-Vector6dConvert.hpp"
//#include "Wrappers-VectorXdConvert.hpp"
//#include "Wrappers-Matrix2dConvert.hpp"
#include "Wrappers-Matrix3dConvert.hpp"
//#include "Wrappers-Matrix4dConvert.hpp"
//#include "Wrappers-Matrix6dConvert.hpp"
//#include "Wrappers-MatrixXdConvert.hpp"
#include "Wrappers-QuaterniondConvert.hpp"
//#include "Wrappers-AngleAxisdConvert.hpp"


//Conversion functions from the instanced type to the marshaled type


//void Base_Vector6d_fromIntermediate(base::Vector6d& result, const wrappers::Vector6d& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    for(int i= 0; i < 6; i++)
//    {
//        result[i] = cppMarshall.data[i];
//    }
//    
//}
//
//void Base_Vector6d_toIntermediate(wrappers::Vector6d& result, const base::Vector6d& cppval)
//{
//    /*Add user code for this conversion*/
//    for(int i= 0; i < 6; i++)
//    {
//         result.data[i] = cppval[i];
//    }
//    
//}
//
//void Base_Affine3d_fromIntermediate(base::Affine3d& result, const wrappers::Matrix4d& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    //linear(3x3) T(3x1)
//    //0 0 0          1
//   Base_Matrix4d_fromIntermediate(result.matrix(),cppMarshall);
//    result.makeAffine();
//    
//    
//    
//}
//
//void Base_Affine3d_toIntermediate(wrappers::Matrix4d& result, const base::Affine3d& cppval)
//{
//    /*Add user code for this conversion*/
//    Base_Matrix4d_toIntermediate(result,cppval.matrix());
//    
//    
//}
//
//void Base_Matrix4d_fromIntermediate(base::Matrix4d& result, const wrappers::Matrix4d& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    for(int i = 0; i < 4; i++)
//    {
//        for(int j=0; j < 4; j++)
//        {
//            result(i,j)=cppMarshall.data[j*4+i];
//        }
//    }
//    
//}
//
//void Base_Matrix4d_toIntermediate(wrappers::Matrix4d& result, const base::Matrix4d& cppval)
//{
//    /*Add user code for this conversion*/
//    for(int i = 0; i < 4; i++)
//    {
//        for(int j=0; j < 4; j++)
//        {
//            result.data[j*4+i] = cppval(i,j);
//        }
//    }
//}


void Base_Vector3d_fromIntermediate(base::Vector3d& result, const wrappers::Vector3d& cppMarshall)
{
    /*Add user code for this conversion*/
    for(int i= 0; i < 3; i++)
    {
        result[i] = cppMarshall.data[i];
    }
}

void Base_Vector3d_toIntermediate(wrappers::Vector3d& result, const base::Vector3d& cppval)
{
    /*Add user code for this conversion*/
    for(int i= 0; i < 3; i++)
    {
         result.data[i] = cppval[i];
    }
}


//void Base_VectorXd_fromIntermediate(base::VectorXd& result, const wrappers::VectorXd& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    for(int i= 0; cppMarshall.data.size(); i++)
//    {
//        result[i] = cppMarshall.data[i];
//    }
//    
//}
//
//void Base_VectorXd_toIntermediate(wrappers::VectorXd& result, const base::VectorXd& cppval)
//{
//    /*Add user code for this conversion*/
//    for(int i= 0; i < cppval.size(); i++)
//    {
//         result.data[i] = cppval[i];
//    }
//}
//
//
//void Base_MatrixXd_fromIntermediate(base::MatrixXd& result, const wrappers::MatrixXd& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    for(int i = 0; i < cppMarshall.rows; i++)
//    {
//        for(int j=0; j < cppMarshall.cols; j++)
//        {
//            result(i,j)=cppMarshall.data[j*4+i];
//        }
//    }
//    
//}
//
//void Base_MatrixXd_toIntermediate(wrappers::MatrixXd& result, const base::MatrixXd& cppval)
//{
//    /*Add user code for this conversion*/
//    for(int i = 0; i < cppval.rows(); i++)
//    {
//        for(int j=0; j < cppval.cols(); j++)
//        {
//            result.data[j*4+i] = cppval(i,j);
//        }
//    }
//}
//
//
//void Base_AngleAxisd_fromIntermediate(base::AngleAxisd& result, const wrappers::AngleAxisd& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    result.angle() = cppMarshall.angle;
//    for(int i= 0; i < 3; i++)
//    {
//        result.axis()[i] = cppMarshall.axis[i];
//    }
//    
//    
//}
//
//void Base_AngleAxisd_toIntermediate(wrappers::AngleAxisd& result, const base::AngleAxisd& cppval)
//{
//    /*Add user code for this conversion*/
//    result.angle = cppval.angle();
//    for(int i= 0; i < 3; i++)
//    {
//        result.axis[i] = cppval.axis()[i];
//    }
//    
//}


void Base_Quaterniond_fromIntermediate(base::Quaterniond& result, const wrappers::Quaterniond& cppMarshall)
{
    /*Add user code for this conversion*/
    result.w() = cppMarshall.re;
    result.x()=cppMarshall.im[0];
    result.y()=cppMarshall.im[1];
    result.z()=cppMarshall.im[2];
}

void Base_Quaterniond_toIntermediate(wrappers::Quaterniond& result, const base::Quaterniond& cppval)
{
    /*Add user code for this conversion*/
    result.re = cppval.w();
    result.im[0] = cppval.x();
    result.im[1] = cppval.y();
    result.im[2] = cppval.z();
}


//void Base_Matrix2d_fromIntermediate(base::Matrix2d& result, const wrappers::Matrix2d& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    for(int i = 0; i < 2; i++)
//    {
//        for(int j=0; j < 2; j++)
//        {
//            result(i,j)=cppMarshall.data[j*4+i];
//        }
//    }
//}
//
//void Base_Matrix2d_toIntermediate(wrappers::Matrix2d& result, const base::Matrix2d& cppval)
//{
//    /*Add user code for this conversion*/
//    for(int i = 0; i < 2; i++)
//    {
//        for(int j=0; j < 2; j++)
//        {
//            result.data[j*2+i] = cppval(i,j);
//        }
//    }
//}


void Base_Matrix3d_fromIntermediate(base::Matrix3d& result, const wrappers::Matrix3d& cppMarshall)
{
    /*Add user code for this conversion*/
    for(int i = 0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            result(i,j)=cppMarshall.data[j*4+i];
        }
    }
}

void Base_Matrix3d_toIntermediate(wrappers::Matrix3d& result, const base::Matrix3d& cppval)
{
    /*Add user code for this conversion*/
    for(int i = 0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            result.data[j*3+i] = cppval(i,j);
        }
    }
}


//void Base_Matrix6d_fromIntermediate(base::Matrix6d& result, const wrappers::Matrix6d& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    for(int i = 0; i < 6; i++)
//    {
//        for(int j=0; j < 6; j++)
//        {
//            result(i,j)=cppMarshall.data[j*4+i];
//        }
//    }
//}
//
//void Base_Matrix6d_toIntermediate(wrappers::Matrix6d& result, const base::Matrix6d& cppval)
//{
//    /*Add user code for this conversion*/
//    for(int i = 0; i < 6; i++)
//    {
//        for(int j=0; j < 6; j++)
//        {
//            result.data[j*6+i] = cppval(i,j);
//        }
//    }
//}


//void Base_Vector2d_fromIntermediate(base::Vector2d& result, const wrappers::Vector2d& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    for(int i= 0; i < 2; i++)
//    {
//        result[i] = cppMarshall.data[i];
//    }
//}
//
//void Base_Vector2d_toIntermediate(wrappers::Vector2d& result, const base::Vector2d& cppval)
//{
//    /*Add user code for this conversion*/
//    for(int i= 0; i < 2; i++)
//    {
//         result.data[i] = cppval[i];
//    }
//}
//
//
//void Base_Vector4d_fromIntermediate(base::Vector4d& result, const wrappers::Vector4d& cppMarshall)
//{
//    /*Add user code for this conversion*/
//    for(int i= 0; i < 4; i++)
//    {
//        result[i] = cppMarshall.data[i];
//    }
//}
//
//void Base_Vector4d_toIntermediate(wrappers::Vector4d& result, const base::Vector4d& cppval)
//{
//    /*Add user code for this conversion*/
//    for(int i= 0; i < 4; i++)
//    {
//         result.data[i] = cppval[i];
//    }
//}

// Fully manually coded functions

//void asn1Scc_Vector2d_fromAsn1(base::Vector2d& result, const asn1SccWrappers_Vector2d& asnVal)
//{
//    wrappers::Vector2d intermediate;
//    asn1SccWrappers_Vector2d_fromAsn1(intermediate, asnVal);
//    Base_Vector2d_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_Vector2d_toAsn1(asn1SccWrappers_Vector2d& result, const base::Vector2d& baseObj)
//{
//    wrappers::Vector2d intermediate;
//    Base_Vector2d_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_Vector2d_toAsn1(result, intermediate);
//}

void asn1Scc_Vector3d_fromAsn1(base::Vector3d& result, const asn1SccWrappers_Vector3d& asnVal)
{
    wrappers::Vector3d intermediate;
    asn1SccWrappers_Vector3d_fromAsn1(intermediate, asnVal);
    Base_Vector3d_fromIntermediate(result, intermediate);
}

void asn1Scc_Vector3d_toAsn1(asn1SccWrappers_Vector3d& result, const base::Vector3d& baseObj)
{
    wrappers::Vector3d intermediate;
    Base_Vector3d_toIntermediate(intermediate, baseObj);
    asn1SccWrappers_Vector3d_toAsn1(result, intermediate);
}

//void asn1Scc_Vector4d_fromAsn1(base::Vector4d& result, const asn1SccWrappers_Vector4d& asnVal)
//{
//    wrappers::Vector4d intermediate;
//    asn1SccWrappers_Vector4d_fromAsn1(intermediate, asnVal);
//    Base_Vector4d_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_Vector4d_toAsn1(asn1SccWrappers_Vector4d& result, const base::Vector4d& baseObj)
//{
//    wrappers::Vector4d intermediate;
//    Base_Vector4d_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_Vector4d_toAsn1(result, intermediate);
//}
//
//void asn1Scc_Vector6d_fromAsn1(base::Vector6d& result, const asn1SccWrappers_Vector6d& asnVal)
//{
//    wrappers::Vector6d intermediate;
//    asn1SccWrappers_Vector6d_fromAsn1(intermediate, asnVal);
//    Base_Vector6d_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_Vector6d_toAsn1(asn1SccWrappers_Vector6d& result, const base::Vector6d& baseObj)
//{
//    wrappers::Vector6d intermediate;
//    Base_Vector6d_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_Vector6d_toAsn1(result, intermediate);
//}
//
//void asn1Scc_VectorXd_fromAsn1(base::VectorXd& result, const asn1SccWrappers_VectorXd& asnVal)
//{
//    wrappers::VectorXd intermediate;
//    asn1SccWrappers_VectorXd_fromAsn1(intermediate, asnVal);
//    Base_VectorXd_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_VectorXd_toAsn1(asn1SccWrappers_VectorXd& result, const base::VectorXd& baseObj)
//{
//    wrappers::VectorXd intermediate;
//    Base_VectorXd_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_VectorXd_toAsn1(result, intermediate);
//}
//
//void asn1Scc_Matrix2d_fromAsn1(base::Matrix2d& result, const asn1SccWrappers_Matrix2d& asnVal)
//{
//    wrappers::Matrix2d intermediate;
//    asn1SccWrappers_Matrix2d_fromAsn1(intermediate, asnVal);
//    Base_Matrix2d_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_Matrix2d_toAsn1(asn1SccWrappers_Matrix2d& result, const base::Matrix2d& baseObj)
//{
//    wrappers::Matrix2d intermediate;
//    Base_Matrix2d_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_Matrix2d_toAsn1(result, intermediate);
//}

void asn1Scc_Matrix3d_fromAsn1(base::Matrix3d& result, const asn1SccWrappers_Matrix3d& asnVal)
{
    wrappers::Matrix3d intermediate;
    asn1SccWrappers_Matrix3d_fromAsn1(intermediate, asnVal);
    Base_Matrix3d_fromIntermediate(result, intermediate);
}

void asn1Scc_Matrix3d_toAsn1(asn1SccWrappers_Matrix3d& result, const base::Matrix3d& baseObj)
{
    wrappers::Matrix3d intermediate;
    Base_Matrix3d_toIntermediate(intermediate, baseObj);
    asn1SccWrappers_Matrix3d_toAsn1(result, intermediate);
}

//void asn1Scc_Matrix4d_fromAsn1(base::Matrix4d& result, const asn1SccWrappers_Matrix4d& asnVal)
//{
//    wrappers::Matrix4d intermediate;
//    asn1SccWrappers_Matrix4d_fromAsn1(intermediate, asnVal);
//    Base_Matrix4d_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_Matrix4d_toAsn1(asn1SccWrappers_Matrix4d& result, const base::Matrix4d& baseObj)
//{
//    wrappers::Matrix4d intermediate;
//    Base_Matrix4d_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_Matrix4d_toAsn1(result, intermediate);
//}
//
//void asn1Scc_Matrix6d_fromAsn1(base::Matrix6d& result, const asn1SccWrappers_Matrix6d& asnVal)
//{
//    wrappers::Matrix6d intermediate;
//    asn1SccWrappers_Matrix6d_fromAsn1(intermediate, asnVal);
//    Base_Matrix6d_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_Matrix6d_toAsn1(asn1SccWrappers_Matrix6d& result, const base::Matrix6d& baseObj)
//{
//    wrappers::Matrix6d intermediate;
//    Base_Matrix6d_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_Matrix6d_toAsn1(result, intermediate);
//}
//
//void asn1Scc_MatrixXd_fromAsn1(base::MatrixXd& result, const asn1SccWrappers_MatrixXd& asnVal)
//{
//    wrappers::MatrixXd intermediate;
//    asn1SccWrappers_MatrixXd_fromAsn1(intermediate, asnVal);
//    Base_MatrixXd_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_MatrixXd_toAsn1(asn1SccWrappers_MatrixXd& result, const base::MatrixXd& baseObj)
//{
//    wrappers::MatrixXd intermediate;
//    Base_MatrixXd_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_MatrixXd_toAsn1(result, intermediate);
//}

void asn1Scc_Quaterniond_fromAsn1(base::Quaterniond& result, const asn1SccWrappers_Quaterniond& asnVal)
{
    wrappers::Quaterniond intermediate;
    asn1SccWrappers_Quaterniond_fromAsn1(intermediate, asnVal);
    Base_Quaterniond_fromIntermediate(result, intermediate);
}

void asn1Scc_Quaterniond_toAsn1(asn1SccWrappers_Quaterniond& result, const base::Quaterniond& baseObj)
{
    wrappers::Quaterniond intermediate;
    Base_Quaterniond_toIntermediate(intermediate, baseObj);
    asn1SccWrappers_Quaterniond_toAsn1(result, intermediate);
}

//void asn1Scc_AngleAxisd_fromAsn1(base::AngleAxisd& result, const asn1SccWrappers_AngleAxisd& asnVal)
//{
//    wrappers::AngleAxisd intermediate;
//    asn1SccWrappers_AngleAxisd_fromAsn1(intermediate, asnVal);
//    Base_AngleAxisd_fromIntermediate(result, intermediate);
//}
//
//void asn1Scc_AngleAxisd_toAsn1(asn1SccWrappers_AngleAxisd& result, const base::AngleAxisd& baseObj)
//{
//    wrappers::AngleAxisd intermediate;
//    Base_AngleAxisd_toIntermediate(intermediate, baseObj);
//    asn1SccWrappers_AngleAxisd_toAsn1(result, intermediate);
//}


