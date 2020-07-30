#ifndef DYNSOCC_FUNDAMENTAL_STDEX_RECT_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_RECT_H_

namespace dynsocc
{
    struct Rectangle
    {
        int x;
        int y;
        int w;
        int h;

        Rectangle(int x1,int y1, int w1, int h1);       
    };
}

#endif // !