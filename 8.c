#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
struct node {
  struct node *prev;
  int ssn;
  long int phno;
  float sal;
  char name[20], dept[10], desg[20];
  struct node *next;
} *first, *temp, *last;

void create() {
  int ssn;
  long int phno;
  float sal;
  char name[20], dept[10], desg[20];
  temp = (struct node *)malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->next = NULL;
  printf("\n Enter ssn,name,department,designation,salary and phno of employee "
         ": ");
  scanf("%d %s %s %s %f %ld", &ssn, name, dept, desg, &sal, &phno);
  temp->ssn = ssn;
  strcpy(temp->name, name);
  strcpy(temp->dept, dept);
  strcpy(temp->desg, desg);
  temp->sal = sal;
  temp->phno = phno;
  count++;
}

void display() {
  temp = first;
  if (temp == NULL) {
    printf("List is Empty\n");
    return;
  }
  printf("\n Linked list elements from begining : \n");
  while (temp != NULL) {
    printf("%d %s %s %s %f %ld\n", temp->ssn, temp->name, temp->dept,
           temp->desg, temp->sal, temp->phno);
    temp = temp->next;
  }
  printf("\n No of employees = %d", count);
}

void insert_front() {
  if (first == NULL) {
    create();
    first = temp;
    last = first;
  } else {
    create();
    temp->next = first;
    first->prev = temp;
    first = temp;
  }
}

void delete_front() {
  struct node *cur;
  cur = first;
  if (first == NULL) 
  {
    printf("List is Empty\n");
    return;
  }
  if (first->next == NULL) 
  {
    printf("%d %s %s %s %f %ld\n", first->ssn, first->name, first->dept,
           first->desg, first->sal, first->phno);
    free(first);
    first = NULL;
  } else {
    printf("%d %s %s %s %f %ld\n", cur->ssn, cur->name, cur->dept, cur->desg,
           cur->sal, cur->phno);
    first = first->next;
    first->prev = NULL;
    free(cur);
  }
  count--;
}

void insert_rear() {
  if (first == NULL) {
    create();
    first = temp;
    last = first;
  } else {
    create();
    last->next = temp;
    temp->prev = last;
    last = temp;
  }
}

void delete_rear() {
  if (first == NULL) 
  {
    printf("List is Empty\n");
    return;
  }
  if (first->next == NULL) 
  {
    printf("%d %s %s %s %f %ld\n", first->ssn, first->name, first->dept,
           first->desg, first->sal, first->phno);
    free(first);
    first = NULL;
  } else {
    temp = last->prev;
    temp->next = NULL;
    printf("%d %s %s %s %f %ld\n", last->ssn, last->name, last->dept,
           last->desg, last->sal, last->phno);
    free(last);
    last = temp;
  }
  count--;
}

int main() {
  int ch, n, i;
  first = NULL;
  temp = last = NULL;
  printf("\n                   MENU                             \n");
  printf("\n 1 - Create a DLL of n emp");
  printf("\n 2 - Display from beginning");
  printf("\n 3 - Insert at front end");
  printf("\n 4 - Delete at front end");
  printf("\n 5 - Insert at rear end");
  printf("\n 6 - Delete at rear end");
  printf("\n 7 - exit\n");
  printf(".............................................\n");
  while (1) {
    printf("\n Enter Choice : ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("\n Enter no of employees : ");
      scanf("%d", &n);
      for (i = 0; i < n; i++)
        insert_rear();
      break;
    case 2:
      display();
      break;
    case 3:
      insert_front();
      break;
    case 4:
      delete_front();
      break;
    case 5:
      insert_rear();
      break;
    case 6:
      delete_rear();
      break;
    case 7:
      exit(0);
    default:
      printf("Wrong Choice\n");
      break;
    }
  }
}
