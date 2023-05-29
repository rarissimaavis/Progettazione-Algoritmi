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
int maxocc(int A[], int l, int r) 
{
	if (l > r)
		return 0;

	if (l == r && A[l] == 2) 
		return 1;
	else if (l == r && A[l] != 2)
		return 0;

	int c = (l+r)/2, nc = 0, nl = 0, nr = 0, i = c, j = c;

	if (A[c] == 2)
	{
		i = c;
		while (i >= l && A[i] == 2)
		{
			i--;
			nc++;
		}
		j = c+1;
		while (j <= r && A[j] == 2)
		{
			j++;
			nc++;
		}
	}

	if (l-i > nc) 
		nl = maxocc(A, l, i-1);

	if (r-j > nc)
		nr = maxocc(A, j, r);

	return max(nl, nr, nc);
}

int main()
{
	int A[] = {2, 2, 3, 2, 2, 6, 2, 2, 3, 3};
	int l = 0, r = 9;
	printf("\nIl massimo numero di occorrenze consecutive di 2 è %d\n", maxocc(A, l, r));
	return 0;
}