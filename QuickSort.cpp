#include <stdio.h>
#include <stdlib.h>


/* Quick Sort */
// Function to Merge Arrays L and R into A. 
// LSize = number of elements in L
// RSize = number of elements in R. 
void Merge(int* A, int *L, int *R, int LSize, int RSize ) {
	int i = 0, k = 0, j = 0;
	
	while (i < LSize) A[j++] = L[i++];
	while (k < RSize) A[j++] = R[k++];
	return;
}

// Recursive function to sort an array of integers. 
void QuickSort(int *A, int size) {
	if (size < 2) return;
	int *L = NULL, *R = NULL;
	int RSize = 0, LSize = 0;
	
	for (int i = 0; i < size; i++) {
		if (A[size - 2] < A[i]) {
			if ((R = (int *)realloc(R, (sizeof(int) * (RSize + 1)))) != NULL)
				R[RSize++] = A[i];
		}
		else 
			if ((L = (int *)realloc(L, (sizeof(int) * (LSize + 1)))) != NULL) 
				L[LSize++] = A[i];
	}

	QuickSort(L, LSize);
	QuickSort(R, RSize);
	Merge(A, L, R, LSize, RSize);
	free(L);
	free(R);
	return;
}

int main() {
	/* Code to test the QuickSort function. */

	int A[] = { 6,2,3,1,9,10,15,13,12,17 }; // creating an array of integers. 
	int numberOfElements;

	numberOfElements = sizeof(A) / sizeof(A[0]);
	// Calling quick sort to sort the array. 
	QuickSort(A, numberOfElements);

	//printing all elements in the array once its sorted.
	for (int i = 0; i < numberOfElements; i++) printf("%d\n", A[i]);
	return 0;
}