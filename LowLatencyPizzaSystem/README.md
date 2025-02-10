# 🍕 Low Latency Digital Restaurant - Pizza Order System

🚀 A high-performance, low-latency restaurant ordering system built with **C++20**, designed for speed and scalability.

## 📌 Key Features

- ✅ **Fast Order Processing** using modern **C++20 threading** (`std::jthread`, `std::condition_variable`).
- ✅ **Concurrency Optimization** with **fine-grained locking** to prevent race conditions.
- ✅ **Thread-Safe Logging & Exception Handling**.

## ⚡ Technologies Used

- **C++20** (`std::jthread`, `std::condition_variable`, `std::mutex`)
- **Multithreading & Synchronization**
- **Design Patterns:**  RAII**

## 🛠️ Installation & Execution

### 1️⃣ Clone the repository
```bash
git clone https://github.com/cpp.git
cd cpp
```
### 2️⃣ Compile with C++20  
```bash
g++-13 -o restaurant main.cpp -std=c++20 -pthread
```
### 3️⃣ Run the program  
```bash
./pizza 0.5 3 2000
```
regina M x2;

## 🏗 Project Structure  
📂 src  
 ├── ❌ Error       # Handles Exception
 
 ├── 🔥 Kitchen     # Manages cooking process with threads  
 ├── 🏠 Reception   # Handles Reception  
 ├── 📝 Parser      # Process and check inputs  


## ✨ Why This Project? 
This project showcases low-latency, high-performance system design with modern C++20 features, thread management, and scalable architecture—ideal for handling thousands of restaurant orders efficiently.
