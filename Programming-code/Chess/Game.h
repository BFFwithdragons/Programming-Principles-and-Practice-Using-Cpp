#pragma once
#include "Chess.h"

class Game {
    public:
        void start_game();
    private:
        string move;
        Board b;
        Color turn;
};

Piece identify_piece(string notation, Color turn);
