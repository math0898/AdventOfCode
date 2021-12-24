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
 * @param data The data to add into the stack. Should match the types of other elements to prevent casting related errors.
 */
void add (Stack* stack, void* data) {
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
void* pop (Stack* stack) {
    if (stack->head == NULL) return NULL;
}

/**
 * Peeks at the top most element of the stack without removing it.
 * 
 * @return The data contained in the topmost node.
 */
void* peek (Stack* stack) {
    if (stack->head == NULL) return NULL;
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
