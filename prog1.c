#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each day of the week
struct Day {
    char *dayName;   // Dynamically allocated string for the name of the day
    int date;        // Date of the day (integer)
    char *activity;  // Dynamically allocated string for the activity description
};
// Function prototypes
struct Day* createCalendar();
void readCalendar(struct Day *calendar);
void displayCalendar(struct Day *calendar);
void freeCalendar(struct Day *calendar);
//main function
int main() {
    // Create the calendar
    struct Day *calendar = createCalendar();
    // Read data into the calendar
    readCalendar(calendar);
    // Display the calendar
    displayCalendar(calendar);
    // Free the allocated memory
    freeCalendar(calendar);
    return 0;
}
// Function to create a dynamically allocated array for 7 days
struct Day* createCalendar() {
    struct Day* calendar = (struct Day*) malloc(7 * sizeof(struct Day));
    for (int i = 0; i < 7; i++) {
        calendar[i].dayName = NULL;
        calendar[i].activity = NULL;
    }
    return calendar;
}

// Function to read data into the calendar
void readCalendar(struct Day *calendar) {
    for (int i = 0; i < 7; i++) {
        // Read day name using %ms to allocate memory automatically
        char buffer[100];
        printf("Enter name of day %d: ", i + 1);
        scanf("%99s", buffer);
        calendar[i].dayName = strdup(buffer);
        // Read date
        printf("Enter date for %s: ", calendar[i].dayName);
        scanf("%d", &calendar[i].date);

        // Read activity description using %ms to allocate memory automatically
        printf("Enter activity for %s: ", calendar[i].dayName);
        scanf("%99s", buffer);
        calendar[i].activity = strdup(buffer);
    }
}
// Function to display the calendar
void displayCalendar(struct Day *calendar) {
    printf("\nWeek's Activity Report:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day: %s, Date: %d, Activity: %s\n", calendar[i].dayName, calendar[i].date, calendar[i].activity);
    }
}

// Function to free the dynamically allocated memory
void freeCalendar(struct Day *calendar) {
    for (int i = 0; i < 7; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
    free(calendar);
}
