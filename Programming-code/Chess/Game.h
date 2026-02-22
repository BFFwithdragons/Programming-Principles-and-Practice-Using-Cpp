#pragma once
#include "Chess.h"

class Game {
    public:
        void start_game();
    private:
        Board b;
        Color turn;
        string move;
};

Piece identify_piece(string notation, Color turn);
