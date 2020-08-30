.PHONY: clean

all: hamiltonian.exe hamiltonian-debug.exe

clean:
	rm hamiltonian.exe hamiltonian-debug.exe

hamiltonian.exe: hamiltonian.c graph.c graph.h Makefile
	gcc hamiltonian.c graph.c  -o $@

hamiltonian-debug.exe: hamiltonian.c graph.c graph.h Makefile
	gcc hamiltonian.c graph.c  -o $@ -D DEBUG
