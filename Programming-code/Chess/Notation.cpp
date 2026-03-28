#include "std_lib_facilities.h"
#include "Chess.h"


//Helper functions
bool found_char(char search, string s) {
    for(char c : s) {
        if(c == search) return true;
    }

    return false;
}

bool validate_notation (string notation) {
    int c = 0;
    if(notation[c] != 'N' && notation[c] != 'B' && notation[c] != 'R' && notation[c] != 'Q' && notation[c] != 'K') 
    {
        if(found_char('x', notation)) c = 1;
        if(found_char('x', notation) && notation[0] != 'x') return false;
        if(notation[c] == 'a' || notation[c] == 'b' || notation[c] == 'c' || notation[c] == 'd' || notation[c] == 'e' || notation[c] == 'f' || notation[c] == 'g' || notation[c] == 'h') {
            if(notation[c + 1] == '1' || notation[c + 1] == '2' || notation[c + 1] == '3' || notation[c + 1] == '4' || notation[c + 1] == '5' || notation[c + 1] == '6' || notation[c + 1] == '7' || notation[c + 1] == '8') {
                if(notation.size() <= c + 2) return true;
                if(notation[c + 2] == '+' && notation.size() <= c + 3) return true;
                return false;
            } else {
                return false;
            }
        } else{
            return false;
        }
    }
    //Non-pawn piece:

        if(found_char('x', notation)) c = 1;
        if(found_char('x', notation) && notation[1] != 'x') return false;
        if(notation[c + 1] == 'a' || notation[c + 1] == 'b' || notation[c + 1] == 'c' || notation[c + 1] == 'd' || notation[c + 1] == 'e' || notation[c + 1] == 'f' || notation[c + 1] == 'g' || notation[c + 1] == 'h') {
            if(notation[c + 2] == '1' || notation[c + 2] == '2' || notation[c + 2] == '3' || notation[c + 2] == '4' || notation[c + 2] == '5' || notation[c + 2] == '6' || notation[c + 2] == '7' || notation[c + 2] == '8') {
                if(notation.size() <= c + 3) return true;
                if(notation[c + 3] == '+' && notation.size() <= c + 4) return true;
                return false;
            } else {
                return false;
            }
        } else{
            return false;
        }

        return false;

}