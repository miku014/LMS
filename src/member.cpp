#include "member.h"
#include <iostream>
#include <ctime>

Member::Member(const std::string& id, const std::string& name,
               const std::string& email, const std::string& password,
               const std::string& phone, const std::string& membershipType)
    : Person(id, name, email), phone(phone), membershipType(membershipType),
      borrowedCount(0) {
    this->password = password;
    registrationDate = time(nullptr);
    
    // 根據會員類型設置最大借閱限制
    if (membershipType == "VIP") {
        maxBorrowLimit = 10;
    } else if (membershipType == "Student") {
        maxBorrowLimit = 3;
    } else { // Standard
        maxBorrowLimit = 5;
    }
}

void Member::display() const {
    std::cout << "\n=== 會員信息 ===" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "名稱: " << name << std::endl;
    std::cout << "郵箱: " << email << std::endl;
    std::cout << "電話: " << phone << std::endl;
    std::cout << "會員類型: " << getMembershipDescription() << std::endl;
    std::cout << "目前借閱書籍: " << borrowedCount << "/" << maxBorrowLimit << std::endl;
}

bool Member::verifyPassword(const std::string& pwd) const {
    return password == pwd;
}

std::string Member::getMembershipDescription() const {
    if (membershipType == "VIP") {
        return "VIP會員 (可借10本)";
    } else if (membershipType == "Student") {
        return "學生會員 (可借3本)";
    } else {
        return "普通會員 (可借5本)";
    }
}
