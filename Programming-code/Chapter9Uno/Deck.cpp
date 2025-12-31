#include "Deck.h"

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
    vector<Card> draw_pile_copy = draw_pile;
    //Random generation code;
    while(draw_pile.size() > 0) {
    int rng; // rng = randon_number(0, draw_pile.size() - 1);
    draw_pile_copy.push_back(draw_pile[rng]);
    draw_pile.erase(draw_pile.begin() + rng);
    }

    draw_pile = draw_pile_copy;
}

ostream& operator<<(ostream& os,  Deck& d)
{
    for (int i = 0; i < d.get_draw_pile().size(); i++) {
    os << '(' << static_cast<int>(d.get_draw_pile()[i].get_color())
              << ',' << static_cast<int>(d.get_draw_pile()[i].get_number())
              << ')' << endl;
    }
    return os;
}