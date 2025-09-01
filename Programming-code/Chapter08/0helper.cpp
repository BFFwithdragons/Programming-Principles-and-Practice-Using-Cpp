#include "0helper.h"

void myswap(int& a, int& b) {
    int prev_a = a;
    a = b;
    b = prev_a;
}