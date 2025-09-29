#include "std_lib_facilities.h"

/**
 * @param price A vector of prices
 * @param weight A vector of weights in pounds
 * @note `price[i]` corropsonds `weight[i]`
 * @invariant price and weight must be the same size
 * @brief returns the products of all the weights and prices
 */
 double index(vector<double> price, vector<double> weight) {
    if(weight.size() != price.size()) throw runtime_error("Price and weight must have the sane size");
    double total = 0;
    for(int i = 0; i < weight.size(); ++i) {
        total += price[i] * weight[i];
    }
    
    return total;
 }


int main() {

    vector<double> price = {4.0, 7.0, 8.0};
    vector<double> weight = {5.0, 6.0, 7.0};
    cout << index(price, weight) << endl;
    cout << "Expected 118" << endl;

    // price = {4.0, 7.0, 8.0, 99.0};
    // weight = {5.0, 6.0, 7.0};
    // cout << index(price, weight) << endl;
    // cout << "Price and weight must have the sane size" << endl;
    return 1;
}