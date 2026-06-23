# 圖書館管理系統 (Library Management System)

## 📚 項目介紹

這是一個使用C++開發的**圖書館管理系統**，實現了完整的圖書借閱管理功能。系統展示了現代C++的核心特性，包括物件導向設計、文件操作、標準模板庫（STL）應用，以及完整的終端用戶界面。

## ✨ 核心特性

### 1. 類別繼承 (Object-Oriented Design)
- **Person基類**：定義人員的基本屬性
  - Librarian（圖書館員）派生類
  - Member（會員）派生類
- 虛函數實現多態性
- 純虛函數定義接口

### 2. 文件操作 (File I/O)
- 自定義`FileManager`類管理數據持久化
- 支持讀寫操作：
  - `books.txt` - 書籍信息
  - `members.txt` - 會員信息
  - `borrowing_records.txt` - 借閱記錄
  - `librarians.txt` - 圖書館員信息

### 3. STL 應用 (Standard Template Library)
- `std::vector<>` - 動態集合
- `std::map<>` - 鍵值對映射
- `std::string` - 字符串處理
- `std::fstream` - 文件流操作
- `std::find()`, `std::sort()` - 算法

### 4. 終端UI (Terminal UI)
- 菜單驅動的命令行界面
- 實時數據展示（表格格式）
- 交互式用戶輸入驗證
- 清屏和格式化輸出

### 5. 完整文檔
- 設計規格說明書
- 開發迭代流程文檔
- API參考手冊
- 使用指南

## 🏗️ 系統架構

```
┌─────────────────────────────────────────┐
│          Main UI Interface              │
│       (菜單系統 & 終端操作)              │
└─────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────┐
│      Library Management System          │
│    (圖書館系統核心業務邏輯)              │
└─────────────────────────────────────────┘
         ↙      ↓      ↙      ↓
    ┌────────┐ ┌────────┐ ┌──────────┐
    │ Book   │ │ Person │ │ Borrow   │
    │ Class  │ │ Class  │ │ Record   │
    └────────┘ └────────┘ └──────────┘
         ↙              ↓
    ┌─────────────────────────────────┐
    │   Librarian   │   Member        │
    │   (派生類)    │   (派生類)      │
    └─────────────────────────────────┘
              ↓
┌─────────────────────────────────────┐
│       FileManager                   │
│   (文件讀寫操作)                     │
└─────────────────────────────────────┘
         ↓      ↓      ↓
    ┌────────────────────────┐
    │   Data Files (JSON)    │
    │ • books.txt            │
    │ • members.txt          │
    │ • borrowing_records.txt│
    └────────────────────────┘
```

## 📋 功能清單

### 管理員功能
- ✅ 添加/刪除書籍
- ✅ 查看所有書籍
- ✅ 搜索書籍
- ✅ 查看借閱記錄
- ✅ 管理會員

### 會員功能
- ✅ 查看可借閱書籍
- ✅ 借閱書籍
- ✅ 歸還書籍
- ✅ 查看個人借閱記錄
- ✅ 搜索書籍

### 系統功能
- ✅ 數據自動保存到文件
- ✅ 程序啟動時自動載入數據
- ✅ 借閱期限管理
- ✅ 逾期提醒
- ✅ 圖書狀態追蹤

## 🚀 快速開始

### 編譯
```bash
cd LMS
make clean
make
```

### 運行
```bash
./library_system
```

### 菜單導航
```
╔════════════════════════════════════╗
║   圖書館管理系統 - 主菜單          ║
╠════════════════════════════════════╣
║  1. 圖書館員登錄                    ║
║  2. 會員登錄                        ║
║  3. 查看系統信息                    ║
║  0. 退出系統                        ║
╚════════════════════════════════════╝
```

## 📂 文件結構

