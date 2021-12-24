#ifndef STACK_H
#define STACK_H

#ifndef NULL
#define NULL 0
#endif

/**
 * This struct defines what a node inside of a stack looks like.
 * 
 * @author Sugaku
 */
struct Stack_Node {

    /**
     * Pointer to the next Node in the stack.
     */
    struct Stack_Node* next;

    /**
     * Pointer to the data stored inside of this node. Stacks should have a unified typing however this stack does support any type.
     */
    void* data;

};

typedef struct Stack_Node Stack_Node;

/**
 * This is the stack definition it should be used whenever a dynamically sized structure is needed however access to the middle
 * isn't needed.
 * 
 * @author Sugaku
 */
struct Stack {

    /**
     * This is a pointer to the current top node in the stack. If the stack is empty this will be a NULL pointer.
     */
    Stack_Node* head;

};

typedef struct Stack Stack;

/**
 * Creates a new empty stack.
 * 
 * @return A newly created stack with no elements.
 */
Stack* createStack ();

/**
 * Adds the given data into the given stack.
 * 
 * @param stack The stack that data should be added to.
 * @param data The data to add into the stack. Should match the types of other elements to prevent casting related errors.
 */
void add (Stack* stack, void* data);

/**
 * Removes the top most element of the stack whilst also returning the data.
 * 
 * @return The data containted in the topmost node.
 */
void* pop (Stack* stack);

/**
 * Peeks at the top most element of the stack without removing it.
 * 
 * @return The data contained in the topmost node.
 */
void* peek (Stack* stack);

/**
 * Checks if the stack is empty.
 * 
 * @return 1 if empty, 0 if not empty
 */
char isEmpty (Stack* stack);

#endif /* STACK_H */
