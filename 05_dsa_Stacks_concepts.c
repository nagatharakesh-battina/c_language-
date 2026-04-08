#include <stdio.h>
#include <string.h>

#define MAX 100

char undoStack[MAX][100];
char redoStack[MAX][100];

int undoTop = -1, redoTop = -1;

char current[100] = "";

// Push to undo stack
void pushUndo(char *state) {
    strcpy(undoStack[++undoTop], state);
}

// Push to redo stack
void pushRedo(char *state) {
    strcpy(redoStack[++redoTop], state);
}

// Undo operation
void undo() {
    if(undoTop == -1) {
        printf("Nothing to undo\n");
        return;
    }

    pushRedo(current);
    strcpy(current, undoStack[undoTop--]);
}

// Redo operation
void redo() {
    if(redoTop == -1) {
        printf("Nothing to redo\n");
        return;
    }

    pushUndo(current);
    strcpy(current, redoStack[redoTop--]);
}

// Add text
void type(char *text) {
    pushUndo(current);
    strcat(current, text);
    redoTop = -1; // clear redo
}

int main() {
    type("A");
    type("B");
    printf("Current: %s\n", current);

    undo();
    printf("After Undo: %s\n", current);

    redo();
    printf("After Redo: %s\n", current);

    return 0;
}
