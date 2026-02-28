#include "../include/file_handler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Private function declarations */
static int parse_date(const char* token, Date* date);
static int parse_address(const char* postal, const char* country, 
                         	const char* region, const char* district,
                         	const char* city, const char* street,
                         	const char* house, const char* apartment,
                        	Address* addr);

/* Parse date from string tokens */
static int parse_date(const char* token, Date* date)
{
	int year, month, day;
    	if (sscanf(token, "%d-%d-%d", &year, &month, &day) == 3) {
        	date->year = year;
        	date->month = month;
        	date->day = day;
        	return 1;
    	}
    	return 0;
}

/* Parse address from string tokens */
static int parse_address(const char* postal, const char* country,
      			const char* region, const char* district,
              		const char* city, const char* street,
                 	const char* house, const char* apartment,
                     	Address* addr)
{
	addr->postal_code = atoi(postal);
    	strncpy(addr->country, country, MAX_COUNTRY_LEN - 1);
    	addr->country[MAX_COUNTRY_LEN - 1] = '\0';
    	strncpy(addr->region, region, MAX_REGION_LEN - 1);
    	addr->region[MAX_REGION_LEN - 1] = '\0';
    	strncpy(addr->district, district, MAX_DISTRICT_LEN - 1);
    	addr->district[MAX_DISTRICT_LEN - 1] = '\0';
    	strncpy(addr->city, city, MAX_CITY_LEN - 1);
    	addr->city[MAX_CITY_LEN - 1] = '\0';
    	strncpy(addr->street, street, MAX_STREET_LEN - 1);
    	addr->street[MAX_STREET_LEN - 1] = '\0';
    	addr->house = atoi(house);
    	addr->apartment = atoi(apartment);
    
    	return 1;
}

/* Read students from file */
int read_students_from_file(const char* filename, Student* students, int max_students)
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        return -1;
    }
    
    int count = 0;
    char line[1024];
    
    while (count < max_students && fgets(line, sizeof(line), file)) {
        /* Remove newline */
        line[strcspn(line, "\n")] = 0;
        
        Student* s = &students[count];
        
        /* Initialize all fields to zero */
        memset(s, 0, sizeof(Student));
        
        /* Parse the line using strtok instead of sscanf for better control */
        char *token;
        int field_num = 0;
        
        token = strtok(line, " ");
        while (token != NULL) {
            switch(field_num) {
                case 0: strncpy(s->last_name, token, MAX_NAME_LEN - 1); break;
                case 1: strncpy(s->first_name, token, MAX_NAME_LEN - 1); break;
                case 2: strncpy(s->patronymic, token, MAX_NAME_LEN - 1); break;
                case 3: s->gender = token[0]; break;
                case 4: strncpy(s->nationality, token, MAX_NATIONALITY_LEN - 1); break;
                case 5: s->height = atoi(token); break;
                case 6: s->weight = atoi(token); break;
                case 7: /* Date - parse separately */
                {
                    int y, m, d;
                    if (sscanf(token, "%d-%d-%d", &y, &m, &d) == 3) {
                        s->birthday.year = y;
                        s->birthday.month = m;
                        s->birthday.day = d;
                    }
                    break;
                }
                case 8: strncpy(s->phone, token, MAX_PHONE_LEN - 1); break;
                case 9: s->address.postal_code = atoi(token); break;
                case 10: strncpy(s->address.country, token, MAX_COUNTRY_LEN - 1); break;
                case 11: strncpy(s->address.region, token, MAX_REGION_LEN - 1); break;
                case 12: strncpy(s->address.district, token, MAX_DISTRICT_LEN - 1); break;
                case 13: strncpy(s->address.city, token, MAX_CITY_LEN - 1); break;
                case 14: strncpy(s->address.street, token, MAX_STREET_LEN - 1); break;
                case 15: s->address.house = atoi(token); break;
                case 16: s->address.apartment = atoi(token); break;
                case 17: strncpy(s->school, token, MAX_SCHOOL_LEN - 1); break;
                case 18: s->class = atoi(token); break;
            }
            field_num++;
            token = strtok(NULL, " ");
        }
        
        if (field_num >= 19) {
            count++;
        }
    }
    
    fclose(file);
    return count;
}

/* Write fifth grade students to file */
int write_fifth_grade_students(const char* filename, const Student* students, int count)
{
    	FILE* file = fopen(filename, "w");
    	if (!file) {
        	return 0;
    	}
    
    	fprintf(file, "Fifth Grade Students Report\n");
    	fprintf(file, "===========================\n\n");
    
    	int fifth_count = 0;
    	for (int i = 0; i < count; i++) {
        	if (is_fifth_grade(&students[i])) {
            		char buffer[1024];
            		student_to_string(&students[i], buffer, sizeof(buffer));
           	 	fprintf(file, "%s\n", buffer);
           	 	fifth_count++;
        	}
    	}
    
    	fprintf(file, "\nTotal fifth grade students: %d\n", fifth_count);
    	fclose(file);
    	return 1;
}

/* Write all students to file */
int write_all_students(const char* filename, const Student* students, int count)
{
    	FILE* file = fopen(filename, "w");
    	if (!file) {
        	return 0;
    	}
    
    	fprintf(file, "All Students Report\n");
    	fprintf(file, "===================\n\n");
    
   	for (int i = 0; i < count; i++) {
        	char buffer[1024];
        	student_to_string(&students[i], buffer, sizeof(buffer));
        	fprintf(file, "%s\n", buffer);
    	}
    
    	fprintf(file, "\nTotal students: %d\n", count);
    	fclose(file);
    	return 1;
}
