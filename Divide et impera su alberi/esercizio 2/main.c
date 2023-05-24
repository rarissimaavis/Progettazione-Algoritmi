#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "Btree.h"

/*
Esercizio divide et impera pa
L'algoritmo restituisce il numero di nodi che contengono x nell'albero t
*/

int main(void)
{
    int x = 3;
    int a[8] = {100,19,36,17,3,25,1,3};
    Btree t = newBtree();
    t = input_Btree(a, 0, 8);
    output_Btree(t, 0);

    printf("\nNumero di nodi che contengono l'elemento x = %d: %d\n", x, conta(t, x));
}
