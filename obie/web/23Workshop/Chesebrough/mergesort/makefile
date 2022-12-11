CC = icpc
CFLAGS = -O0

all:    clean M1 M2 M3

M1: mergesort.cpp
	$(CC) mergesort.cpp $(CFLAGS) -o M1

M2: mergesortOMP.cpp
	$(CC) mergesortOMP.cpp  $(CFLAGS) -openmp -o M2


M3: mergesortCilk.cpp
	$(CC) mergesortCilk.cpp  $(CFLAGS)  -o M3

clean:
	rm -f M1 M2 M3 a.out
