#include <stdio.h>
#include <stdlib.h>

// Yes I do inline functions in C. Sue me.
char* pzle(char* filename, int buffer_size, int line_count) {
    FILE* fptr;
    fptr = fopen(filename, "r");

    char str_buff[buffer_size];

    if (fptr == NULL) {
        char* err = "File Pointer Was Null! Does the file actually exist?";

        printf("%s", err);

        fclose(fptr);
        return err;
    } else {
        char* buff = malloc(line_count * buffer_size * sizeof(char));

        int i = 0;
        while (fgets(str_buff, buffer_size, fptr)) {
            for (int j = 0; str_buff[j]; j++) {
                buff[i] = str_buff[j];

                i++;
            }
        }

        return buff;

        fclose(fptr);
    }
}