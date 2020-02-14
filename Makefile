CC=g++ -std=c++11
files = main.cpp bmp/bmp.c vigenere/vigenere.cc
hellomake: 
	$(CC) $(files) -static