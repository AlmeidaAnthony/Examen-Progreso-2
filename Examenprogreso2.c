#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

// Función para generar una calificación aleatoria entre 0 y 10//
int generarCalificacion() {
    int calificacion = rand() % 11;  // Genera un número aleatorio en el rango de 0 a 10//
    return calificacion;
}

// Función para obtener el promedio de calificaciones de un alumno //
int obtenerPromedioAlumno(int calificaciones[], int numProgresos) {
    int sumaCalificaciones = 0;
    
    // Calcular la suma de las calificaciones del alumno
    for (int i = 0; i < numProgresos; i++) {
        sumaCalificaciones += calificaciones[i];
    }
    
    // Calcular el promedio dividiendo la suma por el número de progresos
    int promedio = sumaCalificaciones / numProgresos;
    
    return promedio;
}

// Función para obtener el promedio de calificaciones del grupo de estudiantes para cada progreso
void obtenerPromedioGrupo(int calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos, int promedios[]) {
    for (int i = 0; i < numProgresos; i++) {
        int sumaCalificaciones = 0;
        
        // Calcular la suma de las calificaciones para el progreso i
        for (int j = 0; j < numAlumnos; j++) {
            sumaCalificaciones += calificaciones[j][i];
        }
        
        // Calcular el promedio dividiendo la suma por el número de alumnos
        int promedio = sumaCalificaciones / numAlumnos;
        
        promedios[i] = promedio;
    }
}

int main() {
    srand(time(0));
    
    int calificaciones[NUM_ALUMNOS][NUM_PROGRESOS];
    
    // Generar calificaciones aleatorias para cada alumno en cada progreso
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            calificaciones[i][j] = generarCalificacion();
        }
    }