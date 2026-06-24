#ifndef MEMBER_H
#define MEMBER_H

#include "person.h"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>

/**
 * @class Member
 * @brief 會員派生類 - 繼承自Person
 * 
 * 會員是圖書館的普通用戶，可以：
 * - 借閱和歸還書籍
 * - 搜索書籍
 * - 查看個人借閱記錄
 * - 管理會員信息
 */
class Member : public Person {
public:
    /**
     * @brief Member構造函數
     * @param id 會員ID
     * @param name 會員名稱
     * @param email 會員郵箱
     * @param password 會員密碼
     * @param phone 會員電話
     * @param membershipType 會員類型
     */
    Member(const std::string& id, const std::string& name,
           const std::string& email, const std::string& password,
           const std::string& phone, const std::string& membershipType = "Standard");
    
    /**
     * @brief 虛析構函數
     */
    virtual ~Member() {}
    
    /**
     * @brief 顯示會員信息
     * 實現純虛函數display()
     */
    virtual void display() const override;
    
    /**
     * @brief 獲取角色
     * @return "Member"
     */
    virtual std::string getRole() const override { return "Member"; }
    
    /**
     * @brief 驗證密碼
     * @param pwd 提供的密碼
     * @return 密碼是否正確
     */
    virtual bool verifyPassword(const std::string& pwd) const override;
    
    // Getter方法
    std::string getPhone() const { return phone; }
    std::string getMembershipType() const { return membershipType; }
    time_t getRegistrationDate() const { return registrationDate; }
    int getBorrowedCount() const { return borrowedCount; }
    int getMaxBorrowLimit() const { return maxBorrowLimit; }
    
    // Setter方法
    void setPhone(const std::string& p) { phone = p; }
    void setMembershipType(const std::string& type) { membershipType = type; }
    
    /**
     * @brief 增加借閱計數
     */
    void addBorrowedBook() { borrowedCount++; }
    
    /**
     * @brief 減少借閱計數
     */
    void removeBorrowedBook() { if (borrowedCount > 0) borrowedCount--; }
    
    /**
     * @brief 檢查是否達到借閱上限
     * @return 是否可以繼續借閱
     */
    bool canBorrow() const { return borrowedCount < maxBorrowLimit; }
    
    /**
     * @brief 獲取會員類型描述
     * @return 類型描述字符串
     */
    std::string getMembershipDescription() const;

private:
    std::string phone;           ///< 會員電話
    std::string membershipType;  ///< 會員類型 (Standard, VIP, Student)
    time_t registrationDate;     ///< 註冊日期
    int borrowedCount;           ///< 目前借閱數量
    int maxBorrowLimit;          ///< 最大借閱限制
};

#endif // MEMBER_H
