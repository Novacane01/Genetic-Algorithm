#include "DNA.h"
#include <iostream>
#include "Population.h"

DNA::DNA() {
	//srand(time(0));
	cell.setRadius(5.f);
	cell.setFillColor(sf::Color(255, 255, 255));
	cell.setPosition(WINDOW_WIDTH/2, WINDOW_LENGTH);
	velocity = rand() % 15 + 5;
	for (int i = 0;i < lifespan;i++) {
		paths[i] = sf::Vector2f((((float)rand()/RAND_MAX)*4-2)*velocity, (((float)rand() / RAND_MAX) * 2 - 1)*velocity);
	}
}

void DNA::Draw(sf::RenderWindow &window) {
	window.draw(cell);
}

void DNA::Update(float dt, int count) {
	if (!dead&&!finished) {
		cell.setPosition(cell.getPosition().x + (paths[count].x), cell.getPosition().y + (paths[count].y));
	}
	else {
		cell.setPosition(cell.getPosition().x, cell.getPosition().y);
	}
	
}

void DNA::calcFitness(sf::Vector2f targetPos, sf::Vector2f blocker) {
	float dist = sqrt(pow(targetPos.x - cell.getPosition().x, 2) + pow(targetPos.y - cell.getPosition().y, 2));
	float targetdist = sqrt(pow(targetPos.x - (WINDOW_WIDTH / 2), 2) + pow(targetPos.y - WINDOW_LENGTH, 2));
	fitness = 1 /dist;
	if (dead) {
		fitness = (1/(dist*10));
	}
	if(cell.getPosition().y<blocker.y)
		fitness *= 5;
	if (finished)
		fitness *= 10;
	if (fitness < 0)
		fitness = 0;
}

DNA DNA::crossOver(DNA parentB) {
	DNA child;
	for (int i = 0;i < lifespan;i++) {
		if (i < (lifespan / 2))
			child.paths[i] = paths[i];
		else
			child.paths[i] = parentB.paths[i];
	}
	if (rand() % 1 == 0)
		child.velocity = velocity;
	else
		child.velocity = parentB.velocity;
	return child;
}

void DNA::mutate() {
	for (int i = 0;i < lifespan;i++) {
		if ((float)rand() / RAND_MAX < mutationRate) {
			paths[i] = sf::Vector2f((((float)rand() / RAND_MAX) * 2 - 1)*velocity, (((float)rand() / RAND_MAX) * 2 - 1)*velocity);
		}
	}
}

