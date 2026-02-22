#include "Chess.h"
void Game::start_game() {
    b.render();
    cout << "\n" << "White's turn - ";
    cin >> move;
    // if(identify_piece(move, Color::white) == start::white_pawn) b.move_piece(, move);
}

Piece identify_piece(string notation, Color turn) {
    if(turn == Color::white) {
        if(notation[0] == 'N') return start::white_knight;
        if(notation[0] == 'B') return start::white_bishop;
        if(notation[0] == 'R') return start::white_rook;
        if(notation[0] == 'Q') return start::white_queen;
        if(notation[0] == 'K') return start::white_king;
        return start::white_pawn;
    }

    if(turn == Color::black) {
        if(notation[0] == 'N') return start::black_knight;
        if(notation[0] == 'B') return start::black_bishop;
        if(notation[0] == 'R') return start::black_rook;
        if(notation[0] == 'Q') return start::black_queen;
        if(notation[0] == 'K') return start::black_king;
        return start::black_pawn;
    }

}