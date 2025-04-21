#include <iostream>
using namespace std;

class Book {
private:
    string title;
    int pages;
    string author = "Manish";

protected:
    float Price;

public:
    string publisher;

    void displayAuthorInfo() {
        cout << "Author: " << author << endl;
    }
};

int main() {
    Book b;

    
     //b.title = "My Book";  

   
    b.publisher = "Publisher";
    cout << "Publisher: " << b.publisher << endl;

   
    b.displayAuthorInfo();

    return 0;
}
