#include "Chess.h"
#include "std_lib_facilities.h"



Board::Board() {
    board.push_back(start::row_1);
    board.push_back(start::row_2);
    board.push_back(start::row_3);
    board.push_back(start::row_4);
    board.push_back(start::row_5);
    board.push_back(start::row_6);
    board.push_back(start::row_7);
    board.push_back(start::row_8);
}

void Board::render() {
    for(int i = 7; i >= 0; --i) {
        cout << i + 1 << "   ";
        for(int j = 0; j < 8; ++j) {
            if(board[i][j].get_color() == Color::white) cout << "\033[31m" << board[i][j].get_symbol() << "\033[0m" << "  ";
            else if(board[i][j].get_color() == Color::black) cout << "\033[34m" << board[i][j].get_symbol() << "\033[0m" << "  ";
            else cout << board[i][j].get_symbol() << "  ";
        }
        cout << "\n";
    }
    cout << "    A  B  C  D  E  F  G  H" << endl;
}

void Board::move_piece(string original_place, string new_place) {
    vector<int> return_notation = notation_to_int(original_place);
    Piece moving_piece = board[return_notation[0]][return_notation[1]];
    board[return_notation[0]][return_notation[1]] = start::empty_space;
    return_notation = notation_to_int(new_place);
    board[return_notation[0]][return_notation[1]] = moving_piece;
}

//Takes in a square and then returns all legal possibilities that a rook could move to.
//The algorithem will be that either the x or y has to be the same. The value that is different will be changed from 1-8 all row/collums depending if it's x or y.
//

vector<vector<int>> Board::movement_rook(string square) {
    vector<vector<int>> legal_moves;
    
    int x = squareToInt(square)[0];
    int y = squareToInt(square)[1];

    for(int i = 0; i < 8; i++) {
        if(x != i) legal_moves.push_back({i, y});
    }

    for(int i = 0; i < 8; i++) {
        if(y != i) legal_moves.push_back({x, i});
    }

    return legal_moves;


}

vector<vector<int>> Board::movement_bishop(string square) {
    vector<vector<int>> legal_moves;
    int x = squareToInt(square)[0];
    int y = squareToInt(square)[1];

    int x_counter = x;
    int y_counter = y;

    while(x_counter < 8 && y_counter < 8) {
        if(x_counter != x && y_counter != y) legal_moves.push_back({x_counter, y_counter});        
        x_counter++;
        y_counter++;
    }

    x_counter = x;
    y_counter = y;

    while(x_counter >= 0 && y_counter >= 0) {
        if(x_counter != x && y_counter != y) legal_moves.push_back({x_counter, y_counter});        
        x_counter--;
        y_counter--;
    }

    x_counter = x;
    y_counter = y;

    while(x_counter >= 0 && y_counter < 8) {
        if(x_counter != x && y_counter != y) legal_moves.push_back({x_counter, y_counter});        
        x_counter--;
        y_counter++;
    }

    x_counter = x;
    y_counter = y;

    while(x_counter < 8 && y_counter >= 0) {
        if(x_counter != x && y_counter != y) legal_moves.push_back({x_counter, y_counter});        
        x_counter++;
        y_counter--;
    }

    return legal_moves;
}

vector<vector<int>> Board::movement_queen(string square) {
    vector<vector<int>> legal_moves = movement_bishop(square);
    vector<vector<int>> rook_moves = movement_rook(square);
    legal_moves.insert(legal_moves.end(), rook_moves.begin(), rook_moves.end());
    return legal_moves;
}
//Helper Functions

vector<int> notation_to_int(string notation) {
    int row;
    int collum;
    if(notation[0] == 'a') collum = 0;
    if(notation[0] == 'b') collum = 1; 
    if(notation[0] == 'c') collum = 2;
    if(notation[0] == 'd') collum = 3;
    if(notation[0] == 'e') collum = 4;
    if(notation[0] == 'f') collum = 5;
    if(notation[0] == 'g') collum = 6;
    if(notation[0] == 'h') collum = 7;



    if(notation[1] == '1') row = 0;
    if(notation[1] == '2') row = 1; 
    if(notation[1] == '3') row = 2;
    if(notation[1] == '4') row = 3;
    if(notation[1] == '5') row = 4;
    if(notation[1] == '6') row = 5;
    if(notation[1] == '7') row = 6;
    if(notation[1] == '8') row = 7;

    vector<int> return_notation = {row, collum};
    return return_notation; 


}

vector<int> squareToInt(string notation) {
    return {(notation[0] - 97), (notation[1] - 49)};
}



