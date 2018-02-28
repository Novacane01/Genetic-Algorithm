#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class DNA {
public:
	DNA();
	sf::Vector2f paths[50] = {};
	void Draw(sf::RenderWindow &);
	void Update(float, int);
	void mutate();
	void calcFitness(sf::Vector2f, sf::Vector2f);
	DNA crossOver(DNA);
	sf::CircleShape cell;
	float fitness = 0.f;
	int velocity = 0;
	bool dead = false;
	bool finished = false;
	int lifespan = 50;
private:
	
};