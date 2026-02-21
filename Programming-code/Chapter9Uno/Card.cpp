#include "std_lib_facilities.h"
#include "Card.h"

bool operator==(const Card& a, const Card& b)  {
    return a.get_color()==b.get_color() 
    && a.get_number()==b.get_number();
}

string colorToString(Color c) {
    switch (c) {
        case Color::red : return "red";
        case Color::yellow : return "yellow";
        case Color::green : return "green";
        case Color::blue : return "blue";
    }
    return "";
}