#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->data[++(s->top)] = value;
        printf("%d pushed onto stack\n", value);
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->data[(s->top)--];
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}

int isPalindrome(Stack *s) {
    if (isEmpty(s)) {
        return 1;
    }
    int start = 0;
    int end = s->top;
    while (start < end) {
        if (s->data[start] != s->data[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    Stack s;
    initialize(&s);
    int choice, value;
    printf("\nMenu:\n");
        printf("1. Push an Element on to Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display the status of Stack\n");
        printf("6. Exit\n");

    while (1) {
                printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                printf("Enter the String: ");
                char str[100];
                fgets(str, sizeof(str), stdin);
                Stack pal;
                initialize(&pal);
                for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
                    push(&pal, str[i]);
                }
                if (isPalindrome(&pal)) {
                    printf("Stack is a palindrome\n");
                } else {
                    printf("Stack is not a palindrome\n");
                }
                break;
            case 4:
                printf("Demonstrating Overflow:\n");
                for (int i = 0; i < MAX + 1; i++) {
                    push(&s, i);
                }
                printf("Demonstrating Underflow:\n");
                for (int i = 0; i < MAX + 1; i++) {
                    pop(&s);
                }
                break;
            case 5:
                display(&s);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
