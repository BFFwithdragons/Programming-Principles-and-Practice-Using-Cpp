#include "std_lib_facilities.h"
#include "uno.h"

int main() {
    Deck d;
    cout << d << endl;
    Card c = d.draw();

}