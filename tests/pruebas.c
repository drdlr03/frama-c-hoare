#include <stdio.h>

int cuadrado(int n);

int main(void) {
    int casos[] = {0, 1, 2, 3, 7, 10, 100, 1000, 46340};
    int total = 9;
    int bien = 0;

    for (int k = 0; k < total; k++) {
        int n = casos[k];
        int r = cuadrado(n);
        if (r == n * n) {
            printf("cuadrado(%5d) = %10d   esperado %10d   OK\n", n, r, n * n);
            bien++;
        } else {
            printf("cuadrado(%5d) = %10d   esperado %10d   FALLO\n", n, r, n * n);
        }
    }
    printf("\n%d/%d pruebas correctas\n", bien, total);
    return 0;
}
