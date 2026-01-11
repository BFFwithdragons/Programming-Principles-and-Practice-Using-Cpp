#include "uno.h"
void Player::add_cards(vector<Card> c) {
    for(int i = 0; i < c.size(); ++i) {
        hand.push_back(c[i]);
    }
}

Card Player::play_card(Card c) {
    for(int i; i < hand.size(); ++i) {
        if(c == hand[i]) {
            hand.erase(hand.begin() + i);
            return c;
        }
    }
    error("Doesn't have card");
    return c;
}