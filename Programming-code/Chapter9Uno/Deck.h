#include "std_lib_facilities.h"
#include "Card.h"
class Deck {
    public:
        Deck() {
            //loop
            for(int i = 0; i < 80; ++i) { // Normal card generation
                int color = floor(i / 20);
                int number = i % 10;
                Card c (allColors[color], allNumbers[number]);
                draw_pile.push_back(c);
            }
        }
        vector<Card> get_draw_pile() const {return draw_pile;}
        vector<Card> get_discard_pile() const {return discard_pile;}

        Card draw();
        vector<Card> draw_amount(int amount);
        void shuffle();
    private:
        vector<Card> draw_pile;
        vector<Card> discard_pile;
};

ostream& operator<<(ostream& os, Deck& d);