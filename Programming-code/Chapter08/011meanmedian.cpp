#include "std_lib_facilities.h"



struct Stats {
    double smallest;
    double largest;
    double mean;
    double median;
};


ostream& operator << (ostream& os, const Stats& s) {
    os << "| Smallest " <<  s.smallest << " | Largest " << s.largest << " | Mean " << s.mean << " | Median " << s.median << " |";
    return os;
}

double findsmallest(const vector<double>& v) {
    double smallest = v[0];
    for(int i = 1; i < v.size(); ++i) {
        if(smallest > v[i]) smallest =  v[i];
    }

    return smallest;
}

double findlargest(const vector<double>& v) {
    double largest = v[0];
    for(int i = 1; i < v.size(); ++i) {
        if(largest < v[i]) largest =  v[i];
    }

    return largest;
}

double findmean(const vector<double>& v) {
    double mean = v[0];

    for(int i = 1; i < v.size(); ++i){
        mean += v[i];
    }

    mean /= v.size();

    return mean;
}

double ordernumbers(vector<double>& v) {
    vector<double> vcopy;
    vcopy = v;
    v.clear();

    while(vcopy.size() > 0) {
        double smallest = vcopy[0];
        int smallestindex = 0;
        for(int i = 0; i < vcopy.size(); ++i) {
            if(smallest > v[i]) {
                smallest =  vcopy[i];
                smallestindex = i;
            }
        }
        v.push_back(smallest);
        vcopy.erase((vcopy.begin() + smallestindex));
    }
}

double findmedium(vector<double> v) {
    ordernumbers(v);
    if(v.size() % 2 != 0) return (v[ceil(v.size() / 2)]);
    else if (v.size() % 2 == 0) return ((v[(v.size() - 1) / 2] + v[((v.size() - 1) / 2) + 1]) / 2);
    else error("invalid number");
}

void print(string label, const vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << label << v[i] << endl;
    }
}

/**
 * @param v A vector of numbers
 * @return `Stats` struct
 */
Stats compute(vector<double> v) {
    double smallest;
    double largest;
    double mean;
    double medium;
    double sum = 0;
    //Smallest
    smallest = findsmallest(v);
    //Largest
    largest = findlargest(v);
    //Mean
    mean = findmean(v);
    //Medium
    medium = findmedium(v);



    return {smallest, largest, mean, medium};
}


int main() {
    vector<double> v = {1, 6, 4, 2};
    cout << compute(v) << endl;
    cout << "Expected: Smallest 1.0 | Larget 6.0 | 3.25 | Median 3.0";

}