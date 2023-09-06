#ifndef DYNSOCC_FUNDAMENTAL_STDEX_ALGORITHM_HPP_
#define DYNSOCC_FUNDAMENTAL_STDEX_ALGORITHM_HPP_
#include <assert.h>

namespace dynsocc
{
    class algorithm
    {
    public: 
        template <typename T>
        static int binary_search(T* arr_sorted_asc, int nBegin, int nEnd, T val, int& nFound)
        {
            int nL = nBegin;
            int nR = nEnd-1;
            int nMid;
            nFound = -1;
            T valMid;
            while (nL <= nR && (nFound < 0))
            {
                nMid = (nL + nR) / 2;
                valMid = arr_sorted_asc[nMid];

                if (valMid == val)
                {
                    nFound = nMid;
                }
                else if (valMid < val)
                {
                    nL = nMid + 1;
                }
                else 
                {
                    nR = nMid - 1;
                }
            }

            return 0;
        }

        template <typename T>
        static int binary_search(T* arr_sorted_asc, int nBegin, int nEnd, T val, int& nFoundBegin, int& nFoundEnd)
        {
            // Find every 
            int nL = nBegin;
            int nR = nEnd-1;
            int nMid = (nL + nR) / 2;
            int nFound = -1;
            nFoundBegin = -1;
            nFoundEnd = nFoundBegin -1;
            T valMid;

            // The 1st location 
            while (nL <= nR && (nFound < 0))
            {
                nMid = (nL + nR) / 2;
                valMid = arr_sorted_asc[nMid];

                if (valMid == val)
                {
                    nFound = nMid;
                }
                else if (valMid < val)
                {
                    nL = nMid + 1;
                }
                else 
                {
                    nR = nMid - 1;
                }
            }

            if (nFound >=0)
            {
                nFoundBegin = nFound;
                nFoundEnd = nFound;


                while (nFoundBegin > nBegin && arr_sorted_asc[nFoundBegin-1] == val)  { nFoundBegin--;}
                while (nFoundEnd < nEnd-1 && arr_sorted_asc[nFoundEnd+1] == val ) { nFoundEnd++;}
            }
            
            return 0;
        }

        
        template<typename T>
        static int insert_into_sorted_asc(T* parr, int nBegin, int &nEnd, T val, int& nPos)
        {
            // Pre-Requisite: parr is sorted asc (every i: p[i] <= p[i+1])
            // This function does not validate pre-requisite condition 
           
            // Find the 1st position (smallest) where 
            //      parr[pos] < val
            nPos = 0;
            while (nPos < nEnd && parr[nPos] >= val) { nPos++; }

            // Starting from nPos+1, move everything forward
            for (int i=nEnd; i> nPos;i--)
            {
                parr[i] = parr[i-1];
            }

            // Insert at nPos
            parr[nPos] = val;
            nEnd++;
            return 0;
        }

        template<typename T>
        static int insert_into_sorted_desc(T* parr, int nBegin, int &nEnd, T val, int& nPos)
        {
            // Pre-requisite: parr is sorted desc (p[i] >= p[i+1], every i)
            // If the pre-requisite condition is not meet => the result will incorrect, 
            // This function does not validate pre-requisite condition.

            // Find the 1st position where val >= p[loc]
            nPos = nBegin;

            while (nPos < nEnd && (val < parr[nPos]))
            {
                nPos++;
            }

            // Starting from nPos+1, move everything forward 1step
            for (int i=nEnd;i>nPos;i--)
            {
                parr[i] = parr[i-1];
            }

            // Insert 
            parr[nPos] = val;
            nEnd++;
            return 0;
        }

        template<typename T>
        static int remove_element(T* parr, int nBegin, int &nEnd, int removeIndex)
        {
            if (removeIndex >= nBegin && removeIndex < nEnd)
            {
                for (int i=removeIndex;i<nEnd-1;++1)
                {
                    parr[i]=parr[i+1];
                }
                nEnd--;
                return 0;
            }
            return 1;
        }

        template<typename T>
        static int remove_element(T* parr, T* parr2, int nBegin, int& nEnd, int removeIndex)
        {
            if (removeIndex >= nBegin && removeIndex < nEnd)
            {
                for (int i=removeIndex;i<nEnd-1;++i)
                {
                    parr[i]=parr[i+1];
                    parr2[i] = parr2[i+1];
                }

                nEnd--;
                return 0;
            }
            return 1;
        }
        
        template<typename T>
        static int remove_elements(T* parr, int nBegin, int &nEnd, int* prm_indexes, int nRemoveStart, int nRemoveEnd)
        {
            // Validate 
            for (int i=nRemoveStart;i<nRemoveEnd;++i)
            {
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
        static int remove_elements(T* parr, T* parr2, int nBegin, int &nEnd, int* prm_indexes, int nRemoveStart, int nRemoveEnd)
        {
            // Validate 
            for (int i = nRemoveStart; i < nRemoveEnd; ++i)
            {
                if (prm_indexes[i] < nBegin || prm_indexes[i] >= nEnd)
                {
                    // Invalid data
                    return 1;
                }
            }

            int nRemove = nRemoveEnd - nRemoveStart;
            int* premove = (int*)malloc(sizeof(int)*nRemove);

            memcpy(premove, prm_indexes + nRemoveStart, nRemove * sizeof(int));
            std::sort(premove, premove + nRemove);

            // Remove from largest position first, then go on.
            for (int i = nRemove - 1; i >= 0; i--)
            {
                for (int j = premove[i]; j < nEnd; j++)
                {
                    parr[j] = parr[j + 1];
                    parr2[j] = parr2[j + 1];
                }

                nEnd--;
            }

            return 0;
        }
    
		template<typename T>
		static int find_location_in_sorted_order(T* parr, int nBegin, int nEnd, T val, int& nPos)
		{
			// Pre-Requisite: parr is sorted asc (every i: p[i] <= p[i+1])
			// This function does not validate pre-requisite condition 

			// Find the 1st position (smallest) where 
			//      parr[pos] < val
			nPos = 0;
			while (nPos < nEnd && parr[nPos] >= val) { nPos++; }
			return 0;
		}

		template<typename T>
		static int insert(T* parr, int nBegin, int& nEnd, T val, int nPos)
		{
			assert(nPos < nEnd && nPos >= 0);

			// Starting from nPos+1, move everything forward
			for (int i = nEnd; i > nPos; i--)
			{
				parr[i] = parr[i - 1];
			}

			// Insert at nPos
			parr[nPos] = val;
			nEnd++;
			return 0;
		}
	};

}


#endif 