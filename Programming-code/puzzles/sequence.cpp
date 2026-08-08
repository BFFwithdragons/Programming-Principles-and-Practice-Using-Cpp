#include "std_lib_facilities.h"

long long int fibonacci(long long int times) {
    long long int sum = 0;
    long long int k;
    long long int prev_one = 1;
    long long int prev_two = 1;
    while(k < times) {
        k = prev_one + prev_two;
        prev_one = prev_two;
        prev_two = k;
        if(k % 2 == 0) sum += k;
    }

    return sum;
}

int main() {
    cout << fibonacci(4000000);
}