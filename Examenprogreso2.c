#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

int generarCalificacion() {
    int calificacion = rand() % 11;
    return calificacion;

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
 // Función para obtener el promedio de calificaciones de un alumno
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