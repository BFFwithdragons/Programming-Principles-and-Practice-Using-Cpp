#pragma once
#include "Chess.h"
#include "std_lib_facilities.h"

enum class Color {
        black, white, none
};

class Piece {
    public:
        //Default constructor:
        Piece() {
            symbol = '-';
            color = Color::none;
        }

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
ostream& operator<<(ostream& os,  Piece p);