#makefile - projeto pet fera

exe:	pet_fera_main.o libtratadoreslib.so libveterinarioslib.so libanimaislib.so libfuncoesprinclib.so libfuncoesauxlib.so
	g++	-o	exe	-Wall	-ansi	-pedantic pet_fera_main.o -L -l libtratadoreslib.so libveterinarioslib.so libanimaislib.so libfuncoesprinclib.so libfuncoesauxlib.so -std=c++11

pet_fera_main.o:	pet_fera_main.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0 -c	pet_fera_main.cpp -std=c++11

clear:
	rm -rf *.o
