#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "student.h"

/* Maximum number of students that can be stored */
#define MAX_STUDENTS 100

/* Function declarations */
int read_students_from_file(const char* filename, Student* students, int max_students);
int write_fifth_grade_students(const char* filename, const Student* students, int count);
int write_all_students(const char* filename, const Student* students, int count);

#endif
