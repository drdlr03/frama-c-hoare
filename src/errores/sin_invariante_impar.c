// sin el invariante de impar, falla suma_preserved

/*@ requires 0 <= n <= 46340;
    assigns  \nothing;
    ensures  \result == n * n;
*/
int cuadrado(int n) {
    int i = 0;
    int s = 0;
    int impar = 1;

    /*@ loop invariant rango:  0 <= i <= n;
        loop invariant suma:   s == i * i;
        loop assigns i, s, impar;
    */
    while (i < n) {
        s = s + impar;
        impar = impar + 2;
        i = i + 1;
    }
    return s;
}
