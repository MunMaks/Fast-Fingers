#include "..\inc\read_files.h"


/**
 * @brief Open a file and return the file pointer
 */
FILE* open_file(const char* const filename, const char* const mode){
    FILE *fptr = NULL;
    if (!(fptr = fopen(filename, mode))){
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }
    return fptr;
}


/**
 * @brief Read a file and return the buffer as a string
 */
char *read_file(const char* const filename){
    FILE *fptr = open_file(filename, "r");
    long length = 0;
    char *buffer = NULL;
    if (!fptr){
        goto return_null;
    }

    fseek(fptr, 0, SEEK_END);
    length = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    buffer = malloc(length + 1);
    if (!buffer){
        fprintf(stderr, "Error allocating memory for buffer\n");
        goto close_file;
    }

    /* recopie le contenue d'un fichier */
    fread(buffer, sizeof(*buffer), length, fptr);
    fclose(fptr);
    buffer[length] = '\0';

    return buffer;

close_file:
    fclose(fptr);

return_null:
    return NULL;
}
