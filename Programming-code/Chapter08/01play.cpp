
//
// This is example code from Chapter 8.2 "Declarations and definitions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"     // we find the declaration of cout in here
#include "0helper.h"
//------------------------------------------------------------------------------


void swap(int& a, int& b);

int main()
{
  int a = 8;
  int b = 7;
  myswap(a, b);
 cout << "a: " << a << " b: " << b << endl;
}



//------------------------------------------------------------------------------

