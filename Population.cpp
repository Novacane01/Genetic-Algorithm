#include "stdafx.h"
#include "Population.h"

Population::Population() {
	population = new DNA[populationSize];
	for (int i = 0;i < populationSize;i++) {
		population[i] = DNA();
	}
}

void Population::calcFitness() {
	float sum = 0.f;
	highestFitness = 0;
	for (int i = 0;i < populationSize;i++) {
		sum += population[i].fitness;
	}
	for (int i = 0;i < populationSize;i++) {
		population[i].fitness /= sum;
		if (population[i].fitness > highestFitness) {
			highestFitness = population[i].fitness;
		}
	}
	avgFitness = sum / populationSize;
}

DNA Population::selection(DNA *popcopy) {
	int index = -1;
	float r = (float)rand() / RAND_MAX;
	while (r > 0) {
		r -= popcopy[++index].fitness;
	}
	return popcopy[index];
}

