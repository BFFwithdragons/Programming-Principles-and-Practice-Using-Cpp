#include "Chess.h"
#include "std_lib_facilities.h"

bool operator==(const Piece& a, const Piece& b)  {
    return a.get_symbol()==b.get_symbol() 
    && a.get_color()==b.get_color();
}

ostream& operator<<(ostream& os,  Piece p)
{
    string buffer_name = "N/A";
    string buffer_color;
    if(p.get_symbol() == start::pawn.get_symbol()) buffer_name = "Pawn";
    if(p.get_symbol() == start::bishop.get_symbol()) buffer_name = "Bishop";
    if(p.get_symbol() == start::knight.get_symbol()) buffer_name = "Knight";
    if(p.get_symbol() == start::rook.get_symbol()) buffer_name = "Rook";
    if(p.get_symbol() == start::queen.get_symbol()) buffer_name = "Queen";
    if(p.get_symbol() == start::king.get_symbol()) buffer_name = "King";

    if(p.get_color() == Color::black) buffer_color = "Black";
    if(p.get_color() == Color::white) buffer_color = "White";
    if(p.get_color() == Color::none) buffer_color = "Null";

    os << buffer_color << " " << buffer_name << endl;


    return os;
}