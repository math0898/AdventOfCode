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

    for (int i = 0; i < length; i++) {
        Node n = nodes[i];
        if (n.flow_rate != -1) {
            printf("Node: %i(%i) --->", i, n.flow_rate);
            for (int j = 0; j < n.branch; j++) printf(" %i", n.children[j]);
            printf("\n");
        }
    }

    int bestPath[30];
    int currentPath[30];
    int sum = 0;
    int flowRate = 0;
    for (int i = 0; i < 30; i++) {
        currentPath[i] = -2;
        bestPath[i] = -2;
    }

    short open = 0;

    Node current = nodes[0];
    for (int i = 0; i < 30; i++) {
        sum += current.flow_rate;
        if (current.flow_rate > 0 && open == 0) {
            flowRate += current.flow_rate;
            open = 1;
        } else {
            open = 0;
            int toMove = -1;
            int nextflow = 0;
            for (int j = 0; j < current.branch; j++) {
                if (nodes[current.children[j]].flow_rate > nextflow) {
                    toMove = current.children[j];
                    nextflow = nodes[current.children[j]].flow_rate;
                }
            }
            current = nodes[toMove];
        }
    }

    printf("Sum: %i\n", sum);

    return 0;
}