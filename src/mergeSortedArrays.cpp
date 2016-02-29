/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

typedef struct transaction TRANS;


struct date {
	int day;
	int month;
	int year;
};

typedef struct date Date;

Date getDateFromString2(char *dob){
	Date date1;
	date1.day = 0; date1.month = 0; date1.year = 0;

	date1.day = (dob[0] - '0') * 10 + dob[1] - '0';
	date1.month = (dob[3] - '0') * 10 + dob[4] - '0';
	date1.year = (dob[6] - '0') * 1000 + (dob[7] - '0') * 100 + (dob[8] - '0') * 10 + (dob[9] - '0');

	return date1;
}

int structCompare2(Date date1, Date date2)
{
	if (date1.year <= date2.year)
		return 1;
	else if (date1.year > date2.year)
		return 2;
	else {
		if (date1.month <= date2.month)
			return 1;
		else if (date1.month > date2.month)
			return 2;
		else {
			if (date1.day <= date2.day)
				return 1;
			else if (date1.day > date2.day)
				return 2;
			else
				return 0;
		}
	}
}

int dateComapare(char *date1, char*date2)
{
	Date date11 = getDateFromString2(date1);
	Date date22 = getDateFromString2(date2);

	return structCompare2(date11, date22);
}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if ((A == NULL) || (B == NULL) || (ALen < 0) || (BLen < 0))
		return NULL;

	TRANS * mergedTrans = (TRANS*)calloc((ALen + BLen), sizeof(TRANS));


	int ind1 = 0, ind2 = 0, ind3 = 0;

	while (ind3 < (ALen + BLen - 1)){
		while ((dateComapare(A[ind1].date, B[ind2].date) == 1) && (ind1 < ALen)){
			strcpy(mergedTrans[ind3].date, A[ind1].date);
			mergedTrans[ind3].amount = A[ind1].amount;
			strcpy(mergedTrans[ind3].description, A[ind1].description);

			ind1++;
			ind3++;
		}
		printf("\n%d\n", ind1);
		if (ind1 == ALen)
			break;
		
		while ((dateComapare(B[ind2].date, A[ind1].date) == 1) && (ind2 < BLen)){
			strcpy(mergedTrans[ind3].date, B[ind2].date);
			mergedTrans[ind3].amount = B[ind2].amount;
			strcpy(mergedTrans[ind3].description, B[ind2].description);

			ind2++;
			ind3++;
		}
		printf("\n%d\n", ind2);

		if (ind2 == BLen)
			break;
		
	}
	while (ind2 < BLen){
		strcpy(mergedTrans[ind3].date, B[ind2].date);
		mergedTrans[ind3].amount = B[ind2].amount;
		strcpy(mergedTrans[ind3].description, B[ind2].description);

		ind2++;
		ind3++;
	}
	while (ind1 < ALen){
		strcpy(mergedTrans[ind3].date, A[ind1].date);
		mergedTrans[ind3].amount = A[ind1].amount;
		strcpy(mergedTrans[ind3].description, A[ind1].description);

		ind1++;
		ind3++;
	}

	return mergedTrans;
}