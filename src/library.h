#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "member.h"
#include "librarian.h"
#include "borrowing_record.h"
#include "filemanager.h"
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <algorithm>

/**
 * @class Library
 * @brief 圖書館系統核心類 - 管理所有業務邏輯
 * 
 * 這是一個完整的圖書館管理系統核心，包含：
 * - 書籍管理（添加、刪除、查詢）
 * - 會員管理（註冊、刪除、查詢）
 * - 圖書館員管理
 * - 借閱業務（借出、歸還、查詢記錄）
 * - 數據持久化
 */
class Library {
public:
    /**
     * @brief Library構造函數
     * @param dataDir 數據文件目錄
     */
    explicit Library(const std::string& dataDir = "data");
    
    /**
     * @brief Library析構函數
     */
    ~Library() {}
    
    // ==================== 初始化和加載 ====================
    
    /**
     * @brief 初始化系統
     * @return 是否成功
     */
    bool initialize();
    
    /**
     * @brief 從文件加載所有數據
     * @return 是否成功
     */
    bool loadAllData();
    
    /**
     * @brief 保存所有數據到文件
     * @return 是否成功
     */
    bool saveAllData();
    
    // ==================== 書籍管理 ====================
    
    /**
     * @brief 添加新書籍
     * @param isbn 國際標準書號
     * @param title 書籍標題
     * @param author 作者
     * @param publisher 出版社
     * @param year 出版年份
     * @param category 分類
     * @param quantity 數量
     * @return 是否成功
     */
    bool addBook(const std::string& isbn, const std::string& title,
                const std::string& author, const std::string& publisher,
                int year, const std::string& category, int quantity = 1);
    
    /**
     * @brief 刪除書籍
     * @param isbn 要刪除的書籍ISBN
     * @return 是否成功
     */
    bool removeBook(const std::string& isbn);
    
    /**
     * @brief 查詢單本書籍
     * @param isbn 書籍ISBN
     * @return 指向Book對象的指針（nullptr表示未找到）
     */
    Book* findBookByISBN(const std::string& isbn);
    
    /**
     * @brief 按標題搜索書籍
     * @param title 書籍標題（支持模糊搜索）
     * @return 匹配的書籍列表
     */
    std::vector<Book*> searchBooksByTitle(const std::string& title);
    
    /**
     * @brief 按作者搜索書籍
     * @param author 作者名
     * @return 匹配的書籍列表
     */
    std::vector<Book*> searchBooksByAuthor(const std::string& author);
    
    /**
     * @brief 按分類搜索書籍
     * @param category 分類
     * @return 匹配的書籍列表
     */
    std::vector<Book*> searchBooksByCategory(const std::string& category);
    
    /**
     * @brief 獲取所有書籍
     * @return 所有書籍的列表
     */
    const std::vector<Book>& getAllBooks() const { return books; }
    
    /**
     * @brief 獲取可借閱的書籍
     * @return 可借閱書籍列表
     */
    std::vector<Book*> getAvailableBooks();
    
    // ==================== 會員管理 ====================
    
    /**
     * @brief 註冊新會員
     * @param id 會員ID
     * @param name 會員名稱
     * @param email 電郵
     * @param password 密碼
     * @param phone 電話
     * @param membershipType 會員類型
     * @return 是否成功
     */
    bool registerMember(const std::string& id, const std::string& name,
                       const std::string& email, const std::string& password,
                       const std::string& phone,
                       const std::string& membershipType = "Standard");
    
    /**
     * @brief 刪除會員
     * @param memberId 要刪除的會員ID
     * @return 是否成功
     */
    bool removeMember(const std::string& memberId);
    
    /**
     * @brief 查詢會員
     * @param memberId 會員ID
     * @return 指向Member對象的指針（nullptr表示未找到）
     */
    Member* findMember(const std::string& memberId);
    
    /**
     * @brief 會員登錄驗證
     * @param memberId 會員ID
     * @param password 密碼
     * @return 是否登錄成功
     */
    bool loginMember(const std::string& memberId, const std::string& password);
    
    /**
     * @brief 獲取所有會員
     * @return 所有會員的列表
     */
    const std::vector<Member>& getAllMembers() const { return members; }
    
    // ==================== 圖書館員管理 ====================
    
    /**
     * @brief 添加圖書館員
     * @param id 館員ID
     * @param name 館員名稱
     * @param email 電郵
     * @param password 密碼
     * @param department 部門
     * @param employeeLevel 等級
     * @return 是否成功
     */
    bool addLibrarian(const std::string& id, const std::string& name,
                     const std::string& email, const std::string& password,
                     const std::string& department, int employeeLevel = 1);
    
    /**
     * @brief 刪除圖書館員
     * @param librarianId 要刪除的館員ID
     * @return 是否成功
     */
    bool removeLibrarian(const std::string& librarianId);
    
    /**
     * @brief 查詢圖書館員
     * @param librarianId 館員ID
     * @return 指向Librarian對象的指針（nullptr表示未找到）
     */
    Librarian* findLibrarian(const std::string& librarianId);
    
    /**
     * @brief 圖書館員登錄驗證
     * @param librarianId 館員ID
     * @param password 密碼
     * @return 是否登錄成功
     */
    bool loginLibrarian(const std::string& librarianId, const std::string& password);
    
    /**
     * @brief 獲取所有圖書館員
     * @return 所有館員的列表
     */
    const std::vector<Librarian>& getAllLibrarians() const { return librarians; }
    
    // ==================== 借閱業務 ====================
    
    /**
     * @brief 借閱書籍
     * @param memberId 會員ID
     * @param isbn 書籍ISBN
     * @return 是否成功
     */
    bool borrowBook(const std::string& memberId, const std::string& isbn);
    
    /**
     * @brief 歸還書籍
     * @param memberId 會員ID
     * @param isbn 書籍ISBN
     * @return 是否成功
     */
    bool returnBook(const std::string& memberId, const std::string& isbn);
    
    /**
     * @brief 查詢會員的借閱記錄
     * @param memberId 會員ID
     * @return 該會員的所有借閱記錄
     */
    std::vector<BorrowingRecord*> getMemberBorrowingHistory(const std::string& memberId);
    
    /**
     * @brief 查詢特定書籍的借閱記錄
     * @param isbn 書籍ISBN
     * @return 該書籍的所有借閱記錄
     */
    std::vector<BorrowingRecord*> getBookBorrowingHistory(const std::string& isbn);
    
    /**
     * @brief 獲取所有借閱記錄
     * @return 所有借閱記錄的列表
     */
    const std::vector<BorrowingRecord>& getAllBorrowingRecords() const { return borrowingRecords; }
    
    /**
     * @brief 獲取逾期記錄
     * @return 所有逾期借閱的列表
     */
    std::vector<BorrowingRecord*> getOverdueRecords();
    
    // ==================== 統計信息 ====================
    
    /**
     * @brief 獲取系統統計信息
     * @return 統計信息字符串
     */
    std::string getSystemStatistics();
    
    /**
     * @brief 獲取書籍統計信息
     * @return 統計信息字符串
     */
    std::string getBookStatistics();
    
    /**
     * @brief 獲取會員統計信息
     * @return 統計信息字符串
     */
    std::string getMemberStatistics();

protected:
    /**
     * @brief 解析書籍數據行
     * @param line 數據行
     * @return 是否成功解析
     */
    bool parseBookLine(const std::string& line);
    
    /**
     * @brief 解析會員數據行
     * @param line 數據行
     * @return 是否成功解析
     */
    bool parseMemberLine(const std::string& line);
    
    /**
     * @brief 解析館員數據行
     * @param line 數據行
     * @return 是否成功解析
     */
    bool parseLibrarianLine(const std::string& line);
    
    /**
     * @brief 解析借閱記錄行
     * @param line 數據行
     * @return 是否成功解析
     */
    bool parseBorrowingRecordLine(const std::string& line);
    
    /**
     * @brief 序列化書籍為數據行
     * @param book 書籍對象
     * @return 數據行
     */
    std::string serializeBook(const Book& book) const;
    
    /**
     * @brief 序列化會員為數據行
     * @param member 會員對象
     * @return 數據行
     */
    std::string serializeMember(const Member& member) const;
    
    /**
     * @brief 序列化館員為數據行
     * @param librarian 館員對象
     * @return 數據行
     */
    std::string serializeLibrarian(const Librarian& librarian) const;
    
    /**
     * @brief 序列化借閱記錄為數據行
     * @param record 借閱記錄對象
     * @return 數據行
     */
    std::string serializeBorrowingRecord(const BorrowingRecord& record) const;

private:
    FileManager fileManager;              ///< 文件管理器
    std::vector<Book> books;              ///< 書籍集合
    std::vector<Member> members;          ///< 會員集合
    std::vector<Librarian> librarians;    ///< 館員集合
    std::vector<BorrowingRecord> borrowingRecords; ///< 借閱記錄集合
};

#endif // LIBRARY_H
