/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct date {
	int day;
	int month;
	int year;
};

typedef struct date Date;

Date getDateFromString(char *dob){
	Date date1;
	date1.day = 0; date1.month = 0; date1.year = 0;

	date1.day = (dob[0] - '0') * 10 + dob[1] - '0';
	date1.month = (dob[3] - '0') * 10 + dob[4] - '0';
	date1.year = (dob[6] - '0') * 1000 + (dob[7] - '0') * 100 + (dob[8] - '0') * 10 + (dob[9] - '0');

	return date1;
}

int structCompare(Date date1, Date date2)
{
	if (date1.year < date2.year)
		return 1;
	else if (date1.year > date2.year)
		return 2;
	else {
		if (date1.month < date2.month)
			return 1;
		else if (date1.month > date2.month)
			return 2;
		else {
			if (date1.day < date2.day)
				return 1;
			else if (date1.day > date2.day)
				return 2;
			else
				return 0;
		}
	}
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if ((Arr == NULL) || (len < 0))
		return -1;

	int count = 0, index = 0;
	Date date1, date2;

	while (index < len){

		date2 = getDateFromString(date);
		date1 = getDateFromString(Arr[index].date);

		if (structCompare(date1, date2) == 2)
			count++;
		index++;
	}
	return count;
}
