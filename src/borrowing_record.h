#ifndef BORROWING_RECORD_H
#define BORROWING_RECORD_H

#include <string>
#include <ctime>
#include <iostream>

/**
 * @class BorrowingRecord
 * @brief 借閱記錄類 - 記錄每次的借閱交易
 * 
 * 記錄會員借閱書籍的詳細信息，包括借閱日期、
 * 應歸還日期、實際歸還日期等
 */
class BorrowingRecord {
public:
    /**
     * @brief BorrowingRecord構造函數
     * @param memberId 會員ID
     * @param bookISBN 書籍ISBN
     * @param borrowDate 借閱日期
     * @param dueDate 應歸還日期
     */
    BorrowingRecord(const std::string& memberId, const std::string& bookISBN,
                   time_t borrowDate, time_t dueDate);
    
    /**
     * @brief 虛析構函數
     */
    virtual ~BorrowingRecord() {}
    
    /**
     * @brief 顯示借閱記錄信息
     */
    void display() const;
    
    // Getter方法
    std::string getMemberId() const { return memberId; }
    std::string getBookISBN() const { return bookISBN; }
    time_t getBorrowDate() const { return borrowDate; }
    time_t getDueDate() const { return dueDate; }
    time_t getReturnDate() const { return returnDate; }
    bool isReturned() const { return returned; }
    int getOverdayDays() const { return overdayDays; }
    
    /**
     * @brief 歸還書籍
     * @param actualReturnDate 實際歸還日期
     */
    void returnBook(time_t actualReturnDate);
    
    /**
     * @brief 檢查是否逾期
     * @return 是否逾期
     */
    bool isOverdue() const;
    
    /**
     * @brief 計算罰款
     * @return 罰款金額（單位：元）
     */
    double calculateFine() const;
    
    /**
     * @brief 獲取狀態字符串
     * @return 狀態描述
     */
    std::string getStatus() const;
    
    /**
     * @brief 獲取天數差異
     * @return 借閱天數
     */
    int getDaysDiff(time_t start, time_t end) const;

private:
    std::string memberId;       ///< 會員ID
    std::string bookISBN;       ///< 書籍ISBN
    time_t borrowDate;          ///< 借閱日期
    time_t dueDate;             ///< 應歸還日期
    time_t returnDate;          ///< 實際歸還日期
    bool returned;              ///< 是否已歸還
    int overdayDays;            ///< 逾期天數
    double fine;                ///< 罰款金額
};

#endif // BORROWING_RECORD_H
