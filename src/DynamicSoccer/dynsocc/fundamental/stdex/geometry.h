#ifndef DYNSOCC_FUNDAMENTAL_STDEX_GEOMETRY_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_GEOMETRY_H_

#include "rect.h"

namespace dynsocc
{

    class GeometryUtil
    {
        public:
            static bool intersect(Rectangle rc1, Rectangle rc2, Rectangle& rc);

            static bool intersect(Rectangle rc1, Rectangle rc2);

    };

}

#endif