#include "impl.h"
#include <cstdio>
#include <cmath>
#include <cstdio>
bool Quadro(int a,int b,int c, double& x1,double& x2)
{
    return (((b*b - 4 * a * c) < 0)? false: (((b*b - 4 * a * c) == 0)?x1=x2=(-b/(2*a)), true: x1=(-b+sqrt(b*b - 4 * a * c))/(2*a), x2=(-b-sqrt(b*b - 4 * a * c))/(2*a),true));
}
