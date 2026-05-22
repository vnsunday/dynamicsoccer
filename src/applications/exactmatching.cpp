#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
const int NMAX = 100;
int M[NMAX];
int N[NMAX];

#define LOGTRACE 1

using namespace std;
/*==================================================
    CASES
 *==================================================*/
int load(const char* file_path, vector<string>& vectorline) {
    vectorline.clear();
    std::ifstream file1(file_path);                 
    if (file1.is_open())                            
    {                                               
        std::string line;                           
        while (std::getline(file1, line))           
        {                                           
            vectorline.push_back(line);             
        }                                           
        file1.close();                              
    }                                               
    return 0;
}

int analyze(const vector<string>& vline) {

    int l[1000];
    int r[1000];
    int Z[1000];
    string azMatch[1000];

    for (int i=0; i<vline.size(); i++) {
        int nl = vline[i].length();

        for (int j=1; j<nl; j++) {
            int k0 = -1;
            int k1 = j-1;

            while (k1 <= nl && vline[i][++k0] == vline[i][++k1]) {
            }
            Z[j] = k1 - j;

            azMatch[j] = vline[i].substr(j, Z[j]);
        }

        for (int j=1; j<nl; j++) {
            l[j] = -1;
            r[j] = -1;

            for (int k=1; k<=j; k++) {
                if (Z[k] > 0 && r[j] < k + Z[k] - 1) {
                    r[j] = k + Z[k] - 1;
                    l[j] = k;
                }
            }
        }

        /*==================================================*
            Report:
         *==================================================*/
        printf("String: %s\r\n", vline[i].c_str());
        for (int j=1; j<vline[i].length(); j++) {
            printf("    Z[%d]=%d (%s)\r\n", j, Z[j], azMatch[j].c_str());
            printf("        [L,R]=[%d,%d]; prefix=%s; S[%d]=%s\r\n", 
                                l[j], r[j],
                                vline[i].substr(0,3).c_str(),
                                j,
                                vline[i].substr(j,3).c_str());
        }
    }
    return 0;
}

/*==================================================
    Right-2-Left-Scan
 *==================================================*/
int R2LScan(char* S, int n) {
    // Right-2-Left 
    //    * The 1st found= the Right-most (max-index)
    // Left-2-Right 
    //    * The 1st found= the left most (minimum index)
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



    while ( i < n ) {
        if (i > r) {
            j2 = i;
            j1 = 0;

        
            /* Compare to the prefix */
            while (S[j1] == S[j2] && j2 < n) { j1++; j2++;}

            /* Found */
            if (j2 > i) {
                #ifdef LOGTRACE
                printf("    Step[%d](i>r=%d). Found l=%d;rnew=%d;Z=%d\r\n",
                        i, r, i, j2-1, j2-i);
                #endif

                l = i;
                r = j2 - 1;
                Z[i] = j2 - i;
            }
            else {
                #ifdef LOGTRACE
                printf("    Step[%d](i>r=%d). NotFound\r\n",
                        i, r);
                #endif                
                Z[i] = 0;
            }
        }
        else {
            lenbeta = r - i + 1;
            i0 = i - l;

            if (Z[i0] < lenbeta) {
                Z[i] = Z[i0];
                #ifdef LOGTRACE
                printf("    Step[%d] Z[%d]=%d<lenbeta=%d\r\n",
                        i, i0, Z[i0], lenbeta);
                #endif
                // l,r unchanged
            }
            else {
                #ifdef LOGTRACE
                printf("    Step[%d] Z[%d]=%d>=lenbeta=%d\r\n",
                        i, i0, Z[i0], lenbeta);
                #endif
                j2 = r + 1;
                j1 = lenbeta + 1; // (r - l) + 1;
            
                while (S[j1] == S[j2] && j2 < n) {
                    j1 ++;
                    j2 ++;
                }

                l = i;
                r = j2 - 1;
                Z[i] = (j2 - i);
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

int main(int argc, char const *argv[]) {

    vector<string> vline;
    load("exact.txt", vline);
    analyze(vline);

    const char* S = "abcaabbacaabcaedebbba";
    int n = strlen(S);
    int* Z = (int*)malloc(sizeof(int)*n);

    ZTable((char*)S, n, Z);
    test_ztable((char*)S, n, Z);
    free(Z);
    return 0;
}