# make verificar        -> correccion parcial
# make verificar-rte    -> parcial + desbordamientos
# make verificar-total  -> correccion total
# make errores          -> versiones con errores (deben fallar)
# make pruebas          -> pruebas con gcc
#
# En Codespaces agregar DOCKER=1, ej: make verificar DOCKER=1

FRAMAC  = frama-c
PROVER  = z3

ifdef DOCKER
FRAMAC  = docker run --rm -v $(CURDIR):/work -w /work framac/frama-c:32.1 frama-c
PROVER  = alt-ergo
endif

WP      = -wp -wp-prover $(PROVER) -wp-timeout 10
# frama-c 27+ tambien pide probar que termina (eso es correccion total), lo quitamos
PARCIAL = -generated-spec-custom terminates:skip

verificar:
	$(FRAMAC) $(WP) $(PARCIAL) src/cuadrado.c

verificar-rte:
	$(FRAMAC) $(WP) $(PARCIAL) -wp-rte src/cuadrado.c

verificar-total:
	$(FRAMAC) $(WP) -wp-rte src/cuadrado_total.c

errores:
	-$(FRAMAC) $(WP) $(PARCIAL) src/errores/sin_invariante_impar.c
	-$(FRAMAC) $(WP) $(PARCIAL) -wp-rte src/errores/sin_cota_superior.c

pruebas:
	gcc -std=c99 -Wall -o pruebas src/cuadrado.c tests/pruebas.c
	./pruebas

limpiar:
	rm -rf pruebas .frama-c

.PHONY: verificar verificar-rte verificar-total errores pruebas limpiar
