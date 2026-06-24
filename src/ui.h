#ifndef UI_H
#define UI_H

#include "library.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

/**
 * @class UI
 * @brief 用戶界面類 - 管理所有的菜單和交互
 * 
 * 提供完整的終端UI，包括：
 * - 主菜單
 * - 圖書館員菜單
 * - 會員菜單
 * - 數據展示（表格格式）
 * - 用戶輸入驗證
 */
class UI {
public:
    /**
     * @brief UI構造函數
     * @param lib 指向Library對象的指針
     */
    explicit UI(Library* lib);
    
    /**
     * @brief UI析構函數
     */
    ~UI() {}
    
    /**
     * @brief 運行主程序
     */
    void run();
    
private:
    Library* library;  ///< 指向圖書館系統的指針
    Member* currentMember;     ///< 當前登錄的會員
    Librarian* currentLibrarian; ///< 當前登錄的館員
    
    // ==================== 主菜單 ====================
    
    /**
     * @brief 顯示主菜單
     */
    void showMainMenu();
    
    /**
     * @brief 處理主菜單選擇
     */
    void handleMainMenu();
    
    // ==================== 登錄菜單 ====================
    
    /**
     * @brief 會員登錄
     */
    void memberLogin();
    
    /**
     * @brief 圖書館員登錄
     */
    void librarianLogin();
    
    // ==================== 會員菜單 ====================
    
    /**
     * @brief 會員菜單
     */
    void showMemberMenu();
    
    /**
     * @brief 處理會員菜單選擇
     */
    void handleMemberMenu();
    
    /**
     * @brief 會員借閱書籍
     */
    void memberBorrowBook();
    
    /**
     * @brief 會員歸還書籍
     */
    void memberReturnBook();
    
    /**
     * @brief 會員查看借閱記錄
     */
    void memberViewRecords();
    
    /**
     * @brief 會員搜索書籍
     */
    void memberSearchBooks();
    
    /**
     * @brief 會員查看個人信息
     */
    void memberViewProfile();
    
    // ==================== 圖書館員菜單 ====================
    
    /**
     * @brief 圖書館員菜單
     */
    void showLibrarianMenu();
    
    /**
     * @brief 處理圖書館員菜單選擇
     */
    void handleLibrarianMenu();
    
    /**
     * @brief 館員添加書籍
     */
    void librarianAddBook();
    
    /**
     * @brief 館員刪除書籍
     */
    void librarianRemoveBook();
    
    /**
     * @brief 館員查看所有書籍
     */
    void librarianViewAllBooks();
    
    /**
     * @brief 館員管理會員
     */
    void librarianManageMembers();
    
    /**
     * @brief 館員查看借閱記錄
     */
    void librarianViewRecords();
    
    /**
     * @brief 館員查看逾期記錄
     */
    void librarianViewOverdueRecords();
    
    /**
     * @brief 館員查看系統統計
     */
    void librarianViewStatistics();
    
    // ==================== 顯示功能 ====================
    
    /**
     * @brief 顯示歡迎屏幕
     */
    void showWelcomeScreen();
    
    /**
     * @brief 清屏
     */
    void clearScreen();
    
    /**
     * @brief 暫停（等待用戶按鍵）
     */
    void pause();
    
    /**
     * @brief 顯示分隔線
     * @param length 分隔線長度
     */
    void printSeparator(int length = 80);
    
    /**
     * @brief 顯示所有書籍列表（表格格式）
     * @param bookList 書籍列表
     */
    void displayBooksTable(const std::vector<Book*>& bookList);
    
    /**
     * @brief 顯示所有書籍列表（完整版本）
     * @param bookList 書籍列表
     */
    void displayBooksTableFull(const std::vector<Book>& bookList);
    
    /**
     * @brief 顯示借閱記錄列表
     * @param records 記錄列表
     */
    void displayBorrowingRecords(const std::vector<BorrowingRecord*>& records);
    
    /**
     * @brief 顯示會員列表
     * @param memberList 會員列表
     */
    void displayMembers(const std::vector<Member>& memberList);
    
    // ==================== 輸入驗證 ====================
    
    /**
     * @brief 獲取整數輸入
     * @param prompt 提示信息
     * @return 輸入的整數
     */
    int getIntInput(const std::string& prompt);
    
    /**
     * @brief 獲取字符串輸入
     * @param prompt 提示信息
     * @return 輸入的字符串
     */
    std::string getStringInput(const std::string& prompt);
    
    /**
     * @brief 獲取隱藏輸入（密碼）
     * @param prompt 提示信息
     * @return 輸入的字符串
     */
    std::string getHiddenInput(const std::string& prompt);
    
    /**
     * @brief 確認是否繼續
     * @param prompt 提示信息
     * @return 用戶選擇
     */
    bool confirmAction(const std::string& prompt);
};

#endif // UI_H