```
LMS/
├── src/
│   ├── person.h              # 人員基類（虛函數）
│   ├── librarian.h/cpp       # 圖書館員派生類
│   ├── member.h/cpp          # 會員派生類
│   ├── book.h/cpp            # 書籍類
│   ├── borrowing_record.h/cpp# 借閱記錄類
│   ├── library.h/cpp         # 圖書館系統主類
│   ├── filemanager.h/cpp     # 文件管理器
│   ├── ui.h/cpp              # UI界面管理
│   └── main.cpp              # 主程序
├── data/
│   ├── books.txt             # 書籍數據
│   ├── members.txt           # 會員數據
│   ├── librarians.txt        # 圖書館員數據
│   └── borrowing_records.txt # 借閱記錄
├── docs/
│   ├── README.md             # 本文件
│   ├── DESIGN_SPEC.md        # 詳細設計規格
│   ├── DEVELOPMENT.md        # 開發流程文檔
│   └── CLASS_DIAGRAM.md      # 類別設計圖
├── Makefile                  # 編譯配置
└── .gitignore
```

## 🛠️ 技術棧

| 技術 | 用途 |
|------|------|
| **C++11/14** | 編程語言 |
| **STL** | 標準模板庫（vector, map, string等） |
| **面向對象** | 類別繼承、多態、封裝 |
| **文件操作** | fstream, ifstream, ofstream |
| **終端UI** | ANSI轉義碼、格式化輸出 |

## 📖 完整文檔

詳細內容請參考：
- [DESIGN_SPEC.md](docs/DESIGN_SPEC.md) - 系統設計規格
- [DEVELOPMENT.md](docs/DEVELOPMENT.md) - 開發迭代流程
- [CLASS_DIAGRAM.md](docs/CLASS_DIAGRAM.md) - 類別設計圖

## 👥 系統用戶角色

### 圖書館員 (Librarian)
- 完全的系統管理權限
- 可添加/刪除書籍
- 查看所有借閱記錄
- 管理會員賬戶

### 會員 (Member)
- 有限的系統訪問權限
- 只能借閱書籍
- 查看個人記錄
- 搜索書籍

## 📊 數據模型

### Person（基類）
```cpp
class Person {
  protected:
    std::string id;
    std::string name;
    std::string email;
  public:
    virtual ~Person() {}
    virtual void display() = 0;
};
```

### Book
```cpp
class Book {
  private:
    std::string isbn;
    std::string title;
    std::string author;
    std::string status;  // "available" or "borrowed"
};
```

### BorrowingRecord
```cpp
class BorrowingRecord {
  private:
    std::string memberId;
    std::string bookISBN;
    std::string borrowDate;
    std::string returnDate;
    bool isReturned;
};
```

## 🔄 開發迭代

### Phase 1: 基礎架構
- ✅ 設計類別結構
- ✅ 實現繼承和多態

### Phase 2: 核心功能
- ✅ 書籍管理
- ✅ 會員管理
- ✅ 借閱系統

### Phase 3: 文件操作
- ✅ 數據持久化
- ✅ 數據加載

### Phase 4: UI/UX
- ✅ 終端界面
- ✅ 用戶交互

### Phase 5: 測試與文檔
- ✅ 系統測試
- ✅ 文檔完善

## 💡 學習價值

此項目涵蓋了期末專題的所有要求：

1. **C++類別繼承** ✅
   - 虛基類、虛函數、多態

2. **文件讀寫** ✅
   - 自定義FileManager類
   - 標準流操作

3. **STL應用** ✅
   - 容器：vector, map, string
   - 算法：find, sort, for_each

4. **終端UI** ✅
   - 菜單系統
   - 數據展示表格
   - 輸入驗證

5. **完整文檔** ✅
   - 設計規格書
   - 開發流程
   - API手冊
   - 使用指南

## 🎓 學習收穫

通過完成此項目，學生將學到：
- 🎯 實際的物件導向設計方法
- 🎯 C++標準庫的應用
- 🎯 文件操作和數據持久化
- 🎯 用戶界面設計原則
- 🎯 代碼組織和文檔編寫
- 🎯 調試和測試技巧

## 📝 授權

MIT License - 自由使用和修改

## 👨‍💻 開發者

開發於 2026年6月
C++ 期末專題項目

---

**開始使用**: 執行 `make` 編譯，然後運行 `./library_system`
