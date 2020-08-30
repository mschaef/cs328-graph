.PHONY: clean

all: hamiltonian.exe

clean:
	rm hamiltonian.exe

hamiltonian.exe: hamiltonian.c graph.c graph.h
	gcc hamiltonian.c graph.c  -o $@
