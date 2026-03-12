#include <stdio.h>

using namespace std;

double percentage(double d1, double d2) {
    return d1/d2;
}

int main(int argc, char const *argv[])
{
    const int N = 100;
    double* pX;
    double* pY;

    pX = (double*)malloc(sizeof(double)*N);
    pY = (double*)malloc(sizeof(double)*N);

    int iS = 12; // (random)
    int iE = 35; 

    double dtravel = 0.0; // pY[iJ] - pY[iI];

    for (int i=iS+1; i<=iE; ++i) {
        dtravel += abs(pY[i] - pY[i-1])
    }

    free(pX);
    free(pY);
    return 0;
}