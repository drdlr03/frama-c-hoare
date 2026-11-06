/*@ requires 0 <= n <= 46340;
    assigns  \nothing;
    ensures  \result == n * n;
*/
int cuadrado(int n) {
    int i = 0;       // cuantos impares llevamos sumados
    int s = 0;       // la suma hasta ahora
    int impar = 1;   // el siguiente impar que toca sumar

    /*@ loop invariant rango:  0 <= i <= n;
        loop invariant suma:   s == i * i;
        loop invariant impar:  impar == 2 * i + 1;
        loop assigns i, s, impar;
    */
    while (i < n) {
        s = s + impar;
        impar = impar + 2;
        i = i + 1;
    }
    return s;
}
