#include <stdio.h>

int min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return a;
		else
			return c;
	}
	else
	{
		if (b < c)
			return b;
		else
			return c;
	}
}

//complessità O(nlogn)
int minsum(int A[], int l, int r) 
{
	if (l > r)
		return 0;

	if (l == r) 
		return A[l];

	int c = (l+r)/2;
	
	int suml = minsum(A, l, c);
	int sumr = minsum(A, c+1, r);

	int sumc = 1000, sumctemp = 0, j = c;
	while (j >= l)
	{
		sumctemp += A[j];
		if (sumctemp < sumc)
			sumc = sumctemp;
		j--;
	}
	j = c+1;
	while (j <= r)
	{
		sumctemp += A[j];
		if (sumctemp < sumc)
			sumc = sumctemp;
		j++;
	}

	return min(suml, sumr, sumc);
}

int main()
{
	int A[] = {-2, -5, -3, -1, -7};
	int l = 0, r = 4;
	printf("\nLa sottosequenza di somma minima ha somma %d\n", minsum(A, l, r));
	return 0;
}