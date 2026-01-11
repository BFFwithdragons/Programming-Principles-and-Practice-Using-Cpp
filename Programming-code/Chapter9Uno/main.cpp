#include "std_lib_facilities.h"
#include "uno.h"

int main() {
    Deck d;
    Player p;
    cout << d.get_draw_pile() << endl;
    cout << "finished" << endl;
    Card c = d.draw();
    p.add_card(d.draw());
    cout << p.get_hand();

}