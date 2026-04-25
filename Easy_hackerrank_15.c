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
 * Complete the 'hasCircularDependency' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY dependencies
 */
struct Node {
    int val;
    struct Node* next;
};
bool dfs(int u, struct Node** adj, int* state) {
    state[u] = 1;
    struct Node* curr = adj[u];
    while (curr) {
        int v = curr->val;
        if (state[v] == 1) return true;
        if (state[v] == 0 && dfs(v, adj, state)) return true;
        curr = curr->next;
    }
    state[u] = 2;
    return false;
}

bool hasCircularDependency(int n, int dependencies_rows, int dependencies_columns, int** dependencies) {
    struct Node** adj = calloc(n, sizeof(struct Node*));
    for (int i = 0; i < dependencies_rows; i++) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->val = dependencies[i][1];
        newNode->next = adj[dependencies[i][0]];
        adj[dependencies[i][0]] = newNode;
    }

    int* state = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (state[i] == 0 && dfs(i, adj, state)) return true;
    }
    return false;
}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    int dependencies_rows = parse_int(ltrim(rtrim(readline())));

    int dependencies_columns = parse_int(ltrim(rtrim(readline())));

    int** dependencies = malloc(dependencies_rows * sizeof(int*));

    for (int i = 0; i < dependencies_rows; i++) {
        *(dependencies + i) = malloc(dependencies_columns * (sizeof(int)));

        char** dependencies_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < dependencies_columns; j++) {
            int dependencies_item = parse_int(*(dependencies_item_temp + j));

            *(*(dependencies + i) + j) = dependencies_item;
        }
    }

    bool result = hasCircularDependency(n, dependencies_rows, dependencies_columns, dependencies);

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
