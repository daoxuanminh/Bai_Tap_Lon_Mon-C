#include <stdio.h>
#include <stdlib.h>

int C(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;
    return C(k - 1, n - 1) + C(k, n - 1);
}

int main()
{
    FILE *fIn;
    fIn = fopen("TOHOP.INP.txt", "r");
    int n, k;
    while (fscanf(fIn, "%d %d\n", &n, &k) != EOF)
    {
        FILE *fOut = fopen("TOHOP.OUT.txt", "a+");
        fprintf(fOut, "%d\n", C(k, n));
        fclose(fOut);
    }
    fclose(fIn);

    return 0;
}
