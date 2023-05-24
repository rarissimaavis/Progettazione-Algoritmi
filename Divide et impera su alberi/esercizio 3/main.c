#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "Btree.h"

/*
Esercizio divide et impera pa
Scrivere un algoritmo ricorsivo che restituisce la somma degli elementi dei nodi (tranne la radice)
*/

int main(void)
{
    int x = 3;
    int a[8] = {100,19,36,17,3,25,1,2};
    Btree t = newBtree();
    t = input_Btree(a, 0, 8);
    output_Btree(t, 0);

    printf("\nSomma dei nodi dell'albero: %d\n", somma_nodi(t));
}
