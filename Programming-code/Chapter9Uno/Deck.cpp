#include "Deck.h"

Card Deck::draw() {
    Card drawed_card = draw_pile[0];
    draw_pile.erase(draw_pile.begin());
    return drawed_card;
}

void Deck::shuffle() {
    vector<Card> draw_pile_copy = draw_pile;
    //Random generation code;
    while(draw_pile.size() > 0) {
    int rng; // rng = randon_number(draw_pile[0], draw_pile[draw_pile.size - 1]);
    draw_pile_copy.push_back(draw_pile[rng]);
    draw_pile.erase(draw_pile.begin() + rng);
    }
}