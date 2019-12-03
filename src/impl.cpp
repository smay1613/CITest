#include "impl.h"
#include <cmath>


//bool Quadro(int a,int b,int c, double& x1,double& x2)
//{
//    x1 = (-b + (sqrt(static_cast<double>(b*b - 4*a*c))))/(2*a);
//    x2 = (-b - (sqrt(static_cast<double>(b*b - 4*a*c))))/(2*a);
//    return !std::isnan(sqrt(static_cast<double>(b*b - 4*a*c)));
//}

bool Quadro(int a,int b,int c, double& x1,double& x2)
{
    return x1 = (-b + (sqrt(static_cast<double>(b*b - 4*a*c))))/(2*a),
    x2 = (-b - (sqrt(static_cast<double>(b*b - 4*a*c))))/(2*a),
     !std::isnan(sqrt(static_cast<double>(b*b - 4*a*c)));
}
