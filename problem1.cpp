// CMPT 225 D100 - Summer 2025
// Instructor: Jocelyn Minns
// DO NOT REPOST
// Student name: 

#include <iostream>
#include <string>

using std::string;

// structure for book data
struct Book {
    string title;
    string author;
    bool isCheckedOut;
};

// Abstract class
class Library {
public:
    // virtual destructor, common practice for abstract classes
    virtual ~Library() {}; 

    // Adds a new book to the library at a specific ID (shelf spot)
    virtual bool addBook(int id, const std::string& title, const std::string& author) = 0;

    // Removes a book from the library based on its ID
    virtual bool removeBook(int id) = 0;

    // Replaces an existing book at a given ID with a new title and author
    virtual bool swapBook(int id, const std::string& newTitle, const std::string& newAuthor) = 0;

    // Flags the book at the given ID as checked out (borrowed)
    virtual bool checkOutBook(int id) = 0;

    // Flags the book at the given ID as returned (in the library)
    virtual bool returnBook(int id) = 0;

    // Checks if the book at the given ID is currently in the library
    virtual bool isInLibrary(int id) const = 0;

    // Returns a string with information about the book at the given ID
    virtual std::string getBookInfo(int id) const = 0;

    // Returns the total number of books currently stored in the library
    virtual int totalBooks() const = 0;

    // Returns the number of books that are currently available in the library
    virtual int booksInLibrary() const = 0;

    // Returns the number of books that are currently checked out
    virtual int booksLentOut() const = 0;
};


class SFULibrary : public Library{
    // YOUR CODE HERE
};


int main() {
    Library* lib = new SFULibrary();
    
    lib->addBook(0, "1984", "George Orwell");
    lib->addBook(1, "The Hobbit", "J.R.R. Tolkien");
    lib->addBook(2, "Dune", "Frank Herbert");

    std::cout << lib->getBookInfo(0) << "\n";
    lib->checkOutBook(0);
    std::cout << lib->getBookInfo(0) << "\n";

    lib->returnBook(0);
    std::cout << lib->getBookInfo(0) << "\n";

    lib->swapBook(2, "Foundation", "Isaac Asimov");
    std::cout << lib->getBookInfo(2) << "\n";

    std::cout << "Total books: " << lib->totalBooks() << "\n";
    std::cout << "Books in: " << lib->booksInLibrary() << "\n";
    std::cout << "Books out: " << lib->booksLentOut() << "\n";

    delete lib;
    return 0;
}

