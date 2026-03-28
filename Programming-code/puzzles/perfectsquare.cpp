#include "std_lib_facilities.h"
long long int add_perfect_squares(long long int times);

int main () {
    cout << add_perfect_squares(391000);
}


long long int add_perfect_squares(long long int times) {
    long long int k = 0;
    long long int total = 0;
    for(int i = 0; i < times; ++i) {
        k += (i * 2 + 1);
        if(k % 2 == 1) total += k;
    }

    return total;
}