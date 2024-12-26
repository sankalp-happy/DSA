#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a day
struct Day {
    char* name;
    int date;
    char* activity;
};

// Function to create the calendar
struct Day* create() {
    struct Day* calendar = (struct Day*)malloc(7 * sizeof(struct Day));
    return calendar;
}

// Function to read data from the keyboard
void read(struct Day* calendar) {
    for (int i = 0; i < 7; i++) {
        calendar[i].name = (char*)malloc(10 * sizeof(char));
        calendar[i].activity = (char*)malloc(100 * sizeof(char));

        printf("Enter the name of day %d: ", i + 1);
        scanf("%s", calendar[i].name);
        printf("Enter the date for %s: ", calendar[i].name);
        scanf("%d", &calendar[i].date);
        printf("Enter the activity for %s: ", calendar[i].name);
        scanf(" %[^\n]", calendar[i].activity);
    }
}

// Function to display the week's activity details
void display(struct Day* calendar) {
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day: %s, Date: %d, Activity: %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}

// Main function
int main() {
    struct Day* calendar = create();
    read(calendar);
    display(calendar);

    // Free allocated memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    free(calendar);

    return 0;
}