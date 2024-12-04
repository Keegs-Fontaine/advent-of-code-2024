#include <stdio.h>

#include "../globals/f_reader.h"

int main() {
    char* val = pzle("input.txt", 100);

    for (int i = 0; val[i]; i++) {
        printf("%c", val[i]);
    }

    return 0;
}
