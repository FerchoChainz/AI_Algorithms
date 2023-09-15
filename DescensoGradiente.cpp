#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Definimos una función objetivo con varios mínimos locales.
double funcion_objetivo(double x, double y, double z) {
    return sin(x) + cos(y) + 0.5 * z * z;
}

// Definimos el gradiente de la función objetivo.
void gradiente(double x, double y, double z, double *grad_x, double *grad_y, double *grad_z) {
    *grad_x = cos(x);
    *grad_y = -sin(y);
    *grad_z = z;
}

int main() {
    srand(time(NULL));

    // Punto de inicio aleatorio.
    double punto_x = (double)rand() / RAND_MAX * 10.0;  // Multiplicado por 10 para cambiar la escala.
    double punto_y = (double)rand() / RAND_MAX * 10.0;
    double punto_z = (double)rand() / RAND_MAX * 10.0;

    // Hiperparámetros del algoritmo de descenso de gradiente.
    double tasa_aprendizaje = 0.1;
    int num_iteraciones = 100;

    // Algoritmo de descenso de gradiente.
    for (int i = 0; i < num_iteraciones; i++) {
        double grad_x, grad_y, grad_z;
        gradiente(punto_x, punto_y, punto_z, &grad_x, &grad_y, &grad_z);

        punto_x -= tasa_aprendizaje * grad_x;
        punto_y -= tasa_aprendizaje * grad_y;
        punto_z -= tasa_aprendizaje * grad_z;
    }

    printf("Resultado final: (%lf, %lf, %lf)\n", punto_x, punto_y, punto_z);
    printf("Valor minimo de la función objetivo: %lf\n", funcion_objetivo(punto_x, punto_y, punto_z));

    return 0;
}

