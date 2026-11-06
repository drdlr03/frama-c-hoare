# Taller Frama-C - Cuadrado por suma de impares

Verificamos con Frama-C y el plugin WP que la función `cuadrado(n)` calcula n²
sumando los primeros n impares (1 + 3 + 5 + ... + (2n-1) = n²). La terna que
probamos es:

```
{ 0 <= n <= 46340 }  cuadrado(n)  { \result == n*n }
```

## Archivos

- `src/cuadrado.c`: el programa con las anotaciones ACSL (corrección parcial)
- `src/cuadrado_total.c`: lo mismo pero con `loop variant` (corrección total)
- `src/errores/`: dos versiones con errores a propósito, Frama-C no las puede probar
- `tests/pruebas.c`: pruebas normales con gcc
- `informe/`: el informe en PDF y el .tex

## Cómo correrlo

Frama-C no corre en Windows, así que lo corrimos en un Codespace de GitHub
(Code → Codespaces → Create codespace on main), o desde VS Code con la extensión
GitHub Codespaces. El Codespace ya trae Docker, y con `DOCKER=1` se usa la imagen
oficial de Frama-C:

```bash
make verificar DOCKER=1        # correccion parcial -> 10 / 10
make verificar-total DOCKER=1  # correccion total   -> 17 / 17
make errores DOCKER=1          # tienen que fallar  -> 7 / 8 y 13 / 14
make pruebas                   # gcc                -> 9/9 pruebas correctas
```

La primera vez se demora unos minutos descargando la imagen.

Si ya tienen Frama-C instalado en Linux se puede correr sin el `DOCKER=1` (usa Z3).
