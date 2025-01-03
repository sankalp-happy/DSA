#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;


void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = element;
    printf("Pushed %d onto the stack\n", element);
}


int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int element = stack[top--];
    printf("Popped %d from the stack\n", element);
    return element;
}


void checkPalindrome() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    int isPalindrome = 1;
    for (int i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("Stack is a palindrome\n");
    } else {
        printf("Stack is not a palindrome\n");
    }
}


void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display the status of Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                
                top = MAX - 1;
                push(1); 
                
                top = -1;
                pop(); 
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}