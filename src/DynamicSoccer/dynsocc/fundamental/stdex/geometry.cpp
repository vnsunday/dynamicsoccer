#include "geometry.h"

using namespace dynsocc;

bool GeometryUtil::intersect(Rectangle rc1, Rectangle rc2, Rectangle& rc)
{
    if (intersect(rc1,rc2))
    {
        // rc.x = std::max()

        return true;
    }
    return false;
}

bool GeometryUtil::intersect(Rectangle rc1, Rectangle rc2)
{
    return  (rc1.x + rc1.w >= rc2.x && 
                    rc2.x + rc2.w >= rc1.x &&
                    rc2.y + rc2.h >= rc1.y && 
                    rc1.y + rc1.h >= rc2.y);
}