#include "../include/student.h"
#include <stdio.h>
#include <string.h>

/* Private function declarations */
static void format_date(const Date* d, char* buffer, int buffer_size);
static void format_address(const Address* a, char* buffer, int buffer_size);

// Format date to string
static void format_date(const Date* d, char* buffer, int buffer_size)
{
    	snprintf(buffer, buffer_size, "%04d-%02d-%02d", 
             	d->year, d->month, d->day);
}

// Format address to string 
static void format_address(const Address* a, char* buffer, int buffer_size)
{
    	snprintf(buffer, buffer_size, "%d, %s, %s, %s, %s, %s, %d/%d",
             	a->postal_code, a->country, a->region, a->district,
             	a->city, a->street, a->house, a->apartment);
}

// Print student information
void print_student(const Student* s)
{
    	char date_str[20];
    	char address_str[200];
    
    	format_date(&s->birthday, date_str, sizeof(date_str));
    	format_address(&s->address, address_str, sizeof(address_str));
    
    	printf("Student: %s %s %s\n", s->last_name, s->first_name, s->patronymic);
    	printf("  Gender: %c, Nationality: %s\n", s->gender, s->nationality);
    	printf("  Height: %d cm, Weight: %d kg\n", s->height, s->weight);
   	printf("  Birthday: %s\n", date_str);
    	printf("  Phone: %s\n", s->phone);
    	printf("  Address: %s\n", address_str);
    	printf("  School: %s, Class: %d\n", s->school, s->class);
}

int is_fifth_grade(const Student* s)
{
	return(s->class == 5)
}

// Convert student info to string
void student_to_string(const Student* s, char* buffer, int buffer_size)
{
    	char date_str[20];
    	char address_str[200];
    
    	format_date(&s->birthday, date_str, sizeof(date_str));
    	format_address(&s->address, address_str, sizeof(address_str));
    
    	snprintf(buffer, buffer_size,
             	"%s %s %s %c %s %d %d %s %s %s %s %s %s %s %d %d %s %d",
             	s->last_name, s->first_name, s->patronymic,
             	s->gender, s->nationality,
            	s->height, s->weight,
             	date_str,
             	s->phone,
             	address_str,
             	s->school, s->class);
}
