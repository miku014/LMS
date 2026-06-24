#include "librarian.h"
#include <iostream>

Librarian::Librarian(const std::string& id, const std::string& name,
                     const std::string& email, const std::string& password,
                     const std::string& department, int employeeLevel)
    : Person(id, name, email), department(department), employeeLevel(employeeLevel) {
    this->password = password;
}

void Librarian::display() const {
    std::cout << "\n=== 圖書館員信息 ===" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "名稱: " << name << std::endl;
    std::cout << "郵箱: " << email << std::endl;
    std::cout << "部門: " << department << std::endl;
    std::cout << "等級: " << getLevelDescription() << std::endl;
}

bool Librarian::verifyPassword(const std::string& pwd) const {
    return password == pwd;
}

std::string Librarian::getLevelDescription() const {
    switch (employeeLevel) {
        case 1: return "1 (助理)";
        case 2: return "2 (初級)";
        case 3: return "3 (中級)";
        case 4: return "4 (高級)";
        case 5: return "5 (主管)";
        default: return "未知";
    }
}
