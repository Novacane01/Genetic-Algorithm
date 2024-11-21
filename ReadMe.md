
# Genetic Algorithm for Pathfinding with SFML

## Overview

This project simulates a population of **DNA** objects using a **genetic algorithm** to evolve behavior over time. Each DNA object has a simple task: to find its way to a target circle at the top of the screen. The simulation runs until either all the agents die or a predefined amount of time elapses. Based on how well each DNA object performs (i.e., how close it gets to the goal), a fitness score is assigned. DNA objects with higher fitness are selected for breeding and crossover, and over generations, the population becomes increasingly successful at finding the goal.


https://github.com/user-attachments/assets/8d7c5db7-a115-4f14-bf7d-39e478bf5567


## Requirements

- **C++** compiler (with C++11 or later support)
- **SFML** graphics library
- **Standard C++ libraries** (vector, random, etc.)


## How It Works

### Initialization:
- A population of size `n` is created, and each DNA object is initialized with random genetic data (representing movement properties).
- The DNA objects are placed at the bottom of the screen, and the goal (circle) is placed at the top.

### Movement:
- Each DNA object moves toward the goal based on its velocity and direction, determined by its genetic data.
- If an agent reaches the goal or gets close enough, it is considered successful.

### Fitness Evaluation:
- After each simulation run, the distance each DNA object traveled is used to calculate its fitness. DNA objects that get closer to the goal have higher fitness scores.
- The fitness scores are used to select which DNA will reproduce in the next generation.

### Selection, Crossover, and Mutation:
- **Elitist Selection**: The top-performing DNA objects (with the highest fitness) are guaranteed to be selected for reproduction. This ensures that the fittest genes are passed on to the next generation.
- **Crossover**: The genetic data of selected DNA objects is combined to produce offspring. This combines traits from two parents to produce new agents.
- **Mutation**: Occasionally, random changes are applied to the offspring's genetic data to prevent stagnation and encourage genetic diversity.

### Generational Evolution:
- Over multiple generations, the population evolves to become better at reaching the goal, thanks to the combination of elitist selection, crossover, and mutation.

## Parameters

- **Population size (n)**: Number of DNA objects in each generation.
- **Max simulation time**: Maximum amount of time the simulation will run before ending the current generation.
- **Mutation rate**: The probability that a DNA object will mutate during reproduction (default: 0.01).
- **Goal position**: The fixed location of the goal (circle) at the top of the screen.
- **Number of generations**: Total number of generations for the evolution process.

## Example Run

- **Generation 1**: Initially, the population is randomly initialized, and many DNA objects fail to reach the goal.
- **Generation 2**: After evaluating the fitness of each DNA object, the best performers are selected for reproduction. The population begins to show improvement as the fittest agents are selected for crossover.
- **Subsequent Generations**: Over multiple generations, the population's performance improves as the genetic algorithm refines the agents' ability to navigate toward the goal.

