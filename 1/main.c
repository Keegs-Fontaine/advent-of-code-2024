#include <stdio.h>
#include <stdlib.h>

#include "../globals/f_reader.h"

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}

int main() {
    int line_size = 5;
    int spaces_between_columns = 3;

    int buffer_size = line_size * 2 + spaces_between_columns + 1;
    int line_count = 1000;

    char* val = pzle("input.txt", buffer_size, line_count);

    int left_list[line_count];

    for (int j = 0; j < line_count; j++) {
        char line_str[line_size + 1];

        for (int i = 0; val[i] != ' '; i++) {
            line_str[i] = val[i + buffer_size * j];
        }

        left_list[j] = atoi(line_str);
    }

    int right_list[line_count];

    for (int j = 0; j < line_count; j++) {
        char line_str[line_size + 1];
        int x = 0;

        for (int i = 8; val[i] != '\n'; i++) {
            line_str[x] = val[i + buffer_size * j];

            x++;
        }

        right_list[j] = atoi(line_str);
    }

    // Literally everything above this is project setup (I'm bad at C)

    bubble_sort(right_list, line_count);
    bubble_sort(left_list, line_count);

    int sum = 0;
    for (int i = 0; i < line_count; i++) {
        int diff = right_list[i] - left_list[i];

        if (diff < 0) diff *= -1;

        sum += diff;
    }

    free(val);
    printf("Output: %d\n", sum);
    return 0;
}
