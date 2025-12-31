#pragma once

#include "std_lib_facilities.h"

enum class Color {
    red, yellow, green, blue
};

enum class Number {
    zero=0, one, two, three, four, five, six, seven, eight, nine
};

constexpr Color allColors[] = {Color::red, Color::yellow, Color::green, Color::blue};
constexpr Number allNumbers[] = {Number::zero, Number::one, Number::two, Number::three, Number::four, Number::five, Number::six, Number::seven, Number::eight, Number::nine};

class Card {
    public:
        Card(Color c, Number n)
        : color(c), number(n) {}

        Number get_number() const {return number;}
        Color get_color() const {return color;}

    private:
        Number number;
        Color color;
};


