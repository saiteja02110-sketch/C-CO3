#include <iostream>
#include <string>
#include <stdexcept>
class Book {
    std::string title;
    int copies;
    static int checked(int n) { if (n < 0) throw std::invalid_argument("copies cannot be negative"); return n; }
public:
    Book() : Book("", 0) {}
    explicit Book(std::string t) : Book(std::move(t), 1) {}
    Book(std::string t, int n) : title(std::move(t)), copies(checked(n)) {}
    void print() const { std::cout << "Title: " << (title.empty() ? "(empty)" : title) << ", copies: " << copies << '\n'; }
};
int main() {
    Book empty;
    Book donated("Clean Code");
    Book full("C++ Primer", 5);
    empty.print(); donated.print(); full.print();
    try { Book invalid("Bad record", -2); invalid.print(); }
    catch (const std::invalid_argument& e) { std::cout << "Rejected: " << e.what() << '\n'; }
}