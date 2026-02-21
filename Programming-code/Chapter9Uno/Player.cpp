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

ostream& operator<<(ostream& os,  Player h)
{
    os << h.get_name() << "'s cards" << endl;
    for (int i = 0; i < h.get_hand().size(); i++) {
    os << i + 1 << ". " << '(' << colorToString(h.get_hand()[i].get_color())
              << ',' << static_cast<int>(h.get_hand()[i].get_number())
              << ')'
              << endl;
    }


    return os;
}