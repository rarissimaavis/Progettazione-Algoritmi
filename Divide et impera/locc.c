#include <stdio.h>

int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else
	{
		if (b > c)
			return b;
		else
			return c;
	}
}

//complessità O(nlogn)
int locc(int A[], int l, int r) 
{
	if (l > r)
		return 0;

	if (l == r) 
		return 1;

	int c = (l+r)/2;
	
	int nl = locc(A, l, c);
	int nr = locc(A, c+1, r);

	int nc = 0, j = c;
	if (A[c] == A[c+1])
	{
		nc = nc + 2;
		while (j > l && A[j] == A[j-1])
		{
			j--;
			nc++;
		}
		j = c+1;
		while (j < r && A[j] == A[j+1])
		{
			j++;
			nc++;
		}
	}

	return max(nl, nr, nc);
}

int main()
{
	int A[] = {5, 4, 2, 2, 2, 2, 5, 5, 3, 2}
	int l = 0, r = 9;
	printf("\nIl massimo numero di occorrenze consecutive di un elemento è %d\n", locc(A, l, r));
	return 0;
}