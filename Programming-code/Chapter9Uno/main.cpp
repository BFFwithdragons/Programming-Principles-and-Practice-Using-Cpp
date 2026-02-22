#include "std_lib_facilities.h"
#include "uno.h"

int main() {
    Deck d;
    Player p("Ellie Chung");
    d.shuffle();
    cout << d.get_draw_pile() << endl;
    // p.add_cards(d.draw_amount(7));
    // cout << "hand" << endl;
    // cout << p; 
}