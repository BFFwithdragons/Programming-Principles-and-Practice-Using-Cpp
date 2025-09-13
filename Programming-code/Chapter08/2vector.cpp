/*

Write a function print() that prints a vector of ints to cout. Give it two 
arguments: a string for “labeling” the output and a vector.

*/

#include "std_lib_facilities.h"
void print(string label, const vector<int>& v);

namespace newcopy {
void reversevector(const vector<int>& v) {
    vector<int> n;
    for(int i = 0; n.size() != v.size(); i++) n.push_back(v[(v.size() - i) - 1]);
    print("Reverse w/ copy: ", n);
}
}


namespace nocopy {
    void reversevector(vector<int>& v) {
        for(int i = 0; i < floor(v.size() / 2); i++) {
            swap(v[i], v[v.size() - i - 1]);
        }
    }
}

void fibonacci (int x, int y, vector<int>& v, int n) {
    int currentvalue;
    while(v.size() < n) {
        v.push_back(x);
        if(v.size() == n) break;
        v.push_back(y);
        x = y + x;
        y = x + y;
    }
}

void print(string label, const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << label << v[i] << endl;
    }
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 8, 9};
    print("test: ", numbers);

    vector<int> fibonaccinumberes;
    fibonacci(6, 7, fibonaccinumberes, 5);
    print("Fibonacci: ", fibonaccinumberes);

    vector<int> reversalvector = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    newcopy::reversevector(reversalvector);

    vector<int> nocopyreversalvector = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    nocopy::reversevector(nocopyreversalvector);
    print("Reversed no copy: ", nocopyreversalvector);
}