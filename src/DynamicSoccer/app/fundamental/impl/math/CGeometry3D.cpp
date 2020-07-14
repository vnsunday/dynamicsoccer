#include "CGeometry3D.h"
#include <opencv2/core.hpp>

using namespace cv;

CGeometry3D::CGeometry3D(/* args */)
{
}

CGeometry3D::~CGeometry3D()
{
}

int CGeometry3D::projectPointIntoPlane(cv::Vec3d p,
                                    cv::Vec3d O,
                                    cv::Vec3d v1,
                                    cv::Vec3d v2,
                                    cv::Vec3d& pout)
{
    // Normal vector of two planes
    Vec3d vN =  v1.cross(v2);   // Normal 

    Mat mA = (Mat_<double>(3,3) << 
                v1[0], v1[1], v1[2],
                v2[0], v2[1], v2[2],
                vN[0], vN[1], vN[2]);
    Mat mB = (Mat_<double>(3,1) <<
                p[0]*v1[0] + p[1]*v1[1] + p[2]*v1[2],
                p[0]*v2[0] + p[1]*v2[1] + p[2]*v2[2],
                O[0]*vN[0] + O[1]*vN[1] + O[2]*vN[2]);
    Mat mA_inv = mA.inv();
    Mat X = mA_inv * mB;

    // pout[0] = X.at<double>(0,0);
    // pout[1] = X.at<double>(1,0);
    // pout[2] = X.at<double>(2,0);
    pout = Vec3d(X.reshape(3).at<cv::Vec3d>());
    return 0;
}