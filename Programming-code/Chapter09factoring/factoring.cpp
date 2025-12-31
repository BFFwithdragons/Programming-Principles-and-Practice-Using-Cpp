#include "std_lib_facilities.h"

string quadratic_formula_pos(int a, int b, int c) {
    double discriminant = (b * b) - 4 * (a) * (c);
    if(discriminant < 0) {
        return "prime";
    }

    double solution = (-b + sqrt(discriminant)) / (2 * a);

    return to_string(solution);
}

string quadratic_formula_neg(int a, int b, int c) {
    double discriminant = (b * b) - 4 * (a) * (c);
    if(discriminant < 0) {
        return "prime";
    }

    double solution = (-b - sqrt(discriminant)) / (2 * a);

    return to_string(solution);
}

void get_variables(int& a, int& b, int& c) {
    string terms;
    string storing;
    int j = 0;
    while(cin >> terms) {
        if(terms == "") return;
        for(int i = 0; i < terms.size(); ++i) {
            if(terms[i] == '-') {
                storing = "-";
                if(j % 2 != 0) break;
            }
            if(terms[i] == '+') break;
            if(terms[i] == '1' || terms[i] == '2' || terms[i] == '3' || terms[i] == '4' || terms[i] == '5' || terms[i] == '6' || terms[i] == '7' || terms[i] == '8' || terms[i] == '9' || terms[i] == '0') {
                storing.push_back(terms[i]);
            }
            if(terms[i] == '^' || terms[i] == 'x' || i == terms.size() - 1) {
                if(storing == "") storing = "1";
                if(storing == "-") storing = "-1"; 
                if(j == 0) a = stoi(storing);
                if(j == 2) b = stoi(storing);
                if(j == 4) c = stoi(storing);
                if(terms[terms.size() - 1] == ';') return;
                break;
            }
        }
        if(storing != "-") {
        storing = "";
        }
        ++j;
    }
}

void print_results(int a, int b, int c) {
    if(quadratic_formula_pos(a, b, c) == "prime") {
        cout << "prime" << endl;
    } else if(quadratic_formula_pos(a, b, c) == quadratic_formula_neg(a, b, c)) {
        cout << "x = " << quadratic_formula_pos(a, b, c) << endl;
    } else {
        cout << "x = " << quadratic_formula_pos(a, b, c) << " & " << "x = " << quadratic_formula_neg(a, b, c) << endl;
    }
}

int main() {
    int a, b, c;
    // cin >> a;
    // cin >> b;
    // cin >> c;
    get_variables(a, b, c);
    print_results(a, b, c);
    return 1;
}