#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "person.h"
#include <string>
#include <iostream>

/**
 * @class Librarian
 * @brief 圖書館員派生類 - 繼承自Person
 * 
 * 圖書館員具有系統的完全管理權限，可以：
 * - 添加和刪除書籍
 * - 管理會員賬戶
 * - 查看所有借閱記錄
 * - 生成報告
 */
class Librarian : public Person {
public:
    /**
     * @brief Librarian構造函數
     * @param id 圖書館員ID
     * @param name 圖書館員名稱
     * @param email 圖書館員郵箱
     * @param password 圖書館員密碼
     * @param department 所屬部門
     * @param employeeLevel 員工等級
     */
    Librarian(const std::string& id, const std::string& name, 
              const std::string& email, const std::string& password,
              const std::string& department, int employeeLevel = 1);
    
    /**
     * @brief 虛析構函數
     */
    virtual ~Librarian() {}
    
    /**
     * @brief 顯示圖書館員信息
     * 實現純虛函數display()
     */
    virtual void display() const override;
    
    /**
     * @brief 獲取角色
     * @return "Librarian"
     */
    virtual std::string getRole() const override { return "Librarian"; }
    
    /**
     * @brief 驗證密碼
     * @param pwd 提供的密碼
     * @return 密碼是否正確
     */
    virtual bool verifyPassword(const std::string& pwd) const override;
    
    // Getter方法
    std::string getDepartment() const { return department; }
    int getEmployeeLevel() const { return employeeLevel; }
    
    // Setter方法
    void setDepartment(const std::string& dept) { department = dept; }
    void setEmployeeLevel(int level) { employeeLevel = level; }
    
    /**
     * @brief 獲取權限等級描述
     * @return 等級描述字符串
     */
    std::string getLevelDescription() const;

private:
    std::string department;  ///< 所屬部門
    int employeeLevel;       ///< 員工等級 (1-5)
};

#endif // LIBRARIAN_H
