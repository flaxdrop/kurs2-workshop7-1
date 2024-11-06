#include <iostream>
#include <string>

class LibraryBook
{
private:
    std::string isbn;
    std::string title;
    std::string author;
    int copies_available;
    int total_pages;

public:
    // Konstruktor som initierar en bok med hjälp av this-pekaren
    LibraryBook(const std::string &isbn, const std::string &title, const std::string &author, int copies, int pages)
    {
        this->isbn = isbn;
        this->title = title;
        this->author = author;
        this->copies_available = copies;
        this->total_pages = pages;
    }

    // Metod för att lägga till kopior av boken
    void addCopies(int qty)
    {
        if (qty > 0)
        {
            this->copies_available += qty;
            std::cout << qty << " copies added. Total copies available: " << this->copies_available << std::endl;
        }
        else
        {
            std::cerr << "Error: Quantity to add must be positive." << std::endl;
        }
    }

    // Metod för att ta bort kopior av boken
    void removeCopies(int qty)
    {
        if (qty <= 0)
        {
            std::cerr << "Error: Quantity to remove must be positive." << std::endl;
        }
        else if (qty > this->copies_available)
        {
            std::cerr << "Error: Not enough copies available to remove. Current available copies: " << this->copies_available << std::endl;
        }
        else
        {
            this->copies_available -= qty;
            std::cout << qty << " copies removed. Total copies available: " << this->copies_available << std::endl;
        }
    }

    // Metod för att hämta alla detaljer om boken
    std::string getBookInfo() const
    {
        return "ISBN: " + this->isbn + "\nTitle: " + this->title + "\nAuthor: " + this->author +
               "\nCopies Available: " + std::to_string(this->copies_available) +
               "\nTotal Pages: " + std::to_string(this->total_pages);
    }
};

int main()
{
    // Skapar en instans av LibraryBook
    LibraryBook book("978-3-16-148410-0", "Programming in C++", "John Doe", 5, 450);

    // Skriver ut informationen om boken
    std::cout << "Initial Book Information:\n"
              << book.getBookInfo() << "\n\n";

    // Lägger till 4 förekomster av boken
    book.addCopies(4);

    // Skriver ut informationen igen
    std::cout << "\nAfter Adding Copies:\n"
              << book.getBookInfo() << "\n\n";

    // Försöker ta bort 5 förekomster
    book.removeCopies(5);

    // Skriver ut informationen igen
    std::cout << "\nAfter Attempting to Remove 5 Copies:\n"
              << book.getBookInfo() << "\n\n";

    // Tar bort 2 förekomster
    book.removeCopies(2);

    // Skriver ut informationen igen
    std::cout << "\nAfter Removing 2 Copies:\n"
              << book.getBookInfo() << std::endl;

    return 0;
}
