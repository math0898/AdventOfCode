#include <stdlib.h>
#include "Stack.h"

/**
 * Creates a new empty stack.
 * 
 * @return A newly created stack with no elements.
 */
Stack* createStack () {
    Stack* toReturn = malloc(sizeof(Stack));
    toReturn->head = NULL;
    return toReturn;
}

/**
 * Adds the given data into the given stack.
 * 
 * @param stack The stack that data should be added to.
 * @param data The data to add into the stack.
 */
void add (Stack* stack, int data) {
    Stack_Node* temp = malloc(sizeof(Stack_Node));
    temp->next = stack->head;
    temp->data = data;
    stack->head = temp;
}

/**
 * Removes the top most element of the stack whilst also returning the data.
 * 
 * @return The data containted in the topmost node.
 */
int pop (Stack* stack) {
    if (stack->head == NULL) return -1;
    int temp = stack->head->data;
    Stack_Node* swap = stack->head->next;
    free(stack->head);
    stack->head = swap;
    return temp;
}

/**
 * Peeks at the top most element of the stack without removing it.
 * 
 * @return The data contained in the topmost node.
 */
int peek (Stack* stack) {
    if (stack->head == NULL) return -1;
    return stack->head->data;
}

/**
 * Checks if the stack is empty.
 * 
 * @return 0000 0001 if empty, 0000 0000 if not empty
 */
char isEmpty (Stack* stack) {
    if (stack->head == NULL) return (char) 1;
    return (char) 0;
}

/**
 * Prints the stack to console. This will not alter the stack in any way.
 * 
 * @param stack The stack to print to console.
 */
void printStack (Stack* stack) {
    Stack_Node* current = stack->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/**
 * Checks if the stack contains the given data value.
 * 
 * @param stack The stack to check for the data in.
 * @param data The data to check for in the stack.
 * @return 1 if it does, 0 if it does not.
 */
char contains (Stack* stack, int data) {
    Stack_Node* current = stack->head;
    while (current != NULL) {
        if (current->data == data) return (char) 1;
        current = current->next;
    }
    return (char) 0;
}
