#include <stdio.h>
#include <stdlib.h>
#include <cstring>
const int NMAX = 100;
int M[NMAX];
int N[NMAX];

/*==================================================
    Right-2-Left-Scan
 *==================================================*/
int R2LScan(char* S, int n) {
    return 0;
}

int ZTable(char *S, int n, int* Z) {
    int i = 1;
    int i0;
    int j2 = 0;
    int j1 = 0;
    int l = -1; 
    int r = -1;
    int lenbeta = 0;

    while ( i < n) {
        if (i >= r) {
            j2 = i;
            j1 = 0;
        
            while (S[j1] == S[j2] && j2 < n) { j1++; j2++;}

            if (j2 > i) {
                l = i;
                r = j2 - 1;
                Z[i] = j2 - i;
            }
            else {
                l = -1;
                r = -1;
                Z[i] = 0;
            }
        }
        else {
            lenbeta = r - i + 1;
            i0 = i - l + 1;

            if (Z[i0] < lenbeta) {
                Z[i] = lenbeta;
                // l,r unchanged
            }
            else {
                j2 = r + 1;
                j1 = (r - l) + 1;
            
                while (S[j1] == S[j2] && j2 < n) {
                    j1 ++;
                    j2 ++;
                }

                l = i;
                r = j2 - 1;
            }
        }
        i++;
    }
    return 0;
}

int test_ztable(char* S, int n, int* Z) {

    /*==================================================
        Test Every z [1..n-1] 
        (No test z[0])
     *==================================================*/
    for (int i=1; i<n;i++) {
        printf("%d;", Z[i]);
    }
    printf("\r\n");
    for (int i=1; i<n; ++i) {
        int j2 = i;
        int j1 = 0;
        while (j2 < n && S[j2] == S[j1]) { j2++; j1++; }

        if (Z[i] != j2 - i) {
            printf("invalid Z[%d]=%d != %d\r\n", i, Z[i], j2 - i);
        }
    }
    printf("finish %d\r\n", n);
    return 0;
}

/*==================================================
    S: String (Length=nS)
    P: Pattern (Length=nP)
 *==================================================*/

// iA: Aligned
// iS: String Index
// i:  Comparision
// Note: Zero-Index
//  Alignment: 
int phase(char* S, int nS, char* P, int nP, int i, int iA, int iS) {
    /*========================================
        Exp1. Does logical control flow cover every cases?
        
     *========================================*/
    if (M[iS] < 0 || M[iS] == N[i] == 0) {
        if (S[iS] == P[i] && i == 0) {
            // Occurences
        }
    }
    else if (M[iS] < N[i]) {
    }
    else if (M[iS] >= N[i]) {
    }
    else if (M[iS] > N[i] && N[i] < i) {
    }
    else if (M[iS] == N[i] && 0 < N[i] && N[i] <i) {
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    const char* S = "abcaabbacaabcaedebbba";
    int n = strlen(S);
    int* Z = (int*)malloc(sizeof(int)*n);

    ZTable((char*)S, n, Z);
    test_ztable((char*)S, n, Z);
    free(Z);
    return 0;
}