#include <stdio.h>
#include <stdlib.h>

/**
 * Lets do some dumb stuff that is similar to objects in C...
 */
typedef struct Stack {
    char* arr;
    long length;
    void (*reverse)(struct Stack*);
    char (*pop)(struct Stack*);
    void (*push)(struct Stack*, char);
    void (*print)(struct Stack*);
} Stack;

void reverseStack (Stack* s) {
    char* temp = malloc(sizeof(char) * s->length);
    for (long i = 0; i < s->length; i++) 
        temp[i] = s->arr[s->length - i -1];
    free(s->arr);
    s->arr = temp;
}

char popStack (Stack* s) {
    if (s->length == 0) return (char) -1;
    s->length--;
    char* temp = malloc(sizeof(char) * s->length);
    char c = s->arr[0];
    for (long i = 0; i < s->length; i++) 
        temp[i] = s->arr[i + 1];
    free(s->arr);
    s->arr = temp;
    return c;
}

void pushStack (Stack* s, char c) {
    if (c == (char) -1) return;
    s->length++;
    char* temp = malloc(sizeof(char) * s->length);
    temp[0] = c;
    for (long i = 0; i < s->length; i++)
        temp[i + 1] = s->arr[i];
    if (s->length > 0) free(s->arr);
    s->arr = temp;
}

void print (Stack* s) {
    printf("[ ");
    for (long i = 0; i < s->length; i++)
        printf("%c ", s->arr[i]);
    printf("]\n");
}

Stack* createStack () {
    Stack* toReturn = malloc(sizeof(Stack));
    toReturn->pop = &popStack;
    toReturn->reverse = &reverseStack;
    toReturn->push = &pushStack;
    toReturn->print = &print;
    toReturn->length = 0;
    toReturn->arr = malloc(sizeof(char) * 0); // malloc 0 in disguise... undefined behavior :shrug:
    return toReturn;
}

void deleteStack (Stack* s) {
    free(s->arr);
    free(s);
}

int readTillInt (FILE* file) {
    char c = fgetc(file);
    int i = 0;
    short con = 0;
    while (c != (char) EOF) { 
        c = fgetc(file);
        if (c <= '9' && c >= '0') {
            con = 1;
            i *= 10;
            i += c - '0';
        } else if (con == 1) break;
    }
    return i;
}

int main () {
    int stackCount = 9;
    FILE* file = fopen("./input.txt", "r");
    Stack** stacks = malloc(sizeof(Stack*) * stackCount);
    for (int i = 0; i < stackCount; i++)
        stacks[i] = createStack();

    char c = getc(file);
    int li = 1; // line index

    while (c != 'm') {
        if (c == '\n') {
            li = 0;
        } else if (c == '[') {
            c = getc(file);
            stacks[li / 4]->push(stacks[li / 4], c);
            li++;
        }
        c = getc(file);
        li++;
    }
    for (int i = 0; i < stackCount; i++) {
        stacks[i]->reverse(stacks[i]);
        stacks[i]->print(stacks[i]);
    }

    int count = 0;
    int from = 0;
    int to = 0;

    while ( c != (char) EOF) { // todo rewrite while loops as 'read till char'
        count = readTillInt(file);
        from = readTillInt(file) - 1; // File indexes from 1, we do 0
        to = readTillInt(file) - 1; // See from
        if (c != (char) EOF) {
            Stack* temp = createStack();
            for (int i = 0; i < count; i++)
                temp->push(temp, stacks[from]->pop(stacks[from]));
            // temp->reverse(temp); // This line uncommented produces part 1
            for (char c = temp->pop(temp); c != (char) -1; c = temp->pop(temp))
                stacks[to]->push(stacks[to], c);
            printf("\n\n\n");
            printf("move %i from %i to %i \n", count, from + 1, to + 1);
            for (int i = 0; i < stackCount; i++) 
                stacks[i]->print(stacks[i]);
            deleteStack(temp);
        }
        c = fgetc(file);
    }

    printf("\n\n\n");

    for (int i = 0; i < stackCount; i++) 
        stacks[i]->print(stacks[i]);

    printf("Part 2 Solution: "); // TODO: Up to this point the program has undeterministic behavior.
    for (int i = 0; i < stackCount; i++) 
        printf("%c", stacks[i]->arr[0]);
    printf("\n");

    fclose(file);
    for (int i = 0; i < stackCount; i++) deleteStack(stacks[i]);
    free(stacks);

    return 0;
}
