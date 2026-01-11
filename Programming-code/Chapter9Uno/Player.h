#pragma once

#include "uno.h"
#include "std_lib_facilities.h"

class Player {
    public:
        string get_name() const {return name;}
        vector<Card> get_hand() const {return hand;}
        void add_card(Card c) {hand.push_back(c);}
        void add_cards(vector<Card> c);
        Card play_card(Card c);
    private:
        string name;
        vector<Card> hand;
};