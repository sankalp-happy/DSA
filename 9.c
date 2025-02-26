#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int coeff;
  int x_exp;
  int y_exp;
  int z_exp;
  struct Node *next;
} Node;

Node *createNode(int coeff, int x_exp, int y_exp, int z_exp) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->coeff = coeff;
  newNode->x_exp = x_exp;
  newNode->y_exp = y_exp;
  newNode->z_exp = z_exp;
  newNode->next = newNode;
  return newNode;
}

void insertTerm(Node **head, int coeff, int x_exp, int y_exp, int z_exp) {
  Node *newNode = createNode(coeff, x_exp, y_exp, z_exp);
  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *temp = *head;
    while (temp->next != *head) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
  }
}

void displayPolynomial(Node *head) {
  if (head == NULL) {
    printf("0\n");
    return;
  }
  Node *temp = head;
  int firstTerm = 1;
  do {
    if (temp->coeff != 0) {
      if (!firstTerm) {
        printf("+ ");
      }
      printf("%d*x^%d*y^%d*z^%d ", temp->coeff, temp->x_exp, temp->y_exp,
             temp->z_exp);
      firstTerm = 0;
    }
    temp = temp->next;
  } while (temp != head);
  printf("\n");
}

Node *addPolynomials(Node *poly1, Node *poly2) {
  Node *polySum = NULL;
  Node *temp1 = poly1;
  Node *temp2 = poly2;

  do {
    insertTerm(&polySum, temp1->coeff, temp1->x_exp, temp1->y_exp,
               temp1->z_exp);
    temp1 = temp1->next;
  } while (temp1 != poly1);

  do {
    Node *tempSum = polySum;
    int found = 0;
    do {
      if (tempSum->coeff != 0 && tempSum->x_exp == temp2->x_exp &&
          tempSum->y_exp == temp2->y_exp && tempSum->z_exp == temp2->z_exp) {
        tempSum->coeff += temp2->coeff;
        found = 1;
        break;
      }
      tempSum = tempSum->next;
    } while (tempSum != polySum);

    if (!found) {
      insertTerm(&polySum, temp2->coeff, temp2->x_exp, temp2->y_exp,
                 temp2->z_exp);
    }
    temp2 = temp2->next;
  } while (temp2 != poly2);

  return polySum;
}

Node *read_poly(Node *head) {
  int coeff, x_exp, y_exp, z_exp;
  char choice;
  do {
    printf("Enter coefficient: ");
    scanf("%d", &coeff);
    printf("Enter exponent of x: ");
    scanf("%d", &x_exp);
    printf("Enter exponent of y: ");
    scanf("%d", &y_exp);
    printf("Enter exponent of z: ");
    scanf("%d", &z_exp);
    insertTerm(&head, coeff, x_exp, y_exp, z_exp);
    printf("Do you want to add another term? (y/n): ");
    scanf(" %c", &choice);
  } while (choice == 'y' || choice == 'Y');
  return head;
}

double evaluatePolynomial(Node *head, double x, double y, double z) {
  double result = 0.0;
  if (head == NULL) {
    return result;
  }
  Node *temp = head;
  do {
    result += temp->coeff * pow(x, temp->x_exp) * pow(y, temp->y_exp) *
              pow(z, temp->z_exp);
    temp = temp->next;
  } while (temp != head);
  return result;
}

void freePolynomial(Node *head) {
  if (head == NULL) {
    return;
  }
  Node *temp = head;
  Node *nextNode;
  do {
    nextNode = temp->next;
    free(temp);
    temp = nextNode;
  } while (temp != head);
}

int main() {
  Node *eval = NULL;
  Node *h1 = NULL;
  Node *h2 = NULL;
  Node *h3 = NULL;
  int ch;

  while (1) {
    printf("\n\n1. Evaluate polynomial\n2. Add two polynomials\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1: {
      printf("\nEnter polynomial to evaluate:\n");
      eval = read_poly(eval);
      displayPolynomial(eval);

      double x, y, z;
      printf("Enter the value of x: ");
      scanf("%lf", &x);
      printf("Enter the value of y: ");
      scanf("%lf", &y);
      printf("Enter the value of z: ");
      scanf("%lf", &z);

      double result = evaluatePolynomial(eval, x, y, z);
      printf("The result of the polynomial evaluation is: %.2f\n", result);

      freePolynomial(eval);
      eval = NULL;
      break;
    }
    case 2: {
      printf("\nEnter the first polynomial: ");
      h1 = read_poly(h1);
      printf("\nEnter the second polynomial: ");
      h2 = read_poly(h2);
      h3 = addPolynomials(h1, h2);
      printf("\nFirst polynomial is: ");
      displayPolynomial(h1);
      printf("\nSecond polynomial is: ");
      displayPolynomial(h2);
      printf("\nThe sum of 2 polynomials is: ");
      displayPolynomial(h3);

      freePolynomial(h1);
      freePolynomial(h2);
      freePolynomial(h3);
      h1 = h2 = h3 = NULL;
      break;
    }
    case 3:
      exit(0);
      break;
    default:
      printf("\nInvalid entry");
    }
  }
  return 0;
}
