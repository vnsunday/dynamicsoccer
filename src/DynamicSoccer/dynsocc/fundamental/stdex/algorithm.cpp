#include <stdio.h>
#include <stdlib.h>
#include "algorithm.hpp"

using namespace dynsocc;

template<typename T>
int dynsocc::algorithm::equality_score(T* parr1, int n1, T* parr2, int n2) {

    int i, j;
    return 0;
}

template<typename T>
int dynsocc::algorithm::remove_element(T* parr, int nBegin, int &nEnd, int removeIndex) {
    if (removeIndex >= nBegin && removeIndex < nEnd)
    {
        for (int i=removeIndex;i<nEnd-1;++i)
        {
            parr[i]=parr[i+1];
        }
        nEnd--;
        return 0;
    }
    return 1;
}

template<typename T>
int dynsocc::algorithm::remove_element(T* parr, T* parr2, int nBegin, int& nEnd, int removeIndex) {
    if (removeIndex >= nBegin && removeIndex < nEnd) {
        for (int i = removeIndex; i < nEnd - 1; ++i) {
            parr[i] = parr[i + 1];
            parr2[i] = parr2[i + 1];
        }
        nEnd--;
        return EXOK;
    }
    return 1;
}

template<typename T>
static int remove_elements(T* parr, int nBegin, int &nEnd, int* premove_indexes, int nRemoveStart, int nRemoveEnd)
{
    // Validate 
    for (int i=nRemoveStart;i<nRemoveEnd;++i) {
        if (prm_indexes[i] < nBegin || prm_indexes[i] >= nEnd)
        {
            // Invalid data
            return 1;
        }
    }

    int nRemove = nRemoveEnd - nRemoveStart;
    int* premove = (int*)malloc(sizeof(int)*nRemove);

    memcpy(premove, prm_indexes + nRemoveStart, nRemove*sizeof(int));
    std::sort(premove, premove+nRemove);

    // Remove from largest position first, then go on.
    for (int i=nRemove-1;i>=0;i--)
    {
        for (int j=premove[i];j<nEnd;j++)
        {
            parr[j] = parr[j+1];
        }
        nEnd--;
    }

    return 0;
}

template<typename T>
int dynsocc::algorithm::remove_elements(T* parr, T* parr2, int nBegin, int& nEnd, int startIndex, int endIndex)
{
    return EXOK;
}