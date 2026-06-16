/*
Program Name: Project1_MoinuddinTashrif.c
Programmer: Md Moinuddin Tashrif
Class: CS 3335
Project: 01
*/ 
 
#include <stdio.h>
 
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
 
int daysInMonth(int month, int year) {
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Index 0 is unused
    if (month == 2 && isLeapYear(year)) {
        return 29; // February in a leap year
    }
    return daysInMonths[month];
}
 
int main() {
    int year1, month1, day1;
    int year2, month2, day2;
    int dif = 0;
 
    printf("Enter the first date (MM DD YYYY): ");
    scanf("%d %d %d", &month1, &day1, &year1);
    printf("%02d/%02d/%d\n", month1, day1, year1);
 
    if (month1 < 1 || month1 > 12 || day1 < 1 || day1 > daysInMonth(month1, year1)) {
        printf("Invalid date: %02d/%02d/%d\n", month1, day1, year1);
        return 1;
    }
 
    printf("Enter the second date (MM DD YYYY): ");
    scanf("%d %d %d", &month2, &day2, &year2);
    printf("%02d/%02d/%d\n", month2, day2, year2);
 
    if (month2 < 1 || month2 > 12 || day2 < 1 || day2 > daysInMonth(month2, year2)) {
        printf("Invalid date: %02d/%02d/%d\n", month2, day2, year2);
        return 1;
    }
 
    // Calculate the difference in days
    if (year1 > year2 || (year1 == year2 && (month1 > month2 || (month1 == month2 && day1 > day2)))) {
        // Swap dates if the first date is later than the second
        int temp;
        temp = year1; year1 = year2; year2 = temp;
        temp = month1; month1 = month2; month2 = temp;
        temp = day1; day1 = day2; day2 = temp;
    }
 
    // Calculate total days from the start of each date to a reference point
    for (int y = year1; y < year2; y++) {
        dif += isLeapYear(y) ? 366 : 365;
    }
 
    for (int m = 1; m < month1; m++) {
        dif -= daysInMonth(m, year1);
    }
    dif -= day1;
 
    for (int m = 1; m < month2; m++) {
        dif += daysInMonth(m, year2);
    }
    dif += day2 + 1;
 
    printf("Number of dates between the two dates is: %d\n", dif);
 
    return 0;
}
