#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "student.h"

/* Function declarations */
int filter_fifth_grade(const Student* source, int source_count, 
                       Student* destination, int max_destination);

#endif
