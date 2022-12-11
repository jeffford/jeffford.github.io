CC = icpc
CFLAGS = -O0
LFLAGS = -ltbb

all:    clean Q1 Q2 Q3

Q1: qsort.cpp
	$(CC) qsort.cpp $(CFLAGS) -o Q1 $(LFLAGS)

Q2: qsortOMP.cpp
	$(CC) qsortOMP.cpp  $(CFLAGS) -openmp -o Q2 $(LFLAGS)


Q3: qsortCilk.cpp
	$(CC) qsortCilk.cpp  $(CFLAGS) -openmp -o Q3 $(LFLAGS)

clean:
	rm -f Q1 Q2 Q3 a.out
