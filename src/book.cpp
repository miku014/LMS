#include "book.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Book::Book(const std::string& isbn, const std::string& title,
           const std::string& author, const std::string& publisher,
           int year, const std::string& category, int quantity)
    : isbn(isbn), title(title), author(author), publisher(publisher),
      year(year), category(category), totalQuantity(quantity),
      availableQuantity(quantity) {}

void Book::display() const {
    std::cout << std::left
              << std::setw(15) << isbn
              << std::setw(30) << title
              << std::setw(20) << author
              << std::setw(20) << publisher
              << std::setw(6) << year
              << std::setw(15) << category
              << std::setw(8) << totalQuantity
              << std::setw(8) << availableQuantity
              << std::setw(12) << getStatus()
              << std::endl;
}

bool Book::borrow() {
    if (availableQuantity > 0) {
        availableQuantity--;
        return true;
    }
    return false;
}

bool Book::returnBook() {
    if (availableQuantity < totalQuantity) {
        availableQuantity++;
        return true;
    }
    return false;
}

double Book::getBorrowPercentage() const {
    if (totalQuantity == 0) return 0.0;
    return (double)(totalQuantity - availableQuantity) / totalQuantity * 100.0;
}

void Book::addQuantity(int count) {
    if (count > 0) {
        totalQuantity += count;
        availableQuantity += count;
    }
}

bool Book::removeQuantity(int count) {
    if (count > 0 && count <= availableQuantity) {
        totalQuantity -= count;
        availableQuantity -= count;
        return true;
    }
    return false;
}
