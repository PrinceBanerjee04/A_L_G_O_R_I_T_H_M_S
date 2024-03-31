#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l1, int u1, int l2, int u2)
{
    int p, q, j, n;
    int d[100];
    p = l1;
    q = l2;
    n = 0;
    while (p <= u1 && q <= u2)
    {
        if (a[p] < a[q])
            d[n++] = a[p++];
        else
            d[n++] = a[q++];
    }
    while (p <= u1)
    {
        d[n++] = a[p++];
    }
    while (q <= u2)
    {
        d[n++] = a[q++];
    }
    for (q = l1, n = 0; q <= u2; q++, n++)
    {
        a[q] = d[n];
    }
}
