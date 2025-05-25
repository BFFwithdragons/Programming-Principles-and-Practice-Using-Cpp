#include "std_lib_facilities.h"




bool sentence();
bool noun(string);
bool verb(string);
bool conjuction(string);


int main(){

    while(cin) {
        bool b = sentence();
        if (b) cout << "Ok" << endl;
        else cout << "not Ok" <<endl;
        cout << "Try Again please" << endl;
    }
    return 0;
}

bool sentence() {
    // recocnize if text on the input stream is a valid sentence according to our grammar
    string w;
    cin >> w;
    // not a noun then were done
    if(!noun(w)) return false;
    // not a verb then were done
    cin >> w;
    if(!verb(w)) return false;
    // if its ende of sentence that means its okay
    cin >> w;
    if(w == ".") return true;
    // if not the end it must be a conjunction so if its not return false
    if(!conjuction(w)) return false;
    //i need a function that knows how to recognize sentences.....
    return sentence();
}

bool conjuction(string w) {
    return (w == "and" || w == "but" || w == "or");
}


bool noun(string w) {
    return (w == "birds" || w == "fish" || w == "c++");

}

bool verb(string w) {
    return (w == "rules" || w == "fly" || w == "swim");

    
}
