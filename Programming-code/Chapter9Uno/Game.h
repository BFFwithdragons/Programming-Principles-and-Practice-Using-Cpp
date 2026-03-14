#pragma once
#include "uno.h"

#include "std_lib_facilities.h"

class Game {
    public:
        void start_game();
    private:
        Player p1;
        Player p2;
        
        Deck d;

        int turn = 1;

};

//Helper Functions

void manage_turn(Player& p, Deck& d);

bool is_matching(Card c1, Card c2);