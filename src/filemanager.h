#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @class FileManager
 * @brief 文件管理器 - 負責所有的文件讀寫操作
 * 
 * 使用STL的fstream進行文件操作，支持：
 * - 讀取和寫入書籍信息
 * - 讀取和寫入會員信息
 * - 讀取和寫入圖書館員信息
 * - 讀取和寫入借閱記錄
 * 
 * 數據格式：使用簡單的分隔符格式（|分隔）
 */
class FileManager {
public:
    /**
     * @brief FileManager構造函數
     * @param dataDir 數據文件目錄路徑
     */
    explicit FileManager(const std::string& dataDir = "data");
    
    /**
     * @brief FileManager析構函數
     */
    ~FileManager() {}
    
    // ==================== 書籍文件操作 ====================
    
    /**
     * @brief 讀取所有書籍信息
     * @return 書籍數據行的向量
     */
    std::vector<std::string> readBooks();
    
    /**
     * @brief 寫入書籍信息
     * @param books 書籍數據行的向量
     * @return 是否成功
     */
    bool writeBooks(const std::vector<std::string>& books);
    
    /**
     * @brief 添加單本書籍
     * @param bookData 書籍數據行
     * @return 是否成功
     */
    bool addBook(const std::string& bookData);
    
    // ==================== 會員文件操作 ====================
    
    /**
     * @brief 讀取所有會員信息
     * @return 會員數據行的向量
     */
    std::vector<std::string> readMembers();
    
    /**
     * @brief 寫入會員信息
     * @param members 會員數據行的向量
     * @return 是否成功
     */
    bool writeMembers(const std::vector<std::string>& members);
    
    /**
     * @brief 添加單個會員
     * @param memberData 會員數據行
     * @return 是否成功
     */
    bool addMember(const std::string& memberData);
    
    // ==================== 圖書館員文件操作 ====================
    
    /**
     * @brief 讀取所有圖書館員信息
     * @return 圖書館員數據行的向量
     */
    std::vector<std::string> readLibrarians();
    
    /**
     * @brief 寫入圖書館員信息
     * @param librarians 圖書館員數據行的向量
     * @return 是否成功
     */
    bool writeLibrarians(const std::vector<std::string>& librarians);
    
    /**
     * @brief 添加單個圖書館員
     * @param librarianData 圖書館員數據行
     * @return 是否成功
     */
    bool addLibrarian(const std::string& librarianData);
    
    // ==================== 借閱記錄文件操作 ====================
    
    /**
     * @brief 讀取所有借閱記錄
     * @return 借閱記錄數據行的向量
     */
    std::vector<std::string> readBorrowingRecords();
    
    /**
     * @brief 寫入借閱記錄
     * @param records 借閱記錄數據行的向量
     * @return 是否成功
     */
    bool writeBorrowingRecords(const std::vector<std::string>& records);
    
    /**
     * @brief 添加單條借閱記錄
     * @param recordData 借閱記錄數據行
     * @return 是否成功
     */
    bool addBorrowingRecord(const std::string& recordData);
    
    // ==================== 工具方法 ====================
    
    /**
     * @brief 檢查文件是否存在
     * @param filename 文件名
     * @return 文件是否存在
     */
    bool fileExists(const std::string& filename) const;
    
    /**
     * @brief 檢查並創建數據目錄
     * @return 是否成功
     */
    bool ensureDataDirectory();
    
    /**
     * @brief 初始化所有數據文件
     * 如果文件不存在則創建空文件
     * @return 是否成功
     */
    bool initializeDataFiles();
    
    /**
     * @brief 備份所有數據文件
     * @return 是否成功
     */
    bool backupDataFiles();
    
    /**
     * @brief 清空所有數據（用於測試）
     * @return 是否成功
     */
    bool clearAllData();

protected:
    /**
     * @brief 從檔案讀取所有行
     * @param filename 文件名
     * @return 文件所有行的向量
     */
    std::vector<std::string> readFile(const std::string& filename);
    
    /**
     * @brief 寫入所有行到檔案
     * @param filename 文件名
     * @param lines 要寫入的行向量
     * @return 是否成功
     */
    bool writeFile(const std::string& filename, const std::vector<std::string>& lines);
    
    /**
     * @brief 追加單行到檔案
     * @param filename 文件名
     * @param line 要追加的行
     * @return 是否成功
     */
    bool appendFile(const std::string& filename, const std::string& line);

private:
    std::string dataDir;         ///< 數據文件目錄
    std::string booksFile;       ///< 書籍文件路徑
    std::string membersFile;     ///< 會員文件路徑
    std::string librariansFile;  ///< 圖書館員文件路徑
    std::string recordsFile;     ///< 借閱記錄文件路徑
    
    /**
     * @brief 初始化文件路徑
     */
    void initializeFilePaths();
};

#endif // FILEMANAGER_H
