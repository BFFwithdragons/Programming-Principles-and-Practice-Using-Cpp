#include "std_lib_facilities.h"
#include "Card.h"
class Deck {
    public:
        Deck() {
            //loop
        }
    private:
        vector<Card> draw_pile;
        vector<Card> discard_pile;
};
