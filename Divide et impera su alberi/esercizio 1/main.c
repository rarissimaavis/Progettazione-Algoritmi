#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "Btree.h"

/*
Esercizio divide et impera pa

f(v) = elemento di v elevato alla profondità di v se v è una foglia
       elemento di v elevato alla profondità di v + somma dei valori f(c) dei figli altrimenti 
*/

int main(void)
{
    int a[8] = {100,19,36,17,3,25,1,2};
    Btree t = newBtree();
    t = input_Btree(a, 0, 8);
    output_Btree(t, 0);

    printf("\nEsercizio pa divide et impera su alberi: %d\n", f(t, 0));
}
