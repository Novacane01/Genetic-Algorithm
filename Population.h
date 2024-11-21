#ifndef POPULATION_H
#define POPULATION_H

#include <SFML/Graphics.hpp>
#include "DNA.h"
#include <math.h>


const extern int populationSize;
extern float mutationRate;
extern float WINDOW_LENGTH, WINDOW_WIDTH;

class Population {
public:
	Population();
	DNA *population = nullptr;
	void calcFitness();
	sf::Vector2f velocity;
	int generation = 1;
	float avgFitness = 0.f;
	float highestFitness = 0.f;
	DNA selection(DNA *);

};

#endif