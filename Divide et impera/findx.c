#include <stdio.h>

//complessità O(n)
int findx(int A[], int x, int l, int r) 
{
	if (l > r)
		return -1;

	int c = (l+r)/2;
	
	if (A[c] == x)
		return c;
	
	int xl = findx(A, x, l, c-1);
	int xr = findx(A, x, c+1, r);

	if (xl != -1 && xr != -1)
		return xl;
	
	return xl + xr + 1;
}

int main()
{
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int l = 0, r = 10, x = 7;
	printf("\nL'elemento x si trova all'indice %d\n", findx(A, x, l, r));
	return 0;
}