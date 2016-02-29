/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>

void swap(int *arr, int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return;
}

void qusort(int * arr, int left, int right)
{
	int i, last;

	if (left >= right)
		return;

	swap(arr, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++){
		if (arr[i] < arr[left])
			swap(arr, ++last, i);
	}
	swap(arr, left, last);
	qusort(arr, left, last - 1);
	qusort(arr, last + 1, right);
	return;
}

int findSingleOccurenceNumber(int *A, int len) {

	if ((A == NULL) || (len < 0))
		return -1;

	int ind = 0;
	qusort(A, 0, len - 1);

	while (ind < len){
		if (A[ind] == A[ind + 1])
			ind += 3;
		else return A[ind];
	}
}