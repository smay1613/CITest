#include <Ship.h>

Ship::Ship(int x,int y)
{
    _coord.x = x;
    _coord.y = y;
    setStatus(true);
}

Ship::~Ship()
{
}

bool Ship::getStatus()
{
    return _status;
}

bool Ship::fire(int x,int y)
{
    if ((_coord.x == x) && (_coord.y == y))
    {
        _status = false;
        return true;
    }
    else
    {
        return false;
    }
}

void Ship::setStatus(bool value)
{
    _status = value;
}

Point Ship::getPoint()
{
    return Point();
}
