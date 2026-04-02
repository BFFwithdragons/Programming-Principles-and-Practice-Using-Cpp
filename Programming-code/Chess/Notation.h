#pragma once
#include "std_lib_facilities.h"
#include "Chess.h"
#include "start.h"

bool found_char(char search, string s);
bool validate_notation (string notation);
int find_index(char search, string s);

class Notation {
    public:
Notation(string r) 
            : raw_notation(r) {
                if(!validate_notation(r)) error("invalid notation");
                string buffer_notation = raw_notation;
                if(raw_notation[0] == 'x') buffer_notation.erase(buffer_notation.begin());
                if(raw_notation[1] == 'x') buffer_notation.erase(buffer_notation.begin() + 1);

                if(raw_notation[0] == 'B') piece = start::bishop;
                else if(raw_notation[0] == 'N') {
                    piece = start::knight;
                    buffer_notation.erase(buffer_notation.begin());
                }
                else if(raw_notation[0] == 'R') {
                    piece = start::rook;
                    buffer_notation.erase(buffer_notation.begin());
                }
                else if(raw_notation[0] == 'Q') {
                    piece = start::queen;
                    buffer_notation.erase(buffer_notation.begin());
                }
                else if(raw_notation[0] == 'K') {
                    piece = start::king;
                    buffer_notation.erase(buffer_notation.begin());
                }

                else piece = start::pawn;

                if(found_char('+', buffer_notation)) {
                    check = true;
                    buffer_notation.erase(buffer_notation.begin() + find_index('+', buffer_notation));
                }

                target = buffer_notation;

                cout << target << endl;

                cout << check << endl;

                cout << piece << endl;

                cout << raw_notation << endl;

            }
    private:
        string raw_notation;
        Piece piece;
        string target;
        bool check = false;


};

