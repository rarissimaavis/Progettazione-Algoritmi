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

	int i, j, c = (l+r)/2, nc = 0, nl = 0, nr = 0;

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
		nl = liscons(A, l, i-1);

	if (r-j > nc)
		nr = liscons(A, j+1, r);

	return max(nl, nr, nc);
}

int main()
{
	int A[] = {5, 4, 3, 2, 3, 4, 5, 6, 3, 2};
	int l = 0, r = 9;
	printf("\nLa sottosequenza crescente più lunga ha lunghezza %d\n", liscons(A, l, r));
	return 0;
}