#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
  char *name;
  int date;
  char *activity;
};

struct Day *create() {
  struct Day *calendar = (struct Day *)malloc(7 * sizeof(struct Day));
  return calendar;
}

void read(struct Day *calendar) {
  for (int i = 0; i < 7; i++) {
    calendar[i].name = (char *)malloc(10 * sizeof(char));
    calendar[i].activity = (char *)malloc(100 * sizeof(char));

    printf("Enter the name of day %d: ", i + 1);
    scanf("%s", calendar[i].name);
    printf("Enter the date for %s: ", calendar[i].name);
    scanf("%d", &calendar[i].date);
    printf("Enter the activity for %s: ", calendar[i].name);
    scanf(" %[^\n]", calendar[i].activity);
  }
}

void display(struct Day *calendar) {
  printf("\nWeek's Activity Details:\n");
  for (int i = 0; i < 7; i++) {
    printf("Day: %s, Date: %d, Activity: %s\n", calendar[i].name,
           calendar[i].date, calendar[i].activity);
  }
}

int main() {
  struct Day *calendar = create();
  read(calendar);
  display(calendar);

  for (int i = 0; i < 7; i++) {
    free(calendar[i].name);
    free(calendar[i].activity);
  }
  free(calendar);

  return 0;
}
