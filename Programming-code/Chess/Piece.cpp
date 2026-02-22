#include "Chess.h"

bool operator==(const Piece& a, const Piece& b)  {
    return a.get_symbol()==b.get_symbol() 
    && a.get_color()==b.get_color();
}