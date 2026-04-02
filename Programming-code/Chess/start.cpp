#include "Chess.h"

namespace start {
Piece pawn('*', Color::none);
Piece bishop('&', Color::none);
Piece knight('@', Color::none);
Piece rook('^', Color::none);
Piece queen('$', Color::none);
Piece king('+', Color::none);

Piece white_pawn('*', Color::white);
Piece white_bishop('&', Color::white);
Piece white_knight('@', Color::white);
Piece white_rook('^', Color::white);
Piece white_queen('$', Color::white);
Piece white_king('+', Color::white);

Piece black_pawn('*', Color::black);
Piece black_bishop('&', Color::black);
Piece black_knight('@', Color::black);
Piece black_rook('^', Color::black);
Piece black_queen('$', Color::black);
Piece black_king('+', Color::black);

Piece empty_space('-', Color::none);

const vector<Piece> row_1 = {white_rook, white_knight, white_bishop, white_queen, white_king, white_bishop, white_knight, white_rook};
const vector<Piece> row_2 = {white_pawn, white_pawn, white_pawn, white_pawn, white_pawn, white_pawn, white_pawn, white_pawn};
const vector<Piece> row_3 = {empty_space, empty_space, empty_space, empty_space, empty_space, empty_space, empty_space, empty_space};
const vector<Piece> row_4 = {empty_space, empty_space, empty_space, empty_space, empty_space, empty_space, empty_space, empty_space};
const vector<Piece> row_5 = {empty_space, empty_space, empty_space, empty_space, empty_space, empty_space, empty_space, empty_space};
const vector<Piece> row_6 = {empty_space, empty_space, empty_space, empty_space, empty_space, empty_space, empty_space, empty_space};
const vector<Piece> row_7 = {black_pawn, black_pawn, black_pawn, black_pawn, black_pawn, black_pawn, black_pawn, black_pawn};
const vector<Piece> row_8 = {black_rook, black_knight, black_bishop, black_queen, black_king, black_bishop, black_knight, black_rook};
}