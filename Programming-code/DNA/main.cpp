#include "std_lib_facilities.h"

bool is_DNA(string d);
string comp_base(string sequence);

class DNA {
    public:
        DNA(string firstStrand)
        : firstStrand(firstStrand) {
            if(!is_DNA(firstStrand)) {
                error("invalid DNA sequence");
            }

            secondStrand = comp_base(firstStrand);
        }

        string get_firstStrand() const {return firstStrand;}
        string get_secondStrand() const {return secondStrand;}

    private:
        string firstStrand;
        string secondStrand;
};

class RNA {
    public:
    
    private:
        DNA reference;
};

//Helper Functions

bool is_DNA(string d) {
    for(int i = 0; i < d.size(); ++i) {
        if (d[i] != 'A' && d[i] != 'T' && d[i] != 'C' && d[i] != 'G') {
            return false;
        }
    }
    return true;
}

string comp_base(string sequence) {
    for(int i = 0; i < sequence.size(); ++i) {
        if(sequence[i] == 'A') sequence[i] = 'T';
        else if(sequence[i] == 'T') sequence[i] = 'A';
        else if(sequence[i] == 'C') sequence[i] = 'G';
        else if(sequence[i] == 'G') sequence[i] = 'C';

    }
    return sequence;
}

int main() {
    DNA d("ACGTCGTGTACGATC");
    cout << d.get_firstStrand() << endl;
    cout << d.get_secondStrand() << endl;

}