#include <stdio.h>

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void printmatrix(int n, int V, int M[n][V])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", i);
		for (int j = 0; j < V; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
}

int subsums(int w[], int n, int W, int M[n][W]) 
{
	
	for (int j = 0; j < W; j++)
		M[0][j] = 0;

    for (int i = 1; i < n; i++) 
    {
		for (int j = 0; j < W; j++)
		{
			if (w[i] > j) 
				M[i][j] = M[i-1][j];

			else
				M[i][j] = max(M[i-1][j], w[i]+M[i-1][j-w[i]]);
		}
    } 

	printmatrix(n, W, M);
    return M[n-1][W-1];
}

int main()
{
	int w[] = {0, 2, 2, 3};
	int n = sizeof(w)/sizeof(w[0]);
	int W = 7;
	int M[n][W];
	printf("\nLa soluzione ottima ha somma %d\n", subsums(w, n, W, M));
	return 0;
}