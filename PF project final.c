#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

int getDayOfWeek(int year, int month, int day) {
    int century, yearInCentury, dayOfWeek;

    if (month <= 2) {
        month += 12;
        year--;
    }

    century = year / 100;
    yearInCentury = year % 100;

    dayOfWeek = (day + 13 * (month + 1) / 5 + yearInCentury + yearInCentury / 4 + century / 4 + 5 * century) % 7;

    // Adjust for C's 0-based indexing of days (0 = Saturday, 1 = Sunday, etc.)
    dayOfWeek = (dayOfWeek + 6) % 7;

    return dayOfWeek;
}

void printCalendar(int year, int month) {
    int daysInMonth, dayOfWeek, day, i;

    // Array to store the number of days in each month
    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check if it's a leap year and update February's days accordingly
    if (isLeapYear(year))
        daysPerMonth[1] = 29;

    // Get the day of the week for the 1st day of the specified month
    dayOfWeek = getDayOfWeek(year, month, 1);

    // Print the month and year
    printf("\n----------- %d / %02d -----------\n", year, month);

    // Print the days of the week
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Adjust the starting position of the first day
    for (i = 0; i < dayOfWeek; i++)
        printf("     ");

    // Print the dates
    daysInMonth = daysPerMonth[month - 1];
    for (day = 1; day <= daysInMonth; day++) {
        printf("%-5d", day);

        if ((dayOfWeek + day) % 7 == 0)
            printf("\n");
    }

    printf("\n");
}

int main() {
    // new comment
    int year, month;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    printCalendar(year, month);

    return 0;
}
