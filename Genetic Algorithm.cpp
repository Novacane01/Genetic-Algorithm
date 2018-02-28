// Genetic Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "Population.h"
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

const int populationSize = 50;
float mutationRate = 0.05f;
float WINDOW_LENGTH = 720.f;
float WINDOW_WIDTH = 1080.f;

float calcDist(float, float, float, float);
int main()
{
	srand(time(0));
	Population population;
	vector<DNA> genepool;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_LENGTH),"Pathfinder");
	sf::Clock clock;
	sf::RectangleShape target(sf::Vector2f(25, 25));
	sf::RectangleShape blocker(sf::Vector2f(WINDOW_WIDTH/2,30));
	blocker.setOrigin(blocker.getSize().x/2, blocker.getSize().y/2);
	blocker.setPosition(WINDOW_WIDTH / 2, WINDOW_LENGTH / 2);
	blocker.setFillColor(sf::Color(150, 50, 150, 150));
	target.setPosition(WINDOW_WIDTH/2-target.getSize().x, WINDOW_LENGTH*.1);
	target.setFillColor(sf::Color(255, 0, 0, 100));
	sf::Text details;
	sf::Font font;
	if (!font.loadFromFile("C:\\Fonts\\LemonMilk.otf")) {
		cout << "Could not load font" << endl;
	}
	details.setFont(font);
	details.setCharacterSize(15);
	float count = 0;
	while (window.isOpen()){
		srand(time(0));
		float dt = clock.restart().asSeconds();
		details.setString("Frames: "+to_string(count)+"\nGenerations: "+to_string(population.generation)+
			"\nMutation Rate: "+to_string(mutationRate*100)+"%\nAverage Fitness: "+ to_string(population.avgFitness)+"%"+"\nHighest Fitness: "+to_string(population.highestFitness));
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		for (int i = 0;i < populationSize;i++) {
			population.population[i].Update(dt,(int)count);
			population.population[i].Draw(window);
			if (blocker.getGlobalBounds().intersects(population.population[i].cell.getGlobalBounds())||population.population[i].cell.getPosition().x<0||population.population[i].cell.getPosition().x>WINDOW_WIDTH||population.population[i].cell.getPosition().y>WINDOW_LENGTH||population.population[i].cell.getPosition().y<0) {
				population.population[i].dead = true;
			}
			if (target.getGlobalBounds().intersects(population.population[i].cell.getGlobalBounds()))
				population.population[i].finished = true;
				
		}
		window.draw(target);
		window.draw(details);
		window.draw(blocker);
		window.display();
		count += .2f;
		if ((int)count == 50) {
			DNA popcopy[populationSize] ;
			for (int i = 0; i < populationSize;i++) {
				population.population[i].calcFitness(target.getPosition(),blocker.getPosition());
				/*for (int j = 0;j < population.population[i].fitness*populationSize;j++) {
					genepool.push_back(population.population[i]);
				}*/
			}
			population.calcFitness();
			for (int i = 0;i < populationSize;i++) {
				popcopy[i] = population.population[i];
			}
			for (int i = 0;i < populationSize;i++) {
				DNA parentA = population.selection(popcopy);
				DNA parentB = population.selection(popcopy);
				DNA child = parentA.crossOver(parentB);
				if (population.population[i].fitness >= population.highestFitness) {
					for (int j = 0;j < population.population[i].lifespan;j++) {
						child.paths[j] = population.population[i].paths[j];
					}
				}
				child.mutate();
				population.population[i] = child;
			}
			population.generation++;
			genepool.clear();
			count = 0;
		}
		Sleep(10);
	}
    return 0;
}

float calcDist(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}