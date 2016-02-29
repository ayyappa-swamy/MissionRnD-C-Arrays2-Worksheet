/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

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

Date getDateFromStrng(char *dob){
	Date date1;
	date1.day = 0; date1.month = 0; date1.year = 0;

	date1.day = (dob[0] - '0') * 10 + dob[1] - '0';
	date1.month = (dob[3] - '0') * 10 + dob[4] - '0';
	date1.year = (dob[6] - '0') * 1000 + (dob[7] - '0') * 100 + (dob[8] - '0') * 10 + (dob[9] - '0');

	return date1;
}

int structComparision(Date date1, Date date2)
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

int dateComaparision(char *date1, char*date2)
{
	Date date11 = getDateFromStrng(date1);
	Date date22 = getDateFromStrng(date2);

	return structComparision(date11, date22);
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if ((A == NULL) || (B == NULL) || (ALen < 0) || (BLen < 0))
		return NULL;

	struct transaction* commonArray = (struct transaction *)calloc(((ALen>BLen) ? BLen : ALen), sizeof(struct transaction));

	int index1 = 0, index2 = 0, index3 = 0, comp;

	while ((index1 < ALen) && (index2 < BLen)){
		comp = dateComaparision(A[index1].date, B[index2].date);
		if (comp == 1)
			index1++;
		else if (comp == 2)
			index2++;
		else {
			strcpy(commonArray[index3].date, A[index1].date);
			commonArray[index3].amount = A[index1].amount;
			strcpy(commonArray[index3].description, A[index1].description);
			index3++;
			index2++;
			index1++;
		}
	}

	if (index3 == 0)
		return NULL;
	else
		return commonArray;
}