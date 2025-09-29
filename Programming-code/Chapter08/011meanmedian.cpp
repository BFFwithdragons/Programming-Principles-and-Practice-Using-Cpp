#include "std_lib_facilities.h"



struct Stats {
    double smallest;
    double largest;
    double mean;
    double median;
};


ostream& operator << (ostream& os, const Stats& s) {
    os << s.smallest << "/n";
}

double findsmallest(vector<double> v) {
    double smallest = v[0];
    for(int i = 1; i < v.size(); ++i) {
        if(smallest > v[i]) smallest =  v[i];
    }

    return smallest;
}

double findlargest(vector<double> v) {
    double largest = v[0];
    for(int i = 1; i < v.size(); ++i) {
        if(largest < v[i]) largest =  v[i];
    }

    return largest;
}

/**
 * @param v A vector of numbers
 * @return `Stats` struct
 */
Stats compute(vector<double> v) {
    double smallest;
    double largest;
    double sum = 0;
    //Smallest
    smallest = findsmallest(v);
    //Largest
    largest = findlargest(v);
    //Mean

    //Medium
    sort(v.begin(), v.end());
    return {0, 0, 0, 0};
}


int main() {
    vector<double> v = {1, 6, 4, 2};
    cout << compute(v);
    cout << "Smallest 1.0 | Larget 6.0 | 3.25 | Median 3.0";

}