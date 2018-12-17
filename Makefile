all: saida
	@echo " "
	@echo "Compilacao concluida!!"
	@echo " "

saida: FileManager.o Huffman.o main.o
	g++ -o saida FileManager.o Huffman.o main.o

FileManager.o: FileManager.cpp FileManager.h
	g++ -o FileManager.o -c FileManager.cpp

Huffman.o: Huffman.cpp Huffman.h
	g++ -o Huffman.o -c Huffman.cpp

main.o: main.cpp Huffman.h FileManager.h
	g++ -o main.o -c main.cpp
