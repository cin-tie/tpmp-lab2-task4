#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

/* Constants for array sizes */
#define MAX_NAME_LEN 50
#define MAX_PATRONYMIC_LEN 50
#define MAX_NATIONALITY_LEN 30
#define MAX_PHONE_LEN 15
#define MAX_COUNTRY_LEN 30
#define MAX_REGION_LEN 30
#define MAX_DISTRICT_LEN 30
#define MAX_CITY_LEN 30
#define MAX_STREET_LEN 30
#define MAX_SCHOOL_LEN 30

/* Date structure for birthday */
typedef struct {
    	int year;
    	int month;
	int day;
} Date;

/* Address structure */
typedef struct {
    	int postal_code;
	char country[MAX_COUNTRY_LEN];
    	char region[MAX_REGION_LEN];
    	char district[MAX_DISTRICT_LEN];
    	char city[MAX_CITY_LEN];
    	char street[MAX_STREET_LEN];
    	int house;
   	int apartment;
} Address;

/* Main student structure */
typedef struct {
    char last_name[MAX_NAME_LEN];
    char first_name[MAX_NAME_LEN];
    char patronymic[MAX_PATRONYMIC_LEN];
    char gender;  /* 'M' or 'F' */
    char nationality[MAX_NATIONALITY_LEN];
    int height;   /* in cm */
    int weight;   /* in kg */
    Date birthday;
    char phone[MAX_PHONE_LEN];
    Address address;
    char school[MAX_SCHOOL_LEN];
    int class;
} Student;

/* Function declarations */
void print_student(const Student* s);
int is_fifth_grade(const Student* s);
void student_to_string(const Student* s, char* buffer, int buffer_size);

#endif
