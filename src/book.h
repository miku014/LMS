#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

/**
 * @class Book
 * @brief 書籍類 - 定義圖書館中的書籍對象
 * 
 * 每本書包含ISBN、標題、作者、出版社、出版年份、
 * 分類、狀態等信息
 */
class Book {
public:
    /**
     * @brief Book構造函數
     * @param isbn 國際標準書號
     * @param title 書籍標題
     * @param author 作者
     * @param publisher 出版社
     * @param year 出版年份
     * @param category 分類
     * @param quantity 數量
     */
    Book(const std::string& isbn, const std::string& title,
         const std::string& author, const std::string& publisher,
         int year, const std::string& category, int quantity = 1);
    
    /**
     * @brief 虛析構函數
     */
    virtual ~Book() {}
    
    /**
     * @brief 顯示書籍信息
     */
    void display() const;
    
    // Getter方法
    std::string getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getPublisher() const { return publisher; }
    int getYear() const { return year; }
    std::string getCategory() const { return category; }
    int getTotalQuantity() const { return totalQuantity; }
    int getAvailableQuantity() const { return availableQuantity; }
    int getBorrowedQuantity() const { return totalQuantity - availableQuantity; }
    std::string getStatus() const { return availableQuantity > 0 ? "Available" : "Borrowed"; }
    
    // Setter方法
    void setTitle(const std::string& t) { title = t; }
    void setAuthor(const std::string& a) { author = a; }
    void setPublisher(const std::string& p) { publisher = p; }
    void setCategory(const std::string& c) { category = c; }
    
    /**
     * @brief 借出一本書
     * @return 是否成功借出
     */
    bool borrow();
    
    /**
     * @brief 歸還一本書
     * @return 是否成功歸還
     */
    bool returnBook();
    
    /**
     * @brief 檢查是否可借
     * @return 是否有可用的書籍
     */
    bool isAvailable() const { return availableQuantity > 0; }
    
    /**
     * @brief 獲取借閱率百分比
     * @return 借出書籍的百分比
     */
    double getBorrowPercentage() const;
    
    /**
     * @brief 增加書籍數量
     * @param count 增加的數量
     */
    void addQuantity(int count);
    
    /**
     * @brief 移除書籍
     * @param count 移除的數量
     * @return 是否成功移除
     */
    bool removeQuantity(int count);

private:
    std::string isbn;           ///< 國際標準書號
    std::string title;          ///< 書籍標題
    std::string author;         ///< 作者
    std::string publisher;      ///< 出版社
    int year;                   ///< 出版年份
    std::string category;       ///< 分類
    int totalQuantity;          ///< 總數量
    int availableQuantity;      ///< 可借閱數量
};

#endif // BOOK_H
