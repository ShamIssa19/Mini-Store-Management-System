# 🛒 Mini Store Management System (C++)

A modular C++ console application designed to manage store products, inventory levels, sales operations, and system analytics using parallel dynamic arrays.

## 🌟 Key Features

- **Product Management**: Add, update, search, and view all items in stock with safe input validations.
- **Sales Transactions**: Process customer purchases with real-time stock reduction and inventory validation.
- **Analytics & Statistics**:
  - Calculate total inventory valuation.
  - Track total available stock units.
  - Identify the **Most Expensive Product** and items with the **Lowest Stock**.
- **Sorting Logic**: Built-in **Selection Sort** algorithm to sort products by price from highest to lowest.

## 🛠️ Technical Details

- **Language**: C++
- **Core Concepts**: Parallel Arrays (`ids`, `names`, `prices`, `quantities`, `categories`), Modular Functions, $O(N^2)$ Selection Sort, Index Bounds Checking, `const` Parameter Safety.

## 🚀 How to Run

1. Clone or download the code.
2. Compile the `main.cpp` file using any C++ compiler (Visual Studio, Code::Blocks, GCC):
   ```bash
   g++ main.cpp -o store_app
