#include "filemanager.h"
#include <sys/stat.h>
#include <algorithm>
#include <ctime>

FileManager::FileManager(const std::string& dataDir) : dataDir(dataDir) {
    initializeFilePaths();
}

void FileManager::initializeFilePaths() {
    booksFile = dataDir + "/books.txt";
    membersFile = dataDir + "/members.txt";
    librariansFile = dataDir + "/librarians.txt";
    recordsFile = dataDir + "/borrowing_records.txt";
}

bool FileManager::ensureDataDirectory() {
    #ifdef _WIN32
        int status = mkdir(dataDir.c_str());
    #else
        int status = mkdir(dataDir.c_str(), 0755);
    #endif
    return status == 0 || fileExists(dataDir);
}

bool FileManager::fileExists(const std::string& filename) const {
    std::ifstream file(filename);
    return file.good();
}

bool FileManager::initializeDataFiles() {
    ensureDataDirectory();
    
    // 如果文件不存在，創建空文件
    if (!fileExists(booksFile)) {
        std::ofstream file(booksFile);
        file.close();
    }
    if (!fileExists(membersFile)) {
        std::ofstream file(membersFile);
        file.close();
    }
    if (!fileExists(librariansFile)) {
        std::ofstream file(librariansFile);
        file.close();
    }
    if (!fileExists(recordsFile)) {
        std::ofstream file(recordsFile);
        file.close();
    }
    return true;
}

std::vector<std::string> FileManager::readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        return lines;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

bool FileManager::writeFile(const std::string& filename,
                           const std::vector<std::string>& lines) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        return false;
    }
    
    for (const auto& line : lines) {
        file << line << std::endl;
    }
    file.close();
    return true;
}

bool FileManager::appendFile(const std::string& filename,
                            const std::string& line) {
    std::ofstream file(filename, std::ios::app);
    
    if (!file.is_open()) {
        return false;
    }
    
    file << line << std::endl;
    file.close();
    return true;
}

// ==================== 書籍文件操作 ====================

std::vector<std::string> FileManager::readBooks() {
    return readFile(booksFile);
}

bool FileManager::writeBooks(const std::vector<std::string>& books) {
    return writeFile(booksFile, books);
}

bool FileManager::addBook(const std::string& bookData) {
    return appendFile(booksFile, bookData);
}

// ==================== 會員文件操作 ====================

std::vector<std::string> FileManager::readMembers() {
    return readFile(membersFile);
}

bool FileManager::writeMembers(const std::vector<std::string>& members) {
    return writeFile(membersFile, members);
}

bool FileManager::addMember(const std::string& memberData) {
    return appendFile(membersFile, memberData);
}

// ==================== 圖書館員文件操作 ====================

std::vector<std::string> FileManager::readLibrarians() {
    return readFile(librariansFile);
}

bool FileManager::writeLibrarians(const std::vector<std::string>& librarians) {
    return writeFile(librariansFile, librarians);
}

bool FileManager::addLibrarian(const std::string& librarianData) {
    return appendFile(librariansFile, librarianData);
}

// ==================== 借閱記錄文件操作 ====================

std::vector<std::string> FileManager::readBorrowingRecords() {
    return readFile(recordsFile);
}

bool FileManager::writeBorrowingRecords(const std::vector<std::string>& records) {
    return writeFile(recordsFile, records);
}

bool FileManager::addBorrowingRecord(const std::string& recordData) {
    return appendFile(recordsFile, recordData);
}

// ==================== 工具方法 ====================

bool FileManager::backupDataFiles() {
    time_t now = time(nullptr);
    std::string timestamp = std::to_string(now);
    std::string backupDir = dataDir + "/backup_" + timestamp;
    
    #ifdef _WIN32
        std::string cmd = "mkdir " + backupDir;
    #else
        std::string cmd = "mkdir -p " + backupDir;
    #endif
    system(cmd.c_str());
    
    return true;
}

bool FileManager::clearAllData() {
    std::vector<std::string> empty;
    writeBooks(empty);
    writeMembers(empty);
    writeLibrarians(empty);
    writeBorrowingRecords(empty);
    return true;
}
