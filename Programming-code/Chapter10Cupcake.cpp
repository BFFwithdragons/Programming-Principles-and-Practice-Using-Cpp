#include "std_lib_facilities.h"

/*
    Wishlist
    - Data Type: Item (name, type) to store name and price of the cupcake
    - Order: list of names and quantities
    - reads menu into unordered map of string -> cupcakes
*/

struct Cupcake {
    string name;
    int price;
};
//Reads cupcakes into map
// name of file -> ordered_map(string name -> cupcake)
unordered_map<string, Cupcake> read_menu(string file_name) {
    ifstream cstream {file_name};
    if(!cstream) error("can't open file", file_name);

    string name;
    int price;
    while(cstream >> name >> price) {
        cout << name << endl;
        cout << price << endl;
    }
}


int main() {
    read_menu("menu.txt");
}