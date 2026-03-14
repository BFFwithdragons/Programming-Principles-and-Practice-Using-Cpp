#include "uno.h"

void Game::start_game() {  
    d.shuffle();

    string changed_name;
    cout << "Player one, choose your name - ";
    cin >> changed_name;

    p1.change_name(changed_name);

    cout << "Player two, choose your name - ";
    cin >> changed_name;

    p2.change_name(changed_name);

    p1.add_cards(d.draw_amount(7));

    p2.add_cards(d.draw_amount(7));

    d.discard(d.draw());
    while(true) {
        manage_turn(p1, d);
    
        manage_turn(p2, d);
        turn++;

    }
}

//Helper function

void manage_turn(Player& p, Deck& d) {
    Card top_discard = d.get_discard_pile()[d.get_discard_pile().size() - 1];
    cout << "Top Discarded Card -> (" << colorToString(top_discard.get_color()) << ", " << static_cast<int>(top_discard.get_number()) << ")" << endl;
    int choosing;
    cout << p;
    cin >> choosing;
    if(choosing == 0) exit(0);
    if(is_matching(top_discard, p.get_hand()[choosing - 1])) {
        d.discard(p.play_card(p.get_hand()[choosing - 1]));
    } else {
        cout << "The card does not match to the top discarded card. Try again" << endl;
        manage_turn(p, d);
    }
}

bool is_matching(Card c1, Card c2) {
    if(c1.get_color() == c2.get_color()) {
        return true;
    }

    if(c1.get_number() == c2.get_number()) {
        return true;
    }

    return false;
}