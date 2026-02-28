# Laboratory Work 2, Task 4

## Overview
A C program for managing student records with a focus on fifth-grade students. 
The program implements:
- Reading student data from a text file
- Processing and filtering students by grade (5th grade)
- Writing filtered results to an output file
- Modular architecture following the Client-Interface-Server model

## Author
Neyfeld Kirill
GitHub: cin-tie

## Usage

### Prerequisites
- GCC compiler
- Make utility
- Git

### Build and Run

1. Clone the repository:
```bash
git clone git@github.com:cin-tie/tpmp-lab2-task4.git
cd tpmp-lab2-task4
```

2. Build the program:
```bash
make all
```

3. Prepare input data:
   Create or place your input file in the `data` directory with student records.

4. Run the program:
```bash
make run
```
or directly:
```bash
./bin/student_program
```

5. Clean build files:
```bash
make clean
```

## File Structure

The project follows the Client-Interface-Server model:

- `src/` - Source files (*.c) - Server and Client implementations
- `include/` - Header files (*.h) - Interfaces
- `obj/` - Object files during compilation
- `bin/` - Executable files
- `data/` - Input and output data files
- `docs/` - Documentation and test reports

## Additional Notes

### Technical Details

- Maximum students: 100 (defined by `MAX_STUDENTS` constant)
- Maximum string length: 100 characters
- Date format: `YYYY MM DD`
- Programming language: C (C99 standard)
- Build system: Make with automatic dependency generation
- Architecture: Modular design with separate modules for:
  - Student data structure and operations
  - File I/O operations
  - Data processing (filtering by grade)
  - Main program logic

### Input File Format

The input file should contain student records in the following format:
```text
LastName FirstName Patronymic Gender Nationality Height Weight Year Month Day Phone Index Country Region District City Street House Apartment School Class
```

Each field is separated by whitespace.

### Output

The program generates a file containing only fifth-grade students with all their information preserved.

