#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);



/*
 * Complete the 'canPlaceSecurityCameras' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. 2D_INTEGER_ARRAY grid
 */


bool backtrack(int row, int N, int** grid, bool* cols, bool* diag1, bool* diag2) {
    if (row == N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (grid[row][col] == 1 || cols[col] || diag1[row - col + N - 1] || diag2[row + col]) {
            continue;
        }

        cols[col] = diag1[row - col + N - 1] = diag2[row + col] = true;

        if (backtrack(row + 1, N, grid, cols, diag1, diag2)) {
            return true;
        }
        cols[col] = diag1[row - col + N - 1] = diag2[row + col] = false;
    }

    return false;
}

bool canPlaceSecurityCameras(int N, int grid_rows, int grid_columns, int** grid) {
       if (N == 0) return true;
    
   
    bool* cols = (bool*)calloc(N, sizeof(bool));
    bool* diag1 = (bool*)calloc(2 * N, sizeof(bool)); // row - col + (N-1)
    bool* diag2 = (bool*)calloc(2 * N, sizeof(bool)); // row + col

    bool result = backtrack(0, N, grid, cols, diag1, diag2);

    free(cols);
    free(diag1);
    free(diag2);

    return result;
}


int main()
{
    int N = parse_int(ltrim(rtrim(readline())));

    int grid_rows = parse_int(ltrim(rtrim(readline())));

    int grid_columns = parse_int(ltrim(rtrim(readline())));

    int** grid = malloc(grid_rows * sizeof(int*));

    for (int i = 0; i < grid_rows; i++) {
        *(grid + i) = malloc(grid_columns * (sizeof(int)));

        char** grid_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < grid_columns; j++) {
            int grid_item = parse_int(*(grid_item_temp + j));

            *(*(grid + i) + j) = grid_item;
        }
    }

    bool result = canPlaceSecurityCameras(N, grid_rows, grid_columns, grid);

    printf("%d\n", result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
