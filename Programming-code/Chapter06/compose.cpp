#include "std_lib_facilities.h"

void convertint(int number);

int main() {
    int input;
    cin >> input;
    convertint(input);
    return 1;
}

void convertint(int number) {
    vector<int> individalval;
    for(int i = 1000; i >= 1; i /= 10) {
    individalval.push_back(number /  i);
    number %= i;
    }

    cout << individalval[0];
    cout << " thousands" << endl;
    cout << individalval[1];
    cout << " hundreds" << endl;
    cout << individalval[2];
    cout << " tens" << endl;
    cout << individalval[3];
    cout << " ones" << endl;
    
}