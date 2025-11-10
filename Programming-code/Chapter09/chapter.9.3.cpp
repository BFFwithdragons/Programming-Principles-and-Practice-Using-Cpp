#include <iostream>
using namespace std;
//
// This is example code from Chapter 9.3 "Interface and implementation" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//--------------------------------s----------------------------------------------

class X {
    int m;
    int mf() { return m; }
public:
    int f(int i) { m=i; return mf(); }
};

//------------------------------------------------------------------------------

int main()
{
    X x;
    //int y = x.mf(); // error: mf is private (i.e., inaccessible)
    int y = x.f(2);
    cout << y << endl;
    return y;
}

//------------------------------------------------------------------------------
