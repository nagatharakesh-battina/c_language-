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
 * Complete the 'getBinarySearchTreeHeight' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY values
 *  2. INTEGER_ARRAY leftChild
 *  3. INTEGER_ARRAY rightChild
 */
int hight(int index,int* leftChild,int * rightChild){
    if(index==-1){
        return 0;
    }
    int left=hight(leftChild[index], leftChild, rightChild);
    int right = hight(rightChild[index], leftChild, rightChild);
    int max;
    if(left>=right){
        max=left;
    }else{
        max=right;
    }
    return 1+ max;
}
int getBinarySearchTreeHeight(int values_count, int* values, int leftChild_count, int* leftChild, int rightChild_count, int* rightChild) {
    
    if(values_count==0){
        return 0;
    }
    return hight(0,leftChild,rightChild);
    
}

int main()
{
    int values_count = parse_int(ltrim(rtrim(readline())));

    int* values = malloc(values_count * sizeof(int));

    for (int i = 0; i < values_count; i++) {
        int values_item = parse_int(ltrim(rtrim(readline())));

        *(values + i) = values_item;
    }

    int leftChild_count = parse_int(ltrim(rtrim(readline())));

    int* leftChild = malloc(leftChild_count * sizeof(int));

    for (int i = 0; i < leftChild_count; i++) {
        int leftChild_item = parse_int(ltrim(rtrim(readline())));

        *(leftChild + i) = leftChild_item;
    }

    int rightChild_count = parse_int(ltrim(rtrim(readline())));

    int* rightChild = malloc(rightChild_count * sizeof(int));

    for (int i = 0; i < rightChild_count; i++) {
        int rightChild_item = parse_int(ltrim(rtrim(readline())));

        *(rightChild + i) = rightChild_item;
    }

    int result = getBinarySearchTreeHeight(values_count, values, leftChild_count, leftChild, rightChild_count, rightChild);

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
