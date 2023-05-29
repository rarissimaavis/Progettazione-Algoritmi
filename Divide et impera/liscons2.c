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

//complessità O(n)
int liscons(int A[], int l, int r) 
{
	if (l > r)
		return 0;

	if (l == r) 
		return 1;

	int c = (l+r)/2, nc = 0, nl = 0, nr = 0, i = c, j = c+1;

	if (A[c] < A[c+1])
	{
		nc = nc+2;
		i = c;
		while (i > l && A[i] > A[i-1])
		{
			i--;
			nc++;
		}
		j = c+1;
		while (j < r && A[j] < A[j+1])
		{
			j++;
			nc++;
		}
	}

	if (i > nc) 
		nl = liscons(A, l, i);

	if (r-j > nc)
		nr = liscons(A, j, r);

	return max(nl, nr, nc);
}

int main()
{
	int A[] = {9, 9, 9, 8, 8, 4, 5, 1, 1, 1};
	int l = 0, r = 9;
	printf("\nLa sottosequenza crescente più lunga ha lunghezza %d\n", liscons(A, l, r));
	return 0;
}