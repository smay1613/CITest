#include "impl.h"

bool Quadro (int a, int b, int c, double& x1, double& x2)
{
    return ((x1 = (-b+sqrt(b*b-4*a*c))/2/a) && (x2 = (-b-sqrt(b*b-4*a*c))/2/a));
}
