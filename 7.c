#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    char usn[20];
    char name[50];
    char programme[50];
    int sem;
    char phNo[15];
    struct Student* next;
};


struct Student* createStudent(char usn[], char name[], char programme[], int sem, char phNo[]) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->usn, usn);
    strcpy(newStudent->name, name);
    strcpy(newStudent->programme, programme);
    newStudent->sem = sem;
    strcpy(newStudent->phNo, phNo);
    newStudent->next = NULL;
    return newStudent;
}


void insertFront(struct Student** head, char usn[], char name[], char programme[], int sem, char phNo[]) {
    struct Student* newStudent = createStudent(usn, name, programme, sem, phNo);
    newStudent->next = *head;
    *head = newStudent;
}


void display(struct Student* head) {
    struct Student* temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("USN: %s, Name: %s, Programme: %s, Sem: %d, PhNo: %s\n", temp->usn, temp->name, temp->programme, temp->sem, temp->phNo);
        temp = temp->next;
        count++;
    }
    printf("Total number of students: %d\n", count);
}


void insertEnd(struct Student** head, char usn[], char name[], char programme[], int sem, char phNo[]) {
    struct Student* newStudent = createStudent(usn, name, programme, sem, phNo);
    if (*head == NULL) {
        *head = newStudent;
        return;
    }
    struct Student* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
}


void deleteFront(struct Student** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Student* temp = *head;
    *head = (*head)->next;
    free(temp);
}


void deleteEnd(struct Student** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Student* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}


int main() {
    struct Student* head = NULL;
    int choice, sem, n;
    char usn[20], name[50], programme[50], phNo[15];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create SLL of N Students (Front Insertion)\n");
        printf("2. Display SLL and Count Nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete from End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete from Front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of students: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter USN: ");
                    scanf("%s", usn);
                    printf("Enter Name: ");
                    scanf("%s", name);
                    printf("Enter Programme: ");
                    scanf("%s", programme);
                    printf("Enter Semester: ");
                    scanf("%d", &sem);
                    printf("Enter Phone Number: ");
                    scanf("%s", phNo);
                    insertFront(&head, usn, name, programme, sem, phNo);
                }
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter USN: ");
                scanf("%s", usn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Programme: ");
                scanf("%s", programme);
                printf("Enter Semester: ");
                scanf("%d", &sem);
                printf("Enter Phone Number: ");
                scanf("%s", phNo);
                insertEnd(&head, usn, name, programme, sem, phNo);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
                printf("Enter USN: ");
                scanf("%s", usn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Programme: ");
                scanf("%s", programme);
                printf("Enter Semester: ");
                scanf("%d", &sem);
                printf("Enter Phone Number: ");
                scanf("%s", phNo);
                insertFront(&head, usn, name, programme, sem, phNo);
                break;
            case 6:
                deleteFront(&head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}