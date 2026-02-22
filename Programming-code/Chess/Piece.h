#pragma once
#include "Chess.h"

enum class Color {
        black, white, none
};

class Piece {
    public:
        Piece(char s, Color c)
        : symbol(s), color(c) {}

        char get_symbol() const {return symbol;}
        Color get_color() const {return color;}

    private:
        char symbol;
        Color color;

        bool moved = false;
};

bool operator==(const Piece& a, const Piece& b);