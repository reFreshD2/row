#include <iostream>
#include "num_threads.h"
#include "interface.h"
#include "experiments.h"
#include <math.h>

size_t element_count = 100000000u;

double accumuate_sequential()
{
	unsigned i;
	double S = 0;
	for (i = 0; i < element_count; ++i) {
		double elem;
		if ((i & 1) == 0)
        		elem = 1.0/(i+1.0);
        	 else
        		elem = -1.0/(i+1.0);
        		
		S += elem;
		}
	return S;
}


int main(int argc, char **argv) {
    printf("%g\n",accumuate_sequential());
    printf("------------С++-------------\n");
    printf("==False sharing==\n");
    run_experiments_for(element_count, cpp_accumulate_false_sharing);
    printf("==Alignment==\n");
    run_experiments_for(element_count, cpp_accumulate_aligned);
    printf("==Atomic==\n");
    run_experiments_for(element_count, cpp_accumulate_atomic);
    printf("==Critical==\n");
    run_experiments_for(element_count, cpp_accumulate_mutex);
    printf("==Reduction (static)==\n");
    run_experiments_for(element_count, cpp_accumulate_reduction_static);
    printf("------------OpenMP-------------\n");
    printf("==False sharing==\n");
	run_experiments_for(element_count, omp_accumulate_false_sharing);
	printf("==Alignment==\n");
	run_experiments_for(element_count, omp_accumulate_aligned);
	printf("==Atomic==\n");
	run_experiments_for(element_count, omp_accumulate_atomic);
	printf("==Critical==\n");
	run_experiments_for(element_count, omp_accumulate_critical);
	printf("==Reduction (static)==\n");
	run_experiments_for(element_count, omp_accumulate_reduction_static);
	printf("==Reduction (dynamic)==\n");
	run_experiments_for(element_count, omp_accumulate_reduction_dynamic);
    return 0;
}
