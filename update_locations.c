#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int size;
int iters;

//Produces a random number in the the range [min, max]
float random_num(int min, int max)
{
	return min + rand() % (max + 1 - min);
}

//Generates a random list of length <size> consisting of #'s in the range [bound, -bound]
float * generate_random_list(int size, float bound)
{
	float* array;
	array = malloc(size * sizeof(int));
	if (!array)
	{
		perror("Memory bug or invalid size.");
		exit(-1);
	}

	for (int i = 0; i < size; i++)
	{
		array[i] = random_num(-bound, bound);
	}
	return array;
}

//Updates the vector coordinates
int update_coords(float x[], float y[], float z[], float vx[], float vy[], float vz[]) 
{
	for (int i = 0; i < size; i++)
	{
		x[i] = x[i] + vx[i];
		y[i] = y[i] + vy[i];
		z[i] = z[i] + vz[i];
	}
	return 0;
}

//utility function to sum the contents of an array.
float sum_array(float array[], int size)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	return sum;
}

int main(int argc, char *argv[] )
{
	//argc is the # of arguments passed
	//argv is [location, arg1, arg2]
	
	if (argc != 3)
	{
		printf("Required arguments: vector_length(n) and iterations_num(M)\n");
		exit(-1);
	}
	size = atoi(argv[1]);
	iters = atoi(argv[2]);
	
	//The seed for our random numbers
	srand((unsigned)size);

	//Creating arrays of random numbers
	float* x = generate_random_list(size, 1000.);
	float* y = generate_random_list(size, 1000.);
	float* z = generate_random_list(size, 1000.);
	float* vx = generate_random_list(size, 1.);
	float* vy = generate_random_list(size, 1.);
	float* vz = generate_random_list(size, 1.);
	
	//Timing update_coords and calculating mean time
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < iters; i++)
	{
		update_coords(x, y, z, vx, vy, vz);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	float t = end.tv_sec - start.tv_sec;
	float chksum = sum_array(x, size) + sum_array(y, size) + sum_array(z, size);
	unsigned int num_of_coords = size * iters;
	float mean_time = 1000000 * t / num_of_coords;
	printf("Mean time per coordinate: %fus \n", mean_time);
	printf("Final checksum is: %f \n", chksum);
	
	//Freeing up allocated memory used when creating the arrays
	free(x);
	free(y);
	free(z);
	free(vx);
	free(vy);
	free(vz);
	return 0;
}