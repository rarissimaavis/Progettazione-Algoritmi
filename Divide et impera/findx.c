#include <stdio.h>

//complessità O(n)
int findx(int A[], int x, int l, int r) 
{
	if (l > r)
		return -1;

	int c = (l+r)/2;
	
	if (A[c] == x)
		return c;
	
	return findx(A, x, l, c-1) + findx(A, x, c+1, r) + 1;
}

int main()
{
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int l = 0, r = 10, x = 77;
	printf("\nL'elemento x si trova all'indice %d\n", findx(A, x, l, r));
	return 0;
}