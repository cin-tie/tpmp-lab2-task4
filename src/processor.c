#include "../include/processor.h"
#include <string.h>

/* Filter fifth grade students from source array */
int filter_fifth_grade(const Student* source, int source_count,
                       Student* destination, int max_destination)
{
   	int dest_count = 0;
    
    	for (int i = 0; i < source_count && dest_count < max_destination; i++) {
        	if (is_fifth_grade(&source[i])) {
            		/* Copy the student */
           		memcpy(&destination[dest_count], &source[i], sizeof(Student));
            		dest_count++;
        	}
    	}
    
    	return dest_count;
}
