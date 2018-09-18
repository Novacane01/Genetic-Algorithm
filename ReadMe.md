
# Genetic Algorithm Project Overview

This project was made using the graphics library SFML in order to improve my understanding of machine learning and how genetic algorithms work.

# How it works

In the beginning a population of size n is created and filled with DNA objects that hold specific data. All of the DNA objects have a simple task which is to find their way to the circle at the top of the screen. The simulation will run until either all of the population has died or a certain amount of time has elasped. After each simulation the learning starts to occur. Depending on how well each DNA object performed, they were assigned a fitness value. The DNA which got closest to the goal were assigned hte highest fitness while the others received a lower score. These scores were used to decide which DNA would be selected for breeding and cross-over. Using elitist selection, the DNA with the highest fitness score is automatically chosen as a parent which increases the rate of success per generation. As the simulation continues to run, the smarter the population becomes, and the closer each DNA objects comes to their goal. To prevent the algorithm from getting stuck in a generation we include a mutation rate which occasioinally randomizes the characteristics of a speciic DNA object.

# Resources

SFML - https://www.sfml-dev.org/
