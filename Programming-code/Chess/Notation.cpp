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
    if(found_char('x', notation) && notation[0] != 'x') return false;
}