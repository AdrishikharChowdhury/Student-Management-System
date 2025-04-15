# 📚 Student Records Management System (C Project)

A simple yet functional **C-based student management system** for managing and maintaining student records using a **console-based interface** and **linked lists**.

---

## 🚀 Features

- ✅ Create single or multiple student records
- 🔍 View all or specific student details
- ✏️ Update individual fields (name, roll, DOB, etc.)
- ❌ Delete a student record by ID
- 💾 Save records to text files (auto-overwrites existing ones)
- 🆔 Generate unique student IDs using **djb2 hash**
- 🗃️ Store each record in a separate, readable `.txt` file
- 🧠 Sort records by name, roll number, or standard
- 🛡️ Input validation and duplication checks

---

## 📁 File Structure

| File               | Description                                             |
|--------------------|---------------------------------------------------------|
| `main.c`           | Main driver program                                     |
| `menu.c`           | User interface logic for menu navigation                |
| `create.c`         | Create and add new student records                      |
| `read.c`           | Display one or all student entries                      |
| `update.c`         | Update specific fields for a student                    |
| `delete.c`         | Delete a student record using ID                        |
| `id_generator.c`   | Generate unique student IDs using `djb2` hash function  |
| `save.c`           | Save student data to individual text files              |
| `student.h`        | Contains `struct Student` and function declarations     |

---

## 🧾 Sample Student File Output

File saved as:
```
student_<ID>.txt
```

Example content:
```
=========================
Student: 5d123abc
=========================
Name: John Doe
Standard: 10th
Section: A
Roll no. 21
Date of Birth: 01/01/2005
Phone number: 9876543210
```

---

## 🔐 Unique ID Generation

- Uses the **djb2 hashing algorithm** on the student’s name for consistent, collision-resistant IDs.
- Ensures each student has a unique file name (`student_<ID>.txt`).

---

## 🔁 Sorting Options

- By **Name** (alphabetical)
- By **Roll Number** (ascending)
- By **Standard** (ascending)

> Sorting is done in-place by swapping student data fields (not pointers), preserving list integrity.

---

## ⚙️ How to Compile and Run

### Using GCC:
```bash
gcc main.c menu.c create.c read.c delete.c id_generator.c update.c save.c -o student_manager
```

### Run the program:
```bash
./student_manager
```

✅ Works on **Linux, macOS, and Windows (via MinGW or WSL)**

---

## ✅ Requirements

- C compiler (GCC recommended)
- Terminal or Command Prompt

---

## 👨‍💻 Author

Developed by **Adrishikhar Chowdhury**  
Feel free to fork, extend, or contribute to the project!

---

## 📄 License

This project is open-source and available under the **MIT License**.  
Use it for learning, teaching, or improving student systems.
