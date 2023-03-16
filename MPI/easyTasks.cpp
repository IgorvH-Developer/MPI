#include <stdio.h>
#include "mpi.h"
#include <cmath>
#include <iostream>

using namespace std;


void easyTask1(int argc, char* argv[])
{
	int proc_number, proc_count, message;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &proc_count);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_number);


	if (proc_number == 0) {
		printf("Process %i from %i processes\n", proc_number, proc_count);
		/*for (int i = 1; i < proc_count; i++) {
			MPI_Recv(&message, 1, MPI_INT, i, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		}*/
	}
	else {
		//MPI_Send(&proc_number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		printf("Process %i from %i processes\n", proc_number, proc_count);
	}

	MPI_Finalize();
}




void easyTask2(int argc, char* argv[])
{
	int proc_number, proc_count, message;
	MPI_Status status;
	double t1 = 0, t2 = 0;



	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &proc_count);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_number);



	if (proc_number != 0) {
		MPI_Recv(&t1, 1, MPI_DOUBLE, proc_number - 1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		t2 = MPI_Wtime();
		printf("From process %i to %i take %f time", proc_number - 1, proc_number, t2 - t1);
	}

	if (proc_number != 7) {
		t1 = MPI_Wtime();
		MPI_Ssend(&t1, 1, MPI_DOUBLE, proc_number + 1, 0, MPI_COMM_WORLD);
	}
	

	MPI_Finalize();
}