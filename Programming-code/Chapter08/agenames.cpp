#include "std_lib_facilities.h"


void pairvectors(const vector<string>& names, vector<string>& ages, const vector<string>& namescopy) {
    vector<string> sorted_ages;
    for (int i = 0; i < names.size(); ++i) {
        for (int j = 0; j < namescopy.size(); ++j) {
            if (names[i] == namescopy[j]) {
                sorted_ages.push_back(ages[j]);
                break;
            }
        }
    }
    ages = sorted_ages;
}

void promtvectors(vector<string>& names, vector<string>& ages) {
    cout << "Add 5 names";
    for(int i = 0; i < 5; i++) {
    string name1;
    cin >> name1;
    names.push_back(name1);
    }


    cout << "Add 5 ages";
    for(int i = 0; i < 5; i++) {
    string age1;
    cin >> age1;
    ages.push_back(age1);
    }
}

void sortnames(vector<string>& names) {
    sort(names.begin(), names.end());
}

void printpairs(string label, const vector<string>& v, const vector<string>& b) {
    for (int i = 0; i < v.size(); i++) {
        cout << label << v[i] << ", " << b[i] << endl;
    }
}

int main() {
    vector<string> names;
    vector<string> ages;
    promtvectors(names, ages);
    printpairs("Pair: ", names, ages);
    vector<string> namescopy = names;
    sortnames(names);


    pairvectors(names, ages, namescopy);
    printpairs("Pair: ", names, ages);
}