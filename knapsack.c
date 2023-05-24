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

int knapsack(int v[], int w[], int n, int W, int M[n][W]) 
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
				M[i][j] = max(M[i-1][j], v[i]+M[i-1][j-w[i]]);
		}
    } 

	printmatrix(n, W, M);
    return M[n-1][W-1];
}

int main()
{
	int v[] = {0, 2, 4, 8, 9};
	int w[] = {0, 2, 2, 5, 1};
	//esempio slide
	//int v[] = {0, 1, 6, 18, 22, 28};
	//int w[] = {0, 1, 2, 5, 6, 7};
	int n = sizeof(v)/sizeof(v[0]);
	int W = 7;
	int M[n][W];
	printf("\nLa soluzione ottima ha valore %d\n", knapsack(v, w, n, W, M));
	return 0;
}