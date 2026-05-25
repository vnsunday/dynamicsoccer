#include <stdlib.h>
#include <conio.h>
#include <cmath>

int two_dices_tossing(int n) {
    // Ex3.9 Book 
    int expecting_event; // 1+1 = (2)

    // Combination 
    // 
    int a1, a2, a3, a4, a5, a6;
    int b1, b2, b3, b4, b5, b6;

    // Easier approach: 

    int Event_A; 
    int C_Event_A; // Complement of A 

    double d1_C_Event_A = 35/36;
    return 1 - std::pow(d1_C_Event_A, n);
}

int main(int argc, char const *argv[])
{
    int n = 2;
    two_dices_tossing(n);
    return 0;
}