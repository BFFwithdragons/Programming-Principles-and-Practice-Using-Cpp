#include "std_lib_facilities.h"
#include "Chrono.h"
using namespace Chrono;
//
bool is_number(char c);
bool validize_isbn(string isbn);

class Patron {
    public:
        Patron(string name, int card_number, int fees_due) 
            :name(name), card_number(card_number), fees_due(fees_due) {}

        string get_name() const {return this->name;}
        int get_card_number() const {return this->card_number;}
        int get_fees_due() const{return this->fees_due;}
        void set_fees(int amount) {fees_due = amount;}
    private:
        string name;
        int card_number;
        int fees_due;
};

//Helper function
bool owes_fees(Patron p) {
    if(p.get_fees_due() == 0) return false;
    return true;
}

//Operator overloading
bool operator==(Patron& a, Patron& b)
{  
    if(a.get_card_number() == b.get_card_number()) return true;
    return false;
}

class Book {
    public:
        enum Genre {
            fiction=1, nonfiction, periodical, biography, children
        };

        Book(string isbn, string title, string author, int year, bool checked_out, Genre genre) 
            :isbn(isbn), title(title), author(author), year(year), checked_out(checked_out), genre(genre) {
                if(!validize_isbn(isbn)) error("Invalid ISBN");
            }
        
        string get_isbn() const {return this->isbn;}
        string get_title() const {return this->title;}
        string get_author() const {return this->author;}
        int get_year() const {return this->year;}
        bool get_checked_out() const {return this->checked_out;}
        void check_out() {this->checked_out = true;}
        void check_in() {this->checked_out = false;}

    private:
        string isbn;
        string title;
        string author;
        int year;
        bool checked_out;
        Genre genre;

    
};

bool is_number(char c) {
    if(c == '1' || c == '2' || c == '3' || c == '4'|| c == '5' || c == '6' || c == '7' || c == '8' || c == '9') return true;
    else return false;
}

bool validize_isbn(string isbn) {
    string example_isbn = "n-nnn-nnnnn-n";
    if(isbn.size() != example_isbn.size()) return false;
    for(const char& i : isbn) {
        if(example_isbn[i] == 'n') {
            if(!is_number(i)) return false;
        }
        if(example_isbn[i] == '-') {
            if(isbn[i] != '-') return false;
        }
    }
    return true;
}

bool operator==(Book& a, Book& b)
{  
    if(a.get_isbn().size() != b.get_isbn().size()) return false;
    for(int i = 0; i < a.get_isbn().size(); ++i) {
        if(a.get_isbn()[i] != b.get_isbn()[i]) return false;
    }
    return true;
}

bool operator!=(Book& a, Book& b)
{  
    if(a.get_isbn().size() != b.get_isbn().size()) return true;
    for(int i = 0; i < a.get_isbn().size(); ++i) {
        if(a.get_isbn()[i] != b.get_isbn()[i]) return true;
    }
    return false;
}

ostream& operator<<(ostream& os, Book& b)
{
    os << b.get_title()
              << endl << b.get_author()
              << endl << b.get_isbn() << endl;
return os;
}

struct Transaction {
    Book book;
    Patron patron;
    Chrono::Date date;
};

class Libary {
    public:
        void add_book(Book b) {books.push_back(b);}
        void add_patron(Patron p) {patrons.push_back(p);}
        void check_out(Book b, Patron p, Chrono::Date d);
        vector<Patron> get_fee_list();
    private:
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;
};

void Libary::check_out(Book b, Patron p, Chrono::Date d) {
    bool found = false;
    bool found_in_stock = false;
    int counter = 0;
    
    for(Book& bo : books) {
        if(bo == b) {
            if(bo.get_checked_out()) {
                found = true;
                found_in_stock = false;
            }
            else {
                found = true;
                found_in_stock = true;
                break;
            }
        }
        ++counter;
    }
    if(!found) error("Book was not found");
    if(!found_in_stock) error("Book/s is already checked out");
    found = false;
    
    for(Patron& pa : patrons) {
        if(pa == p) found = true;
    }
    
    if(!found) error("Patron was not found");

    if(owes_fees(p)) error("Patron owes fees");

    Transaction t = {b, p, d};
    transactions.push_back(t);
    books[counter].check_out();

}

vector<Patron> Libary::get_fee_list() {
    vector<Patron> store_patron;
    for(Patron& p : patrons) {
        if(owes_fees(p)) store_patron.push_back(p);
    }
    return store_patron;
}

int main() {
    Book b1 = Book("0-590-35340-3", "Harry Potter and the Sorcerer's Stone", "J.K Rowling", 1998, false, Book::fiction);
    Book b2 = Book("0-060-93546-4", "To Kill a Mockingbird", "Harper Lee", 1960, false, Book::fiction);
    Book b3 =  Book("0-394-80079-6", "How the Grinch Stole Christmas!", "Dr. Seuss", 1957, false, Book::children);

    vector<Book> books = {
        Book("0-590-35340-3", "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 1998, false, Book::fiction),
        Book("0-06-112008-1", "To Kill a Mockingbird", "Harper Lee", 1960, true, Book::fiction),
        Book("0-394-80079-6", "How the Grinch Stole Christmas!", "Dr. Seuss", 1957, false, Book::children)
    };

    for(const Book& b : books) cout << b.get_title() << endl;
    for(Book& b: books) {
        b.check_out();
        cout << b.get_title() << " " << b.get_checked_out() << endl;
    }
    //Excercise 7
    cout << "Excersize 7" << endl;
    for(Book& b: books) {
        cout << b;
    }

    //Excersize 9
    cout << "Excersize 9" << endl;
    Libary coding_class;
    Book b4 = Book("0-590-35320-3", "Differnt book", "J.K Rowling", 1998, false, Book::fiction);
    // Book b2 = Book("0-060-93546-4", "To Kill a Mockingbird", "Harper Lee", 1960, false, Book::fiction);
    // Book b3 =  Book("0-394-80079-6", "How the Grinch Stole Christmas!", "Dr. Seuss", 1957, false, Book::children);
    Patron p1 = Patron("cookie", 123456789, 1);
    Patron p2 = Patron("elijah", 125456789, 0);

    Chrono::Date d1(2025, Chrono::Date::Month::jan, 1);
    coding_class.add_book(b1);
    coding_class.add_book(b2);
    coding_class.add_book(b3);
    coding_class.add_patron(p1);
    coding_class.add_patron(p2);
    cout << coding_class.get_fee_list()[0].get_name() << endl;
    coding_class.check_out(b2, p2, d1);

}