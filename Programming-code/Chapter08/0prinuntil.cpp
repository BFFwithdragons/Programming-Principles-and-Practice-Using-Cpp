//
// This is example code from Chapter 8.5.2 "Returning a value" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef int T;
typedef double V;

T f()                  // f() returns a T
{
    V v;
    // ...
    return v;
}

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

double my_abs(int x)    // warning: buggy code
{
    if (x < 0)
        return -x;
    else if (x> 0)
        return x;
    else
        return x;
}    // error: no value returned if x is 0

void print_until_s(const vector<string> v, const string quit)
{
    for(int i=0; i<v.size(); ++i) {
        if (v[i]==quit) {
            cout << v[i] << " ";
            return;
        }
        cout << v[i] << ' ';
    }
}

void print_until_ss(const vector<string> v, const string quit) {
    int detected = 0;
    for (int i = 0; i < v.size(); i++) {
        if (detected < 2) {
            if (v[i] == quit) {
                detected++;
                cout << v[i] << " ";
            } else {
                cout << v[i] << " ";
            }
        } else if (detected >= 2) {
            return;
        }
    }
}

//------------------------------------------------------------------------------

int main()
{
    T x = f();
    V v;
    // ...
    T t(v);             // initialize t with v-
    //int x(3);
    
    // PRINT UNTIL S
    cout << "trial 1: ";
    vector<string> v1 = {"hi", "d", "s", "quit", "e"};
    print_until_s(v1, "s");
    cout << "\ntrial 2: ";
    vector<string> v2 = {"hi", "d", "quit", "e"};
    print_until_s(v2, "a");
    cout << "\ntrial 3: ";
    vector<string> v3 = {"hi", "d", "quit", "e", "b"};
    print_until_s(v3, "b");
    
    // PRINT UNTIL SS
    cout << "\n\ntrial 1: ";
    vector<string> v4 = {"hi", "d", "s", "quit", "e", "s"};
    print_until_ss(v4, "s");
    cout << "\ntrial 2: ";
    vector<string> v5 = {"hi", "s", "s", "quit", "e", "s"};
    print_until_ss(v5, "s");
    cout << "\ntrial 3: ";
    vector<string> v6 = {"hi", "s", "a", "quit", "e", "b"};
    print_until_ss(v6, "s");
    cout << "\ntrial 4: ";
    vector<string> v7 = {"hi", "e", "a", "quit", "e", "b"};
    print_until_ss(v7, "s");
}
