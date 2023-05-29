#include <stdio.h>

//complessità O(n)
int findx(int A[], int x, int l, int r) 
{
    if (l > r)
        return 0;

    int c = (l+r)/2;
    
    if (A[c] == x)
        return 1;
    
    return findx(A, x, l, c-1) || findx(A, x, c+1, r);
}

int main()
{
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int l = 0, r = 10, x = 7;
	printf("\nL'elemento x si trova nell'array? (1 si/0 no) %d\n", findx(A, x, l, r));
	return 0;
}