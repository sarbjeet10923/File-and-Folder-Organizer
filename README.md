# File and Folder Organizer (C++)

A simple command-line C++17 project that organizes files in a selected folder into categories based on their file extensions.

## Features

- Creates five folders: `Images`, `Documents`, `Videos`, `Music`, and `Others`.
- Detects common file extensions without case sensitivity.
- Moves files into the matching category.
- Skips a file if a file with the same name already exists in the destination.
- Reports the number of files moved and displays filesystem errors.

## Requirements

- A C++17-compatible compiler (GCC 8+, Clang 7+, or a recent MSVC).
- Permission to read and modify the folder being organized.

## Compile and run

### Windows (MinGW-w64)

Open PowerShell or Command Prompt in this project folder:

```powershell
g++ -std=c++17 -Wall -Wextra -o organizer main.cpp
.\organizer.exe
```

### Linux / macOS

```bash
g++ -std=c++17 -Wall -Wextra -o organizer main.cpp
./organizer
```

When prompted, enter the path to an existing folder, for example:

```text
C:\Users\YourName\Desktop\Test
```

Create the test folder and add a few sample files before running.

## File categories

| Category | Example extensions |
|---|---|
| Images | .jpg, .jpeg, .png, .gif, .bmp, .webp |
| Documents | .pdf, .doc, .docx, .txt, .ppt, .pptx, .xls, .xlsx, .csv |
| Videos | .mp4, .mkv, .avi, .mov, .wmv |
| Music | .mp3, .wav, .aac, .flac, .ogg |
| Others | Any other extension |

## Important note

This program physically moves files. Test it first on a temporary folder containing copies of sample files, not on important folders. Online compilers generally run in a restricted cloud environment and cannot access folders on your personal computer.

## Project structure

```text
File-and-Folder-Organizer/
├── main.cpp
├── README.md
└── .gitignore
```

## License

This project is provided for educational use.
