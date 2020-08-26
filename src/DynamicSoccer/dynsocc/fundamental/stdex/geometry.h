#ifndef DYNSOCC_FUNDAMENTAL_STDEX_GEOMETRY_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_GEOMETRY_H_

#include "stdex.h"
#include "rect.h"

namespace dynsocc
{

    class GeometryUtil
    {
        public:
            static bool intersect(Rectangle rc1, Rectangle rc2, Rectangle& rc);

            static bool intersect(Rectangle rc1, Rectangle rc2);

            static Rectangle move(Rectangle rc, int offsetX, int offsetY);
    };

}

#endif