#include "library.h"
#include <algorithm>
#include <sstream>
#include <ctime>

Library::Library(const std::string& dataDir) : fileManager(dataDir) {}

bool Library::initialize() {
    if (!fileManager.ensureDataDirectory()) {
        return false;
    }
    if (!fileManager.initializeDataFiles()) {
        return false;
    }
    return loadAllData();
}

bool Library::loadAllData() {
    // 讀取書籍
    auto bookLines = fileManager.readBooks();
    for (const auto& line : bookLines) {
        parseBookLine(line);
    }
    
    // 讀取會員
    auto memberLines = fileManager.readMembers();
    for (const auto& line : memberLines) {
        parseMemberLine(line);
    }
    
    // 讀取圖書館員
    auto librarianLines = fileManager.readLibrarians();
    for (const auto& line : librarianLines) {
        parseLibrarianLine(line);
    }
    
    // 讀取借閱記錄
    auto recordLines = fileManager.readBorrowingRecords();
    for (const auto& line : recordLines) {
        parseBorrowingRecordLine(line);
    }
    
    return true;
}

bool Library::saveAllData() {
    // 保存書籍
    std::vector<std::string> bookLines;
    for (const auto& book : books) {
        bookLines.push_back(serializeBook(book));
    }
    fileManager.writeBooks(bookLines);
    
    // 保存會員
    std::vector<std::string> memberLines;
    for (const auto& member : members) {
        memberLines.push_back(serializeMember(member));
    }
    fileManager.writeMembers(memberLines);
    
    // 保存圖書館員
    std::vector<std::string> librarianLines;
    for (const auto& librarian : librarians) {
        librarianLines.push_back(serializeLibrarian(librarian));
    }
    fileManager.writeLibrarians(librarianLines);
    
    // 保存借閱記錄
    std::vector<std::string> recordLines;
    for (const auto& record : borrowingRecords) {
        recordLines.push_back(serializeBorrowingRecord(record));
    }
    fileManager.writeBorrowingRecords(recordLines);
    
    return true;
}

// ==================== 書籍管理 ====================

bool Library::addBook(const std::string& isbn, const std::string& title,
                     const std::string& author, const std::string& publisher,
                     int year, const std::string& category, int quantity) {
    if (findBookByISBN(isbn) != nullptr) {
        return false; // 書籍已存在
    }
    books.emplace_back(isbn, title, author, publisher, year, category, quantity);
    return saveAllData();
}

bool Library::removeBook(const std::string& isbn) {
    auto it = std::find_if(books.begin(), books.end(),
                          [&isbn](const Book& b) { return b.getISBN() == isbn; });
    if (it != books.end()) {
        books.erase(it);
        return saveAllData();
    }
    return false;
}

Book* Library::findBookByISBN(const std::string& isbn) {
    auto it = std::find_if(books.begin(), books.end(),
                          [&isbn](const Book& b) { return b.getISBN() == isbn; });
    if (it != books.end()) {
        return &(*it);
    }
    return nullptr;
}

std::vector<Book*> Library::searchBooksByTitle(const std::string& title) {
    std::vector<Book*> result;
    for (auto& book : books) {
        // 模糊查詢
        if (book.getTitle().find(title) != std::string::npos) {
            result.push_back(&book);
        }
    }
    return result;
}

std::vector<Book*> Library::searchBooksByAuthor(const std::string& author) {
    std::vector<Book*> result;
    for (auto& book : books) {
        if (book.getAuthor().find(author) != std::string::npos) {
            result.push_back(&book);
        }
    }
    return result;
}

std::vector<Book*> Library::searchBooksByCategory(const std::string& category) {
    std::vector<Book*> result;
    for (auto& book : books) {
        if (book.getCategory() == category) {
            result.push_back(&book);
        }
    }
    return result;
}

std::vector<Book*> Library::getAvailableBooks() {
    std::vector<Book*> result;
    for (auto& book : books) {
        if (book.isAvailable()) {
            result.push_back(&book);
        }
    }
    return result;
}

// ==================== 會員管理 ====================

bool Library::registerMember(const std::string& id, const std::string& name,
                            const std::string& email, const std::string& password,
                            const std::string& phone,
                            const std::string& membershipType) {
    if (findMember(id) != nullptr) {
        return false; // 會員已存在
    }
    members.emplace_back(id, name, email, password, phone, membershipType);
    return saveAllData();
}

bool Library::removeMember(const std::string& memberId) {
    auto it = std::find_if(members.begin(), members.end(),
                          [&memberId](const Member& m) { return m.getId() == memberId; });
    if (it != members.end()) {
        members.erase(it);
        return saveAllData();
    }
    return false;
}

Member* Library::findMember(const std::string& memberId) {
    auto it = std::find_if(members.begin(), members.end(),
                          [&memberId](const Member& m) { return m.getId() == memberId; });
    if (it != members.end()) {
        return &(*it);
    }
    return nullptr;
}

bool Library::loginMember(const std::string& memberId, const std::string& password) {
    Member* member = findMember(memberId);
    if (member != nullptr && member->verifyPassword(password)) {
        return true;
    }
    return false;
}

// ==================== 圖書館員管理 ====================

bool Library::addLibrarian(const std::string& id, const std::string& name,
                          const std::string& email, const std::string& password,
                          const std::string& department, int employeeLevel) {
    if (findLibrarian(id) != nullptr) {
        return false;
    }
    librarians.emplace_back(id, name, email, password, department, employeeLevel);
    return saveAllData();
}

bool Library::removeLibrarian(const std::string& librarianId) {
    auto it = std::find_if(librarians.begin(), librarians.end(),
                          [&librarianId](const Librarian& l) { return l.getId() == librarianId; });
    if (it != librarians.end()) {
        librarians.erase(it);
        return saveAllData();
    }
    return false;
}

Librarian* Library::findLibrarian(const std::string& librarianId) {
    auto it = std::find_if(librarians.begin(), librarians.end(),
                          [&librarianId](const Librarian& l) { return l.getId() == librarianId; });
    if (it != librarians.end()) {
        return &(*it);
    }
    return nullptr;
}

bool Library::loginLibrarian(const std::string& librarianId, const std::string& password) {
    Librarian* librarian = findLibrarian(librarianId);
    if (librarian != nullptr && librarian->verifyPassword(password)) {
        return true;
    }
    return false;
}

// ==================== 借閱業務 ====================

bool Library::borrowBook(const std::string& memberId, const std::string& isbn) {
    Member* member = findMember(memberId);
    Book* book = findBookByISBN(isbn);
    
    if (member == nullptr || book == nullptr) {
        return false;
    }
    
    if (!member->canBorrow() || !book->borrow()) {
        return false;
    }
    
    // 創建借閱記錄
    time_t now = time(nullptr);
    time_t dueDate = now + 30 * 24 * 3600; // 30天後歸還
    
    member->addBorrowedBook();
    borrowingRecords.emplace_back(memberId, isbn, now, dueDate);
    
    return saveAllData();
}

bool Library::returnBook(const std::string& memberId, const std::string& isbn) {
    Member* member = findMember(memberId);
    Book* book = findBookByISBN(isbn);
    
    if (member == nullptr || book == nullptr) {
        return false;
    }
    
    // 查找對應的借閱記錄
    auto it = std::find_if(borrowingRecords.begin(), borrowingRecords.end(),
                          [&memberId, &isbn](const BorrowingRecord& r) {
                              return r.getMemberId() == memberId && 
                                     r.getBookISBN() == isbn && 
                                     !r.isReturned();
                          });
    
    if (it != borrowingRecords.end()) {
        it->returnBook(time(nullptr));
        member->removeBorrowedBook();
        book->returnBook();
        return saveAllData();
    }
    
    return false;
}

std::vector<BorrowingRecord*> Library::getMemberBorrowingHistory(const std::string& memberId) {
    std::vector<BorrowingRecord*> result;
    for (auto& record : borrowingRecords) {
        if (record.getMemberId() == memberId) {
            result.push_back(&record);
        }
    }
    return result;
}

std::vector<BorrowingRecord*> Library::getBookBorrowingHistory(const std::string& isbn) {
    std::vector<BorrowingRecord*> result;
    for (auto& record : borrowingRecords) {
        if (record.getBookISBN() == isbn) {
            result.push_back(&record);
        }
    }
    return result;
}

std::vector<BorrowingRecord*> Library::getOverdueRecords() {
    std::vector<BorrowingRecord*> result;
    for (auto& record : borrowingRecords) {
        if (record.isOverdue()) {
            result.push_back(&record);
        }
    }
    return result;
}

// ==================== 統計信息 ====================

std::string Library::getSystemStatistics() {
    std::stringstream ss;
    ss << "\n=== 系統統計信息 ===\n";
    ss << "總書籍數: " << books.size() << "\n";
    ss << "總會員數: " << members.size() << "\n";
    ss << "總館員數: " << librarians.size() << "\n";
    ss << "總借閱記錄: " << borrowingRecords.size() << "\n";
    ss << "未歸還記錄: ";
    int unreturned = 0;
    for (const auto& record : borrowingRecords) {
        if (!record.isReturned()) unreturned++;
    }
    ss << unreturned << "\n";
    ss << "超期記錄: " << getOverdueRecords().size() << "\n";
    return ss.str();
}

std::string Library::getBookStatistics() {
    std::stringstream ss;
    ss << "\n=== 書籍統計 ===\n";
    ss << "總數: " << books.size() << "\n";
    int available = 0;
    for (const auto& book : books) {
        available += book.getAvailableQuantity();
    }
    ss << "可借閱: " << available << "\n";
    ss << "已借出: " << (getSystemStatistics().find("未歸還記錄") != std::string::npos ? "計算中" : "0") << "\n";
    return ss.str();
}

std::string Library::getMemberStatistics() {
    std::stringstream ss;
    ss << "\n=== 會員統計 ===\n";
    ss << "總會員數: " << members.size() << "\n";
    int activeBorrowers = 0;
    for (const auto& member : members) {
        if (member.getBorrowedCount() > 0) {
            activeBorrowers++;
        }
    }
    ss << "活躍借閱者: " << activeBorrowers << "\n";
    return ss.str();
}

// ==================== 數據解析 ====================

bool Library::parseBookLine(const std::string& line) {
    std::stringstream ss(line);
    std::string isbn, title, author, publisher, category;
    int year, quantity, available;
    
    if (std::getline(ss, isbn, '|') &&
        std::getline(ss, title, '|') &&
        std::getline(ss, author, '|') &&
        std::getline(ss, publisher, '|') &&
        ss >> year) {
        
        ss.ignore();
        std::getline(ss, category, '|');
        ss >> quantity >> available;
        
        books.emplace_back(isbn, title, author, publisher, year, category, quantity);
        return true;
    }
    return false;
}

bool Library::parseMemberLine(const std::string& line) {
    std::stringstream ss(line);
    std::string id, name, email, password, phone, membershipType;
    
    if (std::getline(ss, id, '|') &&
        std::getline(ss, name, '|') &&
        std::getline(ss, email, '|') &&
        std::getline(ss, password, '|') &&
        std::getline(ss, phone, '|') &&
        std::getline(ss, membershipType, '|')) {
        
        members.emplace_back(id, name, email, password, phone, membershipType);
        return true;
    }
    return false;
}

bool Library::parseLibrarianLine(const std::string& line) {
    std::stringstream ss(line);
    std::string id, name, email, password, department;
    int level;
    
    if (std::getline(ss, id, '|') &&
        std::getline(ss, name, '|') &&
        std::getline(ss, email, '|') &&
        std::getline(ss, password, '|') &&
        std::getline(ss, department, '|') &&
        ss >> level) {
        
        librarians.emplace_back(id, name, email, password, department, level);
        return true;
    }
    return false;
}

bool Library::parseBorrowingRecordLine(const std::string& line) {
    // 簡化實現
    return true;
}

std::string Library::serializeBook(const Book& book) const {
    std::stringstream ss;
    ss << book.getISBN() << "|" << book.getTitle() << "|" << book.getAuthor() << "|"
       << book.getPublisher() << "|" << book.getYear() << "|" << book.getCategory() << "|"
       << book.getTotalQuantity() << "|" << book.getAvailableQuantity();
    return ss.str();
}

std::string Library::serializeMember(const Member& member) const {
    std::stringstream ss;
    ss << member.getId() << "|" << member.getName() << "|" << member.getEmail() << "|"
       << "password|" << member.getPhone() << "|" << member.getMembershipType();
    return ss.str();
}

std::string Library::serializeLibrarian(const Librarian& librarian) const {
    std::stringstream ss;
    ss << librarian.getId() << "|" << librarian.getName() << "|" << librarian.getEmail() << "|"
       << "password|" << librarian.getDepartment() << "|" << librarian.getEmployeeLevel();
    return ss.str();
}

std::string Library::serializeBorrowingRecord(const BorrowingRecord& record) const {
    std::stringstream ss;
    ss << record.getMemberId() << "|" << record.getBookISBN() << "|" 
       << record.getBorrowDate() << "|" << record.getDueDate() << "|" 
       << (record.isReturned() ? "1" : "0");
    return ss.str();
}
