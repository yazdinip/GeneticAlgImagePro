#include "a4.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
    double sum = 0;
    for (int i = 0; i < image_size; i++) {
        sum += (double)((A[i].r - B[i].r)*(A[i].r - B[i].r))
                + (double)((A[i].g - B[i].g)*(A[i].g - B[i].g))
                + (double)((A[i].b - B[i].b)*(A[i].b - B[i].b));
    }
    return sqrt(sum);
}
void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
    int image_size = individual[0].image.width * individual[0].image.height;
    for (int i = 0; i < population_size; i++) {
        individual[i].fitness=comp_distance(image, individual[i].image.data, image_size);
    }
}
