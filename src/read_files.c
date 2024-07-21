#include "../inc/read_files.h"

char *read_file(const char *filename){
    FILE *fptr = fopen(filename, "r");
    if (!fptr){
        fprintf(stderr, "Error opening file: %s\n", filename);
        goto return_null;
    }

    fseek(fptr, 0, SEEK_END);
    long length = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    if (!buffer){
        fprintf(stderr, "Error allocating memory for buffer\n");
        goto close_file;
    }

    fread(buffer, 1, length, fptr);
    fclose(fptr);
    buffer[length] = '\0';

    return buffer;

close_file:
    fclose(fptr);

return_null:
    return NULL;
}
