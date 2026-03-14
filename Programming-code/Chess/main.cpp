#include "std_lib_facilities.h"
#include "Chess.h"




int main() {
    Game g;
    //g.start_game();
    Board b;

    b.render();

    b.move_piece("h1", "h7");
    b.render();
}