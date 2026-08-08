#pragma once

#include "Piece.h"
#include "std_lib_facilities.h"

class Board {
    public:
        Board();
        void render();
        void move_piece(string original_place, string new_place);
        vector<vector<Piece>> get_board() const {return board;}
        vector<vector<int>> movement_rook(string square);
        vector<vector<int>> movement_bishop(string square);
        vector<vector<int>> movement_queen(string square);
    private:
        vector<vector<Piece>> board;
};

vector<int> notation_to_int(string notation);
vector<int> int_to_notation(vector<int> notation);
vector<int> squareToInt(string notation);