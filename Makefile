CC=g++ -std=c++11
files = main.cpp bmp/bmp.c
hellomake: main.cpp bmp/bmp.c 
	$(CC) $(files)