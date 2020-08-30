.PHONY: clean

all: hamiltonian.exe

clean:
	rm hamiltonian.exe

hamiltonian.exe: hamiltonian.c
	gcc $< -o $@
