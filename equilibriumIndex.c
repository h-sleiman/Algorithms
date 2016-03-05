#include <stdio.h>
#include <stdlib.h>

/*
 * This function executes in O(2 n) in the worst case 
 */
int equilibriumIndex(int* A, int N){
	int* Left = (int *)malloc(sizeof(int) * N - 1);
	int bI = N - 1, leftSum = 0, rightSum = 0;

	for(int i = 0 ; i < N - 1; i++){
		leftSum += A[i];
		Left[i] = leftSum;
	}
	for(int i = 0 ; i < N - 1; i++, bI--){
		if( Left[bI - 1] == rightSum )
			printf("indices are: %d\n", bI);
		rightSum += A[bI];
	}
		

	return 0;
}

int main()
{
	int A[] = { -1, 3, -4, 5, 1, -6, 2, 1 };
	int N = sizeof(A) / sizeof(A[0]);

	equilibriumIndex(A, N);

	return 0;
}

