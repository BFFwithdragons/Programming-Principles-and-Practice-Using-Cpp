#include "std_lib_facilities.h"

double combinations(double a, double b, string typecomb);
double factorial(double number);
double p(double a, double b);
double c(double a, double b);

int main() {
    double a;
    double b;
    cout << "Enter two numbers. Total amount of numbers, and the amount of numbers picked" << endl;
    cin >> a, 
    cin >> b;

    string typecomb;
    cout << "Is it a combination, or is it a permutation" << endl;
    cin >> typecomb;
    cout << "There are " << combinations(a, b, typecomb) << " amount of " << typecomb << "s." << endl;
    return 1;
}

double combinations(double a, double b, string typecomb) {
    // Takes in two numbers (total amount of numbers, and the amount picked)
    // Input decides if it is a combination or permutation.
    // Checks if there are errors and give detailed responses based on them.
    // Calculates the combinations of possibilites using the combination or permutations formula.
    // Returns the value.
    if(!double(a) || !double(b)) error("no numbers. Make sure you input two numbers");
    if(a < 0 || b < 0) error("inavid numbers. Must be a positive number");
    if(typecomb == "permutation") return p(a, b);
    else if (typecomb == "combination") return c(a, b);
    else error("invalid strings. You have to choose either a combination or a permutation");

    return 0;
}

double factorial(double number) {
    double factorialvalue = number;
    for(int i = number - 1; i > 0; i--) {
        factorialvalue *= i;
    }
    return factorialvalue;
}

double p(double a, double b) {
    return ((factorial(a)) / factorial(a - b));
}

double c(double a, double b) {
    return (p(a, b) / factorial(b));
}