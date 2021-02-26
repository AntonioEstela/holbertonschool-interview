#ifndef SLIDE_LINE
#define SLIDE_LINE

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0

int slide_line(int *line, size_t size, int direction);
void to_left(int *line, size_t size);
void to_right(int *line, size_t size);

#endif /* SLIDE_LINE */
