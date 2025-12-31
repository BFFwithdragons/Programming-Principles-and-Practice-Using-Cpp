#include "std_lib_facilities.h"
#include "uno.h"

int main() {
    Deck d;
    for(int i = 0; i < d.get_draw_pile().size(); ++i) {
       // cout << i << ": " << d.get_draw_pile()[i].get_color() << "Number: " << d.get_draw_pile()[i].get_number() << endl;
        cout << i << ": "
        << static_cast<int>(d.get_draw_pile()[i].get_color())
        << " Number: "
        << static_cast<int>(d.get_draw_pile()[i].get_number())
        << endl;
    }
    Card c = d.draw();

}