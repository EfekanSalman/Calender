#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getFirstDayOfMonth(int year, int month) {
	
	int day = 1;
	int y = year - (14 - month) / 12;
	int m = month + 12 * ((14 - month) / 12) - 2;
	int firstDay = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12 ) % 7;
	
	return firstDay;
	
}

int isLeapYear(int year) {
	
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	
}

void printCalender(int year, int month) {
	
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (isLeapYear(year)) {
		daysInMonth[1] = 29;
	}
	
	printf("\n %s %d\n",months[month - 1], year);
	printf(" S  M  T  W  T  F  S\n");
	
	int firstDay = getFirstDayOfMonth(year, month);
	for (int i = 0; i < firstDay; i++) {
		printf("  ");
	}
	
	for (int day = 1; day <= daysInMonth[month - 1]; day++) {
		printf("%3d", day);
		if  ((day + firstDay) % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");	
}


int main(int argc, char *argv[]) {
	
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	int year, month;
	char choice;
	
	year = tm.tm_year + 1900;
	month = tm.tm_mon + 1;
	
	printf("Do you want to enter a specific month and year? (y/n): ");
	scanf("%c", &choice);
	
	if (choice == 'y' || choice == 'Y') {
		
		printf("Enter a year: ");
		scanf("%d", &year);
		printf("Enter month (1-12): ");
		scanf("%d", &month);
		
		if (month < 1 || month > 12) {
			
			printf("Invalid month! Please enter a month between 1 and 12\n");
			return 1;	
		}	
	}
	
	printCalender(year, month);
	
	
	return 0;
}
