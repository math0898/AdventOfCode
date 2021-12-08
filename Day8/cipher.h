#ifndef CIPHER_H
#define CIPHER_H

struct cipher {
    char* zero;
    char* one;
    char* two;
    char* three;
    char* four;
    char* five;
    char* six;
    char* seven;
    char* eight;
    char* nine;
};

typedef struct cipher Cipher;

/**
 * Creates a new Cipher object using the following definitions for the unique elements.
 * 
 * @param one The known value for 1.
 * @param four The known value for 4.
 * @param seven The known value for 7.
 * @param eight The known value for 8.
 * @return A pointer to the newly created Cipher object.
 */
Cipher* createCipher (char* one, char* four, char* seven, char* eight) {
    Cipher* r = malloc(sizeof(Cipher));
    r->zero = NULL;
    r->one = one;
    r->two = NULL;
    r->three = NULL;
    r->four = four;
    r->five = NULL;
    r->six = NULL;
    r->seven = seven;
    r->eight = eight;
    r->nine = NULL;
}

/**
 * Determines the number of overlapping values two char arrays have.
 * 
 * @param c1 The first char array.
 * @param n1 The length of the first char array.
 * @param c2 The second char array.
 * @param n2 The length of the second char array.
 * @return The number of overlapping chars.
 */
int intersect (char* c1, int n1, char* c2, int n2) {
    int count = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (c1[i] == c2[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

/**
 * Uses a solved cipher to determine what value the given char array represents.
 * 
 * @param c The char array to consider.
 * @param n The length of the char array.
 * @param cipher The solve cipher to be used.
 */
int solve (char* c, int n, Cipher* cipher) {
    switch (n) {
        case 2: return 1;
        case 3: return 7;
        case 4: return 4;
        case 7: return 8;
    }
    if (n == 5) {
        if (intersect(c, 5, cipher->three, 5) == 5) return 3;
        else if (intersect(c, 5, cipher->five, 5) == 5) return 5;
        else return 2;
    } else if (n == 6) {
        if (intersect(c, 6, cipher->zero, 6) == 6) return 0;
        else if (intersect(c, 6, cipher->nine, 6) == 6) return 9;
        else return 6;
    }
    return -1;
}

/**
 * Using the unique values solves the items of length 6.
 * 
 * @param sixes Items with a length of 6. There should be three of them.
 * @param cipher The cipher to solve.
 */
void solveSixes (char** sixes, Cipher* cipher) {
    for (int i = 0; i < 3; i++) {
        if (intersect(sixes[i], 6, cipher->one, 2) == 1) cipher->six = sixes[i];
        else if (intersect(sixes[i], 6, cipher->four, 4) == 4) cipher->nine = sixes[i];
        else cipher->zero = sixes[i];
    }
}

/**
 * Using the unique values solves the items of length 5.
 * 
 * @param fives Items with a length of 5. There should be three of them.
 * @param cipher The cipher to solve.
 */
void solveFives (char** fives, Cipher* cipher) {
    for (int i = 0; i < 3; i++) {
        if (intersect(fives[i], 5, cipher->one, 2) == 2) cipher->three = fives[i];
        else if (intersect(fives[i], 5, cipher->four, 4) == 2) cipher->two = fives[i];
        else cipher->five = fives[i];
    }
}

/**
 * Uses the unique values assigned at construction to assign values to the remaining positions.
 * 
 * @param fives Items with a length of 5. There should be three of these.
 * @param sixes Items with a length of 6. There should be three of these.
 * @param cipher The cipher to solve.
 */
void solveCipher (char** fives, char** sixes, Cipher* cipher) {
    solveSixes(sixes, cipher);
    solveFives(fives, cipher);
}

#endif /* CIPHER_H */
