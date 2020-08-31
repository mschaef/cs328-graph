.PHONY: clean

sources = hamiltonian.c graph.c test-graphs.c
all = ${sources} graph.h test-graphs.h

all: hamiltonian.exe hamiltonian-debug.exe

clean:
	rm hamiltonian.exe hamiltonian-debug.exe

hamiltonian.exe: ${all} Makefile
	gcc ${sources} -Wall -o $@

hamiltonian-debug.exe: ${all} Makefile
	gcc ${sources} -Wall -o $@ -D DEBUG
