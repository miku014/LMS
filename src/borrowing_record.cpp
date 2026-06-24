#include "borrowing_record.h"
#include <iostream>
#include <ctime>
#include <iomanip>

BorrowingRecord::BorrowingRecord(const std::string& memberId,
                               const std::string& bookISBN,
                               time_t borrowDate, time_t dueDate)
    : memberId(memberId), bookISBN(bookISBN),
      borrowDate(borrowDate), dueDate(dueDate),
      returnDate(0), returned(false), overdayDays(0), fine(0.0) {}

void BorrowingRecord::display() const {
    std::cout << "會員ID: " << memberId << " | "
              << "書籍ISBN: " << bookISBN << " | "
              << "狀態: " << getStatus();
    if (returned) {
        std::cout << " | 罰款: ¥" << std::fixed << std::setprecision(2) << fine << std::endl;
    } else {
        std::cout << std::endl;
    }
}

void BorrowingRecord::returnBook(time_t actualReturnDate) {
    returned = true;
    returnDate = actualReturnDate;
    
    // 計算超期天數
    if (actualReturnDate > dueDate) {
        overdayDays = getDaysDiff(dueDate, actualReturnDate);
        fine = overdayDays * 0.5; // 每天0.5元罰款
    }
}

bool BorrowingRecord::isOverdue() const {
    if (returned) return false;
    time_t now = time(nullptr);
    return now > dueDate;
}

double BorrowingRecord::calculateFine() const {
    if (!returned || overdayDays <= 0) return 0.0;
    return overdayDays * 0.5;
}

std::string BorrowingRecord::getStatus() const {
    if (returned) {
        if (overdayDays > 0) {
            return "已歸還(已超期)";
        } else {
            return "已歸還";
        }
    } else {
        if (isOverdue()) {
            return "已超期";
        } else {
            return "借閱中";
        }
    }
}

int BorrowingRecord::getDaysDiff(time_t start, time_t end) const {
    if (end < start) return 0;
    return (int)((end - start) / (24 * 3600));
}
