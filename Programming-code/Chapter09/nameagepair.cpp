#include "std_lib_facilities.h"

class Name_pairs {
    public:
    void read_names();
    void read_ages();
    void print();
    void sort();
    vector<string> get_names();
    vector<int> get_ages();
    private:
    vector<string> names;
    vector<int> ages;
};

void Name_pairs::read_names() {
    string buffer;
    cout << "names: ";
    while(cin >> buffer) {
        if(buffer == ";") break;
        names.push_back(buffer);
        buffer = "";
    }
}

void Name_pairs::read_ages() {
    int buffer;
    cout << "ages: ";
    for(int i = 0; i < names.size(); ++i) {
        cin >> buffer;
        ages.push_back(buffer);
        buffer = 0;
    }
}

void Name_pairs::print() {
    for (int i = 0; i < names.size(); i++) {
        cout << "(" << names[i] << ", " << ages[i] << ")"  << endl;
    }
}

void Name_pairs::sort() {
    vector<string> namescopy = names;
    std::sort(names.begin(), names.end());
    vector<int> sorted_ages;
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

vector<string> Name_pairs::get_names() {
    return names;
}

vector<int> Name_pairs::get_ages() {
    return ages;
}
ostream& operator<<(ostream& os, Name_pairs& n)
{
    for (int i = 0; i < n.get_names().size(); i++) {
    os << '(' << n.get_names()[i]
              << ',' << n.get_ages()[i]
              << ')' << endl;
}
return os;
}

bool operator==(Name_pairs& a, Name_pairs& b)
{  
    if(a.get_names().size() != b.get_names().size()) return false;
    for(int i = 0; i < a.get_names().size(); ++i) {
        if(a.get_names()[i] != b.get_names()[i] || a.get_ages()[i] != b.get_ages()[i]) return false;
    }
    return true;
}

bool operator!=(Name_pairs& a, Name_pairs& b)
{  
    if(a.get_names().size() != b.get_names().size()) return true;
    for(int i = 0; i < a.get_names().size(); ++i) {
        if(a.get_names()[i] != b.get_names()[i] || a.get_ages()[i] != b.get_ages()[i]) return true;
    }
    return false;
}

int main() {
    Name_pairs list_one;
    list_one.read_names();
    list_one.read_ages();
    list_one.print();
    list_one.sort();
    cout << list_one << endl;

    Name_pairs list_two;
    list_two.read_names();
    list_two.read_ages();
    list_two.print();
    list_two.sort();
    cout << list_two << endl;

    if(list_two == list_one) cout << "same" << endl;
    else cout << "false" << endl;

    cout << "=! test" << endl;
    if(list_two != list_one) cout << "differnt";
    else cout << "false";
}