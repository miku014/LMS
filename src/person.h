#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

/**
 * @class Person
 * @brief 人員基類 - 定義圖書館員和會員的共同屬性
 * 
 * 使用虛函數實現多態性，展示C++類別繼承的核心概念
 * 這是一個抽象基類，不能直接實例化
 */
class Person {
public:
    /**
     * @brief Person構造函數
     * @param id 人員ID
     * @param name 人員名稱
     * @param email 人員郵箱
     */
    Person(const std::string& id, const std::string& name, const std::string& email)
        : id(id), name(name), email(email) {}
    
    /**
     * @brief 虛析構函數
     * 確保派生類的析構函數被正確調用
     */
    virtual ~Person() {}
    
    /**
     * @brief 純虛函數 - 顯示人員信息
     * 必須由派生類實現
     */
    virtual void display() const = 0;
    
    /**
     * @brief 純虛函數 - 獲取人員角色
     * @return 人員角色字符串
     */
    virtual std::string getRole() const = 0;
    
    // Getter方法
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    
    // Setter方法
    void setName(const std::string& n) { name = n; }
    void setEmail(const std::string& e) { email = e; }
    
    /**
     * @brief 檢查密碼是否正確
     * @param pwd 提供的密碼
     * @return 密碼是否正確
     */
    virtual bool verifyPassword(const std::string& pwd) const = 0;

protected:
    std::string id;       ///< 人員ID
    std::string name;     ///< 人員名稱
    std::string email;    ///< 人員郵箱
    std::string password; ///< 人員密碼
};

#endif // PERSON_H
