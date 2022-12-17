#include <stdlib.h>
#include <stdio.h>

typedef struct Node {

    int flow_rate;
    int branch;
    int* children;

} Node;

int readIndex (FILE* file) {
    char c1 = fgetc(file);
    char c2 = fgetc(file);
    if (c1 > 'Z' || c1 < 'A' || c2 > 'Z' || c2 < 'A') return -1;
    return (26 * (c1 - 'A') + (c2 - 'A'));
}

void resize (Node** arr, Node insert, int length) {
    Node* temp = (Node*) malloc(sizeof(int) * (length + 1));
    for (int i = 0; i < length; i++) temp[i] = (*arr)[i];
    free(*arr);
    temp[length] = insert;
    *arr = temp;
}

void resize (Node** arr, Node insert) {
    int length = 0;
    while ((*arr)[length].flow_rate != -1) length++;
    resize(arr, insert, length);
}

void resize (int** arr, int insert, int length) {
    int* temp = (int*) malloc(sizeof(int) * (length + 1));
    for (int i = 0; i < length; i++) temp[i] = (*arr)[i];
    free(*arr);
    temp[length] = insert;
    *arr = temp;
}

int readInt (FILE* file) {
    char c = fgetc(file);
    int current = 0;
    short negative = 0;

    while (((c <= '9' && c >= '0') || c == '-') && c != (char) EOF ) {
        if (c != '-') {
            current *= 10;
            current += c - '0';
        } else negative = 1;
        c = fgetc(file);
    }

    if (negative == 1) current *= -1;

    return current;
}

int main () {

    Node* nodes = (Node*) malloc(sizeof(Node) * (26 * ('Z' - 'A') + ('Z' - 'A')));
    int length = (26 * ('Z' - 'A') + ('Z' - 'A'));
    Node null;
    null.flow_rate = -1;
    for (int i = 0; i < length; i++) nodes[i] = null;

    FILE* file = fopen("./example.txt", "r");
    char c = fgetc(file);

    while (c != (char) EOF) {
        for (; c != ' ' && c != (char) EOF; c = fgetc(file));
        int index = readIndex(file);
        for (; c != '=' && c != (char) EOF; c = fgetc(file));
        int flow = readInt(file);
        for (; c != 's' && c != (char) EOF; c = fgetc(file));
        for (c = fgetc(file); c != 's' && c != (char) EOF; c = fgetc(file));
        c = fgetc(file);
        int* children = (int*) malloc(0);
        int l = 0;
        int cur = readIndex(file);
        while (cur != -1) {
            resize(&children, cur, l);
            l++;
            c = fgetc(file);
            c = fgetc(file);
            cur = readIndex(file);
        }
        Node n;
        n.branch = l;
        n.children = children;
        n.flow_rate = flow;
        nodes[index] = n;
    }

    int sum = 0;
    int flowRate = 0;

    Node current = nodes[0];
    Node* open = (Node*) malloc(sizeof(Node) * 1);
    open[0] = null;
    Node* continuousNodes = (Node*) malloc(sizeof(Node) * 1);
    continuousNodes[0] = null;
    for (int i = 0; i < length; i++) if (nodes[i].flow_rate != -1) resize(&continuousNodes, nodes[i]);
    int numOpen = 0;
    // Idea 1) Weight each node we can travel to.
    for ()

    printf("Sum: %i\n", sum);

    return 0;
}