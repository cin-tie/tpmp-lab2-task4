#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"
#include "../include/file_handler.h"
#include "../include/processor.h"

#define INPUT_FILE  "data/students.txt"
#define OUTPUT_FILE "data/fifth_grade_students.txt"
#define DEBUG_FILE  "data/all_students_debug.txt"

int main(void)
{
    Student all_students[MAX_STUDENTS];
    Student fifth_grade_students[MAX_STUDENTS];
    
    printf("Student Data Processing Program\n");
    printf("===============================\n\n");
    
    /* Read students from file */
    printf("Reading students from %s...\n", INPUT_FILE);
    int count = read_students_from_file(INPUT_FILE, all_students, MAX_STUDENTS);
    
    if (count <= 0) {
        printf("Error: Could not read students from file or file is empty.\n");
        return 1;
    }
    
    printf("Successfully read %d students.\n\n", count);
    
    /* Write all students to debug file */
    write_all_students(DEBUG_FILE, all_students, count);
    printf("All students written to %s for debugging.\n\n", DEBUG_FILE);
    
    /* Filter fifth grade students */
    printf("Filtering fifth grade students...\n");
    int fifth_count = filter_fifth_grade(all_students, count, 
                                         fifth_grade_students, MAX_STUDENTS);
    printf("Found %d fifth grade students.\n\n", fifth_count);
    
    /* Display fifth grade students */
    if (fifth_count > 0) {
        printf("Fifth Grade Students:\n");
        printf("---------------------\n");
        for (int i = 0; i < fifth_count; i++) {
            printf("\nStudent %d:\n", i + 1);
            print_student(&fifth_grade_students[i]);
        }
    }
    
    /* Write results to file */
    printf("\nWriting results to %s...\n", OUTPUT_FILE);
    if (write_fifth_grade_students(OUTPUT_FILE, all_students, count)) {
        printf("Successfully wrote fifth grade students to file.\n");
    } else {
        printf("Error: Could not write to output file.\n");
        return 1;
    }
    
    printf("\nProgram completed successfully.\n");
    return 0;
}
