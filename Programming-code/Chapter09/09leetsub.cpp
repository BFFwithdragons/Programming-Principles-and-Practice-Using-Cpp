#include "std_lib_facilities.h"

void print(string label, const vector<string>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << label << v[i] << endl;
    }
}

vector<string> clear_duplicates(const vector<string>& v) {
    vector<string> vcopy;
    bool found = false;
    for(int i = 0; i < v.size(); ++i) {
        for(int i2 = 0; i2 < vcopy.size(); ++i2) {
            if(vcopy[i2] == v[i]) {
                found = true;
                break;
            }
        }
        if(found == false) {
            vcopy.push_back(v[i]);
        } else {
            found = false;
        }
    }

    return vcopy;
}

char leetchar (char letter) {
    if(letter == 'a') letter = '4';
    if(letter == 'e') letter = '3';
    if(letter == 'i') letter = '1';
    if(letter == 'o') letter = '0';
    if(letter == 's') letter = '5';
    if(letter== 't') letter = '7';

    return letter;
}

vector<string> leetsub(string password) {
    string password_copy = password;
    vector<int> subint;
    vector<string> leetoutputs;
    leetoutputs.push_back(password);

    for(int i = 0; i < password.size(); ++i) {
        if(password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 's' || password[i] == 't') subint.push_back(i);
    }

    for(int i = 0; i < subint.size(); ++i) {
        for(int i2 = i; i2 < subint.size(); ++i2) {
            password[subint[i2]] = leetchar(password[subint[i2]]);
            leetoutputs.push_back(password);
        }
        password = password_copy;
    }

    return clear_duplicates(leetoutputs);
}

int main() {
    string password;
    cout << "Add password ~ ";
    cin >> password;
    print("label: ", leetsub(password));
    
    return 1;
}