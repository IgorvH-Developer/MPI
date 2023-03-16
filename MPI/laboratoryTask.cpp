#include <stdio.h>
#include "mpi.h"
#include <cmath>
#include <iostream>

using namespace std;

int factorial(int x)
{
	if (x == 0)
		return 1;
	return x * factorial(x - 1);
}


double besselFunction(double x) {
	double eps = pow(10, -5), sum_sequnce = 0, step = 1;

	for (int k = 0; k < 10; k++) {
		sum_sequnce += step = pow(-1, k) * pow(x / 2, 2 * k) / (factorial(k) * factorial(1 + k));
		//cout << "sum " << sum_sequnce << " step " << step << endl;
	}

	return x / 2 * sum_sequnce;
}



void laboratoryTask(int argc, char* argv[])
{
	int proc_number, proc_count, i, message;
	MPI_Status status;

	double a = 0, b = 10, delta = 0.4;
	int points_count = (int)ceil((b - a) / delta);

	double* function_values = new double[points_count];
	for (int i = 0; i < points_count; i++)
		function_values[i] = 0;
	double* main_function_values = new double[points_count];
	for (int i = 0; i < points_count; i++)
		main_function_values[i] = 0;

	int k, i1, i2;


	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &proc_count);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_number);

	// Для каждого процесса определяем точки, в которых будут вычислены значения функции
	k = (int)floor(points_count / proc_count);
	i1 = k * proc_number;
	i2 = k * (proc_number + 1);
	if (proc_number == proc_count - 1)
		i2 = points_count;

	// Вычисляем значения функции
	cout << proc_number << " - process compute points from " << i1 << " to " << i2 << endl;
	for (int i = i1; i < i2; i++) {
		if (i == points_count)
			function_values[i] = besselFunction(b);
		else
			function_values[i] = besselFunction(i * delta);
	}

	// Объединяем вычисленные значения в один массив
	MPI_Reduce(function_values, main_function_values, points_count, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);


	if (proc_number == 0) {
		cout << "\na = " << a << " b = " << b << " delta = " << delta << "\n\n";

		// Выводим все вычисленные значения функций
		cout << "\nFunction values\n" << endl;
		for (int i = 0; i < points_count; i++)
			cout << "point " << i << " = " << main_function_values[i] << endl;
		cout << endl;
	}
	else {
		MPI_Send(&proc_number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}


	MPI_Finalize();
}