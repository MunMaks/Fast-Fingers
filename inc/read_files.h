#ifndef __READ_FILES_H__
#define __READ_FILES_H__

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1 << 10


char *read_file(const char* const filename);

FILE *open_file(const char *filename, const char *mode);

#endif
