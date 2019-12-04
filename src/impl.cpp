#include "impl.h"
#include <cmath>

bool Quadro(int a,int b,int c, double& x1,double& x2)
{
    return  b*b - 4*a*c >= 0
            ? ((x1 = (-b + std::sqrt(b*b - 4*a*c)) / (2*a)), (x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a))), true
            : false;
}
