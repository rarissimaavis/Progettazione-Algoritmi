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
int maxsum(int A[], int l, int r) 
{
	if (l > r)
		return 0;

	if (l == r) 
		return A[l];

	int c = (l+r)/2;
	
	int suml = maxsum(A, l, c);
	int sumr = maxsum(A, c+1, r);

	int sumc = 0, sumctemp = 0, j = c;
	while (j >= l)
	{
		sumctemp += A[j];
		if (sumctemp > sumc)
			sumc = sumctemp;
		j--;
	}
	j = c+1;
	while (j <= r)
	{
		sumctemp += A[j];
		if (sumctemp > sumc)
			sumc = sumctemp;
		j++;
	}

	return max(suml, sumr, sumc);
}

int main()
{
	int A[] = {1, 8, 9, -3};
	int l = 0, r = 3;
	printf("\nLa sottosequenza di somma massima ha somma %d\n", maxsum(A, l, r));
	return 0;
}