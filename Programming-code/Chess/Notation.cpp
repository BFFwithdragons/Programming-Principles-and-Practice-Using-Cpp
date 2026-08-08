#include "std_lib_facilities.h"
#include "Chess.h"


//Helper functions
bool found_char(char search, string s) {
    for(char c : s) {
        if(c == search) return true;
    }

    return false;
}

int find_index(char search, string s) {
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == search) return i;
    }

    return -1; // Something went wrong
}

bool validate_notation (string notation) {
    int c = 0;
    if(notation[c] != 'N' && notation[c] != 'B' && notation[c] != 'R' && notation[c] != 'Q' && notation[c] != 'K') 
    {
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
        if(notation[1] == 'a' || notation[1] == 'b' || notation[1] == 'c' || notation[1] == 'd' || notation[1] == 'e' || notation[1] == 'f' || notation[1] == 'g' || notation[1] == 'h') {
            if(notation[2] == '1' || notation[2] == '2' || notation[2] == '3' || notation[2] == '4' || notation[2] == '5' || notation[2] == '6' || notation[2] == '7' || notation[2] == '8') {
                if(notation.size() <= 3) return true;
                return false;
            } else {
                return false;
            }
        } else{
            return false;
        }

        return false;

}

