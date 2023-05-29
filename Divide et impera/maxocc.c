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
int maxocc(int A[], int l, int r) 
{
	if (l > r)
		return 0;

	if (l == r && A[l] == 2) 
		return 1;
	else if (l == r && A[l] != 2)
		return 0;

	int c = (l+r)/2;
	
	int nl = maxocc(A, l, c);
	int nr = maxocc(A, c+1, r);

	int nc = 0, j;
	if (A[c] == 2)
	{
		j = c;
		while (j > l && A[j] == 2)
		{
			j--;
			nc++;
		}
		j = c+1;
		while (j < r && A[j] == 2)
		{
			j++;
			nc++;
		}
	}

	return max(nl, nr, nc);
}

int main()
{
	int A[] = {2, 2, 3, 6, 2, 2, 2, 2, 3, 3};
	int l = 0, r = 9;
	printf("\nIl massimo numero di occorrenze consecutive di 2 è %d\n", maxocc(A, l, r));
	return 0;
}