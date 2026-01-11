#include "std_lib_facilities.h"
#include "Card.h"

bool operator==(const Card& a, const Card& b)  {
    return a.get_color()==b.get_color() 
    && a.get_number()==b.get_number();
}