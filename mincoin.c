#include <stdio.h>

int min(int a, int b)
{
	if (a < b)
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

int mincoin(int c[], int n, int V, int M[n][V]) 
{
	for (int i = 1; i < n; i++)
		M[i][0] = 0;
	
	for (int v = 1; v < V; v++)
		M[1][v] = v;

    for (int i = 2; i < n; i++) 
    {
        for (int v = 1; v < V; v++) 
        {
          	if (v < c[i]) 
				M[i][v] = M[i-1][v];

			else
				M[i][v] = min(1+M[i][v-c[i]], M[i-1][v]);
        }  
    } 

	printmatrix(n, V, M);
    return M[n-1][V-1];
}

int main()
{
	int c[] = {0, 1, 2, 4};
	int n = sizeof(c)/sizeof(c[0]);
	int V = 7;
	int M[n][V];
	printf("\nLa soluzione ottima è composta da %d monete\n", mincoin(c, n, V, M));
	return 0;
}