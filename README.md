# 🎓 Student Management System in C++
A simple and interactive command-line based Student Management System written in C++ to demonstrate core concepts like classes, file handling, vectors, and user interaction.

# 📌 Features
• Add new students with name, roll number, and marks.
• Display all currently added students.
• Search for a student by name or roll number.
• Delete a student record by name or roll number.
• Save student data to a file (Student.txt) with overwrite warnings.
• Load data: 
• Directly display from file.
• Load data from file into memory (vector).
• Delete file contents or clear in-memory data separately.
• Track: 
• Total students ever created.
• Number of students currently in memory.

# 🛠️ Technologies Used
• C++
• Standard Template Library (STL) – for vector, ifstream, ofstream, etc.
• Basic file I/O operations and class-based design.

# 📂 Project Structure
├── main.cpp // Entry point of the application
├── Student.h // Student class declaration
├── Student.cpp // Student class definition 
├── Functions.h // Function declarations for operations 
├── Functions.cpp // Function definitions for core features ├── Student.txt // File used to persist data 

# ⚙️ How to Run
• Compile all .cpp files together:
g++ main.cpp Student.cpp Functions.cpp -o student_mgmt 
• Run the compiled program:
./student_mgmt 

# 💡 Notes
• The data in memory is temporary unless saved manually to the file.
• Saving to file overwrites previous data, so loading from file is advised beforehand.
• You can load from file directly into memory (vector) or just display it without affecting the current session.
• A count of total students (including deleted ones) is maintained using a static variable.

# 📬 Contact
Feel free to open issues or submit pull requests for improvements or suggestions!

