#include <iostream>
#include <string>

class Book {
    std::string title;
    int pages;
public:
    Book(std::string t = "", int p = 0)
        : title(std::move(t)), pages(p) {
        std::cout << "Book Constructor: \"" << title << "\" with " << pages << " pages\n";
    }

    ~Book() {
        std::cout << "Book Destructor: \"" << title << "\" destroyed\n";
    }

    void display() const {
        std::cout << "Title: " << title << ", Pages: " << pages << '\n';
    }
};

// ------------------ EXAMPLE 1 ------------------
void runExample1() {
    std::cout << "\n--- Running Example 1 ---\n";
    Book shelf[3] = {
        {"C++ Fundamentals", 300},
        {"Data Structures", 450},
        {"Algorithms", 500}
    };

    std::cout << "\n--- Library Contents ---\n";
    for (const auto& book : shelf)
        book.display();

    std::cout << "\n--- End of Program ---\n";
}

// ------------------ EXAMPLE 2 ------------------
class BookShelf {
    Book* books;
    std::size_t count;
public:
    BookShelf() {
        count = 3;
        books = new Book[count]{
            {"C++ Fundamentals", 300},
            {"Data Structures", 450},
            {"Algorithms", 500}
        };
        std::cout << "BookShelf Constructor: Shelf initialized with " << count << " books\n";
    }

    void display() const {
        std::cout << "\nBooks on shelf:\n";
        for (std::size_t i = 0; i < count; ++i)
            books[i].display();
    }

    ~BookShelf() {
        delete[] books;
        std::cout << "BookShelf Destructor: Shelf destroyed\n";
    }
};

void runExample2() {
    std::cout << "\n--- Running Example 2 ---\n";
    BookShelf shelf;
    shelf.display();
}

// ------------------ MAIN ------------------
int main() {
    std::cout << "Choose example to run (1 or 2): ";
    int choice;
    std::cin >> choice;

    if (choice == 1)
        runExample1();
    else if (choice == 2)
        runExample2();
    else
        std::cout << "Invalid choice.\n";

    return 0;
}
