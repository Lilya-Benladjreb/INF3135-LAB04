#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000
#define USAGE "\
Usage: %s {-l|-r}\n\
Sorts a list of words provided on stdin.\n\
  -l    Use the lexicographic (dictionary) order\n\
  -r    Use the radix order\n\
"

/**
 * Compares two strings according to the lexicographic order
 *
 * @param s  A pointer to the first string
 * @param t  A pointer to the second string
 */
int lex_compare(const void *s, const void *t) {
    // À compléter
}

/**
 * Compares two strings according to the radix order
 *
 * @param s  A pointer to the first string
 * @param t  A pointer to the second string
 */
int radix_compare(const void *s, const void *t) {
    // À compléter
}

/**
 * Loads a list of words from stdin
 *
 * Assumes that the words are at most 100 characters
 */
unsigned int load_words(char *words[]) {
    char line[100];
    unsigned int i = 0;
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';
        words[i] = strdup(line);
        ++i;
    }
    return i;
}

/**
 * Prints an array of words to stdout
 *
 * @param words  The words to print
 * @param n      The size of the array
 */
void print_words(char *words[], unsigned int n) {
    for (unsigned int i = 0; i < n; ++i)
        printf ("%s\n", words[i]);
}

int main(int argc, char *argv[]) {
    if (argc == 2 && (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "-r") == 0)) {
        static char *words[N];
        unsigned int n = load_words(words);
        qsort(words, n, sizeof(char*),
              strcmp(argv[1], "-l") == 0 ? lex_compare : radix_compare);
        print_words(words, n);
        return 0;
    } else {
        fprintf(stderr, "Error: missing option\n");
        fprintf(stderr, USAGE, argv[0]);
        return 1;
    }
}
