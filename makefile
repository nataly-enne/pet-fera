# makefile - projeto pet fera

all: exe exportar

exe:	pet_fera_main.o	pet_fera_corpo.o pet_fera_pesquisar.o pet_fera_cadastrar.o pet_fera_carregamento.o pet_fera_editar.o pet_fera_remover.o	pet_fera_consulta_p_func.o pet_fera_checagem.o
	g++	-o	exe	-Wall	-ansi	-pedantic pet_fera_main.o pet_fera_corpo.o pet_fera_pesquisar.o pet_fera_cadastrar.o pet_fera_carregamento.o pet_fera_editar.o pet_fera_remover.o pet_fera_consulta_p_func.o pet_fera_checagem.o -std=c++11

pet_fera_main.o:	pet_fera_main.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0 -c	pet_fera_main.cpp -std=c++11

pet_fera_corpo.o:	pet_fera_corpo.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-c	pet_fera_corpo.cpp -std=c++11

pet_fera_pesquisar.o:	pet_fera_pesquisar.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-c	pet_fera_pesquisar.cpp -std=c++11

pet_fera_cadastrar.o:	pet_fera_cadastrar.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-c	pet_fera_cadastrar.cpp -std=c++11

pet_fera_carregamento.o:	pet_fera_carregamento.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-c	pet_fera_carregamento.cpp -std=c++11

pet_fera_editar.o:	pet_fera_editar.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-c	pet_fera_editar.cpp -std=c++11

pet_fera_remover.o:	pet_fera_remover.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0 -c	pet_fera_remover.cpp -std=c++11

pet_fera_consulta_p_func.o:	pet_fera_consulta_p_func.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-c	pet_fera_consulta_p_func.cpp -std=c++11

pet_fera_checagem.o:	pet_fera_checagem.cpp pet_fera.h
	g++	-Wall	-ansi	-pedantic	-g	-O0	-c	pet_fera_checagem.cpp -std=c++11

exportar:	pet_fera_auxiliar.cpp	libpetfera.so pet_fera.h
	g++	-Wall	-ansi	-pedantic -o	exportar	 pet_fera_auxiliar.cpp -L. -lpetfera -std=c++11

clear:
	rm -rf *.o
