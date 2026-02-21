#include "std_lib_facilities.h"
bool scores_increasing(vector<int> scores) {
    int highest_score;
    for(int i = 1; i < scores.size(); ++i) {
        if(scores[i] < scores[i - 1] && scores[i] != scores[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> pass = {1, 2, 3, 5, 5, 7};
    cout << scores_increasing(pass) << endl;
    vector<int> fail = {1, 2, 3, 4, 7, 5};
    cout << scores_increasing(fail);
}

