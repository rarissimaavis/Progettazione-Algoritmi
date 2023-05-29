#include <stdio.h>

//complessità O(n)
int cerca(int A[], int x, int l, int r) 
{
	if (l > r)
		return 0;

	int c = (l+r)/2;
	
	if (A[c] == x)
		return 1;

	return cerca(A, x, l, c-1) + cerca(A, x, c+1, r);
}

int main()
{
	int A[] = {3, 4, 1, 2, 3, 1, 4, 2, 1, 4};
	int l = 0, r = 9, x = 4;
	printf("\nL'elemento x compare %d volte in A\n", cerca(A, x, l, r));
	return 0;
}