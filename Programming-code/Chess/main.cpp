#include "std_lib_facilities.h"
#include "Chess.h"




int main() {
    //Testing
    cout << "e4 "
         << (validate_notation("e4") ? "legal" : "illegal")
         << " expected: legal "
         << (validate_notation("e4") == true ? "PASS" : "FAIL") << endl;

    cout << "Nf3 "
         << (validate_notation("Nf3") ? "legal" : "illegal")
         << " expected: legal "
         << (validate_notation("Nf3") == true ? "PASS" : "FAIL") << endl;

    cout << "Bb5 "
         << (validate_notation("Bb5") ? "legal" : "illegal")
         << " expected: legal "
         << (validate_notation("Bb5") == true ? "PASS" : "FAIL") << endl;

    cout << "xd5 "
         << (validate_notation("xd5") ? "legal" : "illegal")
         << " expected: legal "
         << (validate_notation("xd5") == true ? "PASS" : "FAIL") << endl;

    cout << "Rxa1 "
         << (validate_notation("Rxa1") ? "legal" : "illegal")
         << " expected: legal "
         << (validate_notation("Rxa1") == true ? "PASS" : "FAIL") << endl;

    cout << "e5e6 "
         << (validate_notation("e5e6") ? "legal" : "illegal")
         << " expected: illegal "
         << (validate_notation("e5e6") == false ? "PASS" : "FAIL") << endl;

    cout << "Ke9 "
         << (validate_notation("Ke9") ? "legal" : "illegal")
         << " expected: illegal "
         << (validate_notation("Ke9") == false ? "PASS" : "FAIL") << endl;

    cout << "Pa4 "
         << (validate_notation("Pa4") ? "legal" : "illegal")
         << " expected: illegal "
         << (validate_notation("Pa4") == false ? "PASS" : "FAIL") << endl;

    cout << "Qz5 "
         << (validate_notation("Qz5") ? "legal" : "illegal")
         << " expected: illegal "
         << (validate_notation("Qz5") == false ? "PASS" : "FAIL") << endl;

    cout << "h9 "
         << (validate_notation("h9") ? "legal" : "illegal")
         << " expected: illegal "
         << (validate_notation("h9") == false ? "PASS" : "FAIL") << endl;

    cout << "Bxz3 "
         << (validate_notation("Bxz3") ? "legal" : "illegal")
         << " expected: illegal "
         << (validate_notation("Bxz3") == false ? "PASS" : "FAIL") << endl;

    // Game g;
    // //g.start_game();
    // Board b;

    // b.render();

    // b.move_piece("h1", "h7");
    // b.render();
}