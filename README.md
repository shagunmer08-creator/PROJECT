# Personal Diary Application (C Project)

The Personal Diary Application is a menu-driven C program designed to help users record and manage diary entries in a digital format. It allows users to add, view, search, and delete saved entries. The program is developed using a modular programming approach, separating the logic into different `.c` and `.h` files for clarity and maintainability. File handling is used to store data permanently in `diary.txt`, ensuring that the information remains available even after the program is closed. The project has been implemented according to standard academic guidelines, including problem definition, system requirements, flowchart, implementation details, testing, sample output, and conclusion.

---

## Features

- Add new diary entries  
- View all saved entries  
- Search entries by date  
- Delete specific entries  
- Data stored permanently using file handling  
- Modular program structure using functions and header files  

---

## How the Program Works

When the program starts, a menu is displayed to the user. Based on the selected option, the program performs the corresponding operation:

- **Add Entry:** The user provides a date, title, and content. The program saves this information in the file.
- **View Entries:** The program reads and displays all entries saved in the file.
- **Search Entry:** The user enters a date, and the program retrieves matching entries.
- **Delete Entry:** The selected entry is removed by copying all non-matching records into a temporary file and replacing the original file.

All file operations are implemented using standard C functions such as `fopen`, `fclose`, `fprintf`, and `fread`.

---

## Technologies Used

| Component | Details |
|----------|---------|
| Programming Language | C |
| File Storage | Text file (`diary.txt`) |
| IDE Used | VS Code / CodeBlocks / Turbo C |
| Concepts Used | File handling, structures, functions, header files |

---

## Project Structure

Personal-Diary-Application
│
├── src
│ ├── main.c
│ ├── diary.c
│ └── diary.h
│
├── data
│ └── diary.txt
│
├── docs
│ └── Project Report.pdf
│
└── README.md
---

==== PERSONAL DIARY APPLICATION ====

Add New Entry

View Entries

Search Entry

Delete Entry

Exit

Enter your choice: 1
Enter Date: 27/11/2025
Enter Title: Birthday Party
Enter Content: It was an amazing day...
Entry added successfully.

