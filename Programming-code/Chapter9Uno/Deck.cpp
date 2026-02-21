#include "Deck.h"
#include "std_lib_facilities.h"
Card Deck::draw() {
    Card drawed_card = draw_pile[0];
    draw_pile.erase(draw_pile.begin());
    return drawed_card;
}

vector<Card> Deck::draw_amount(int amount) {
    vector<Card> drawed_cards;
    for(int i = 0; i < amount; ++i) drawed_cards.push_back(draw());
    return drawed_cards; 
}

void Deck::shuffle() {
    for(int i = draw_pile.size(); i > 0; --i) {
        swap(draw_pile[i], draw_pile[rand_int(0, i)]);

    }
}

ostream& operator<<(ostream& os,  vector<Card> d)
{
    for (int i = 0; i < d.size(); i++) {
    os << '(' << colorToString(d[i].get_color())
              << ',' << static_cast<int>(d[i].get_number())
              << ')' << endl;
    }
    return os;
}