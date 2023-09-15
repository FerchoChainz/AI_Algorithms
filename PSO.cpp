#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define N 10
#define max_iter 100
#define w 0.5
#define c1 2.0
#define c2 2.0
#define minx -10.0
#define maxx 10.0

// Estructura para representar una part�cula.
typedef struct {
    double position;
    double velocity;
    double bestPos;
    double bestFitness;
} Particle;

// Funci�n objetivo que queremos minimizar (puedes cambiarla seg�n tus necesidades).
double funcion_objetivo(double x) {
    return x * x;  // Ejemplo: minimizar la funci�n x^2.
}

int main() {
    Particle swarm[N];
    double best_fitness_swarm = INT_MAX;
    double best_pos_swarm;

    // Inicializaci�n de las part�culas.
    for (int i = 0; i < N; i++) {
        swarm[i].position = (double)rand() / RAND_MAX * (maxx - minx) + minx;
        swarm[i].velocity = 0.0;
        swarm[i].bestPos = swarm[i].position;
        swarm[i].fitness = funcion_objetivo(swarm[i].position);
        swarm[i].bestFitness = swarm[i].fitness;
    }

    // Algoritmo PSO.
    for (int iter = 0; iter < max_iter; iter++) {
        for (int i = 0; i < N; i++) {
            double r1 = (double)rand() / RAND_MAX;
            double r2 = (double)rand() / RAND_MAX;

            // Actualizar la velocidad de la part�cula.
            swarm[i].velocity = w * swarm[i].velocity +
                                r1 * c1 * (swarm[i].bestPos - swarm[i].position) +
                                r2 * c2 * (best_pos_swarm - swarm[i].position);

            // Actualizar la posici�n de la part�cula.
            swarm[i].position += swarm[i].velocity;

            // Asegurarse de que la posici�n est� dentro del rango [minx, maxx].
            if (swarm[i].position < minx) {
                swarm[i].position = minx;
            } else if (swarm[i].position > maxx) {
                swarm[i].position = maxx;
            }

            // Actualizar el mejor de la part�cula y el mejor global.
            if (swarm[i].fitness < swarm[i].bestFitness) {
                swarm[i].bestFitness = swarm[i].fitness;
                swarm[i].bestPos = swarm[i].position;
            }

            if (swarm[i].fitness < best_fitness_swarm) {
                best_fitness_swarm = swarm[i].fitness;
                best_pos_swarm = swarm[i].position;
            }
        }
    }

    printf("Mejor valor encontrado: %lf\n", best_fitness_swarm);
    printf("Mejor posici�n encontrada: %lf\n", best_pos_swarm);

    return 0;
}

