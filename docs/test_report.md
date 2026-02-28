# Laboratory Work Report

## Student Data Processing Program

### Test Results

#### Test 1: Basic Functionality
- **Input file**: `data/students.txt` with 5 records
- **Expected output**: Filter students with class = 5
- **Result**: Successfully filtered 3 fifth-grade students

#### Test 2: File Reading
- **Function tested**: `read_students_from_file()`
- **Result**: Successfully read all 5 records
- **Data integrity**: All fields parsed correctly

#### Test 3: Fifth Grade Filtering
- **Function tested**: `filter_fifth_grade()`
- **Input**: 5 students (2 in class 6, 3 in class 5)
- **Output**: 3 students correctly identified
- **Accuracy**: 100%

### Sample Output

``
Fifth Grade Students:

Ivanov Ivan Ivanovich (Class 5)
Sidorova Anna Sergeevna (Class 5)
Kuznetsova Maria Petrovna (Class 5)
``

### Conclusion
The program successfully processes student data and correctly identifies fifth-grade students. All functions work as expected.
