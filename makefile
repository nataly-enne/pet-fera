#makefile - projeto pet fera

exe:	pet_fera_main.o	pet_fera_corpo.o	pet_fera_funcoes.o	
	g++	-o	exe	-Wall	-ansi	-pedantic	-pg	pet_fera_main.cpp	pet_fera_corpo.o	pet_fera_funcoes.o	-std=c++11

pet_fera_main.o:	pet_fera_main.cpp	pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-pg	-c	pet_fera_main.cpp	-std=c++11

pet_fera_corpo.o:	pet_fera_corpo.cpp	pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-pg	-c	pet_fera_corpo.cpp	-std=c++11

pet_fera_funcoes.o:	pet_fera_funcoes.cpp	pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-pg	-c	pet_fera_funcoes.cpp	-std=c++11

clear:
	rm -rf *.o
