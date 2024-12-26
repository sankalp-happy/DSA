#include <stdio.h>
#include <stdlib.h>

#define M 5 // Number of memory locations in the hash table

typedef struct {
    int key;
    char name[30];
    int age;
} Employee;

Employee* hashTable[M];

int hashFunction(int key) {
    return key % M;
}

void insert(Employee* emp) {
    int index = hashFunction(emp->key);
    int originalIndex = index;
    while (hashTable[index] != NULL) {
        index = (index + 1) % M;
        printf("Index %d is already occupied. Trying index %d\n", (index - 1) % M, index);
        if (index == originalIndex) {
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[index] = emp;
}

void displayHashTable() {
    for (int i = 0; i < M; i++) {
        if (hashTable[i] != NULL) {
            printf("Index %d: Key: %d, Name: %s, Age: %d\n", i, hashTable[i]->key, hashTable[i]->name, hashTable[i]->age);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < M; i++) {
        hashTable[i] = NULL;
    }

    int ans = 1;
    while (ans) {
        Employee* emp = (Employee*)malloc(sizeof(Employee));
        printf("\nEnter the key (4-digit): ");
        scanf("%d", &emp->key);
        printf("Enter the name: ");
        scanf("%s", emp->name);
        printf("Enter the age: ");
        scanf("%d", &emp->age);

        insert(emp);

        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d", &ans);
    }

    // Display hash table
    displayHashTable();

    return 0;
}