// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];

void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
}

void search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    // initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}