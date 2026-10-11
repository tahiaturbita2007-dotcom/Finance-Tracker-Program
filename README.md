# Finance-Tracker-Program
Welcome to our C program which creates the user's finance plan, tracks his/her daily expenditure and rewards with virtual coins for fulfilling savings' target, creating a game type environment just for fun. Let's introduce you all to the description of it....

# 💰 Finance Tracker in C

A comprehensive, interactive console-based personal finance management system written in pure **C**. This application helps users track monthly budgets, establish savings goals, allocate expenses across custom spending spheres, and monitor daily financial health through a gamified feedback system.

---

## 🚀 Key Features

* **Secure Authentication System:** Register a new account with your name, email, username, and password, or log into an existing account safely. Data is persistently stored using file handling.
* **Customized Budget Setup:** Tailor your financial plan by inputting your profession, monthly budget, savings target, and income source.
* **Sphere-Based Expense Tracking:** Define custom spending categories (spheres) and assign specific budget ranges for each.
* **Daily Discussion & Expense Logging:** Log your daily expenditures across different sectors, evaluate your daily budget fulfillment rate, and view real-time calculations.
* **Gamified Performance & Rewards:** Earn virtual coins (`*`) and motivational performance remarks based on how well you stick to your daily spending limits!
* **Persistent Storage:** Automatically saves user account databases (`acc.txt`) and personalized configuration files (`<username>_info.txt`).

---

## 🛠️ C Concepts & Tools Used

This project showcases several fundamental and intermediate concepts of the C programming language:

* **Structures (`struct`):** Used to cleanly organize complex data models for user authentication (`userlogin`, `create_acc`), profile configurations (`user_info`), and daily tracking metrics (`daily_report`).
* **File I/O Management:** Utilizes file pointers (`FILE *`), `fopen`, `fclose`, `fprintf`, `fscanf`, and `fgets` to read and write persistent data across sessions.
* **String Manipulation (`<string.h>`):** Employs functions like `strcpy`, `strcmp`, `strrchr`, and dynamic string formatting (`snprintf`) to handle user credentials and filenames safely.
* **Control Flow & Modular Programming:** Structured with a clean, modular function architecture (`dashboard`, `plan`, `discuss`, `queries`, `login`, `create_acc`) controlled via `switch-case` statements and `while` loops.
* **Standard Library Utilities:** Leverages `<stdlib.h>` for memory operations, string-to-integer conversions (`atoi`), and console control (`system("cls")`).

---

## 📂 Project Structure

```text
├── acc.txt                # Database storing registered user credentials
├── <username>_info.txt    # Individual user financial settings and sphere data
└── main.c                 # Source code containing all program logic

---

## ⚙️ How to Compile and Run

### Prerequisites

You need a C compiler installed on your system (such as **GCC**, **Clang**, or **MinGW** for Windows).

### Compilation & Execution

1. Clone the repository or download the source code file (`main.c`).
2. Open your terminal or command prompt in the project directory.
3. Compile the code using GCC:
```bash
gcc main.c -o finance_tracker

```


4. Run the executable:
* **On Windows:**
```cmd
finance_tracker.exe

```

* **On Linux / macOS:**
```bash
./finance_tracker

```
*(Note: The code uses `system("cls")`, which is optimized for Windows command prompt environments).*

---

## 🖥️ Navigation Flow

1. **Welcome Screen:** Choose to Log In (`1`), Register a new account (`2`), or Exit (`3`).
2. **Onboarding / Queries:** New users walk through an interactive setup to define their financial profile, monthly budget, savings goals, and spending spheres.
3. **Dashboard:** View your overall financial health, daily budget limits, and quick links to your daily plan or expense discussion.
4. **Daily Discussion:** Input your daily expenditures by sector to check your budget fulfillment rate and earn your daily reward coins!

---

## 👩‍💻 Author

Developed by **Safwath Jannat Labiba** and **Tahiat Tarannum Urbita**

*Undergraduate Students | Department of Computer Science and Engineering (CSE)*

*Rajshahi University of Engineering and Technology (RUET)*

```

```
