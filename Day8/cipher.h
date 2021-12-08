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
    // todo
}

/**
 * Using the unique values solves the items of length 6.
 * 
 * @param sixes Items with a length of 6, there should be three of them.
 * @param cipher The cipher to solve.
 */
void solveSixes (char** sixes, Cipher* cipher) {
    // todo
}

/**
 * Uses the unique values assigned at construction to assign values to the remaining positions.
 * 
 * @param fives Items with a length of 5, there should be three of these.
 * @param sixes Items with a length of 6, there should be three of these.
 * @param cipher The cipher to solve.
 */
void solveCipher (char** fives, char** sixes, Cipher* cipher) {
    // todo
}

#endif /* CIPHER_H */