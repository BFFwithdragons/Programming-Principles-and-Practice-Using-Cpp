#pragma once
#include "std_lib_facilities.h"
#include "Chess.h"

class Notation {
    public:
        Notation(string r) 
            : raw_notation(r) {
                // string buffer_notation = raw_notation;
                // if(raw_notation[0] == 'x') buffer_notation.erase(0, 0);
                // if(raw_notation[0] == 'b') piece = 

            }
    private:
        string raw_notation;
        Piece piece;
        string target;
        bool check;


};

bool found_char(char search, string s);
bool validate_notation (string notation);