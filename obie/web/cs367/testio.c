#include <stdio.h>
#include <mpi.h>

main(int argc, char* argv[]) {
	int x;
	MPI_Init(&argc, &argv);

	printf("Enter an integer\n");
	fflush(stdout);
	scanf("%d", &x);
	printf("Read x = %d\n", x);
	fflush*stdout);

	MPI_Finalize();
}