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

int parse_int(char*);



/*
 * Complete the 'verifySameMultisetDifferentStructure' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY root1
 *  2. INTEGER_ARRAY root2
 */



bool sameStructure(int* a, int* b, int i, int n1, int n2) {
    int val1 = (i < n1) ? a[i] : 100001;
    int val2 = (i < n2) ? b[i] : 100001;

    if ((val1 == 100001 && val2 != 100001) ||
        (val1 != 100001 && val2 == 100001))
        return false;

    if (val1 == 100001 && val2 == 100001)
        return true;

    return sameStructure(a, b, 2*i+1, n1, n2) &&
           sameStructure(a, b, 2*i+2, n1, n2);
}
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
bool verifySameMultisetDifferentStructure(int root1_count, int* root1, int root2_count, int* root2) {

    int *a = (int*)malloc(root1_count * sizeof(int));
    int *b = (int*)malloc(root2_count * sizeof(int));

    int n1 = 0, n2 = 0;

    for (int i = 0; i < root1_count; i++)
        if (root1[i] != 100001) a[n1++] = root1[i];

    for (int i = 0; i < root2_count; i++)
        if (root2[i] != 100001) b[n2++] = root2[i];

    if (n1 != n2) return false;

    qsort(a, n1, sizeof(int), cmp);
    qsort(b, n2, sizeof(int), cmp);

    for (int i = 0; i < n1; i++)
        if (a[i] != b[i]) return false;

    bool same = sameStructure(root1, root2, 0, root1_count, root2_count);

    return (same == false);
}


int main()
{
    int root1_count = parse_int(ltrim(rtrim(readline())));

    int* root1 = malloc(root1_count * sizeof(int));

    for (int i = 0; i < root1_count; i++) {
        int root1_item = parse_int(ltrim(rtrim(readline())));

        *(root1 + i) = root1_item;
    }

    int root2_count = parse_int(ltrim(rtrim(readline())));

    int* root2 = malloc(root2_count * sizeof(int));

    for (int i = 0; i < root2_count; i++) {
        int root2_item = parse_int(ltrim(rtrim(readline())));

        *(root2 + i) = root2_item;
    }

    bool result = verifySameMultisetDifferentStructure(root1_count, root1, root2_count, root2);

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

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
