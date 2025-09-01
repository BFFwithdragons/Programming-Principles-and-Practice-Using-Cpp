#include "std_lib_facilities.h"

namespace x {
    int var = 1;
    void print() {
        cout << "x = " << var << endl;
    }
}


namespace y {
    int var = 2;
    void print() {
        cout << "y = " << var << endl;
    }
}

namespace z  {
    int var = 3;
    void print() {
        cout << "z = " << var << endl;
    }
}

int main() {
    x::print();
    y::print();
    z::print();
}