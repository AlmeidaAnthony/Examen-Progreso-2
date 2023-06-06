#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

// Función para generar una calificación aleatoria entre 0 y 10
int generarCalificacion() {
    int calificacion = rand() % 11;  // Genera un número aleatorio en el rango de 0 a 10
    return calificacion;
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

// Función para obtener el número del alumno con el mayor promedio de calificación durante el semestre
int obtenerMejorAlumno(int calificaciones[][NUM_PROGRESOS], int numAlumnos, int numProgresos) {
    int mejorPromedio = 0;
    int mejorAlumno = 0;
    
    // Iterar sobre todos los alumnos y calcular su promedio de calificación
    for (int i = 0; i < numAlumnos; i++) {
        int promedio = obtenerPromedioAlumno(calificaciones[i], numProgresos);
        
        // Comparar el promedio actual con el mejor promedio hasta el momento
        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            mejorAlumno = i + 1;  // Sumar 1 para obtener el número de alumno correcto
        }
    }
    
    return mejorAlumno;
}

void imprimirMatriz(int matriz[][NUM_PROGRESOS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    srand(time(0));  // Inicializar la semilla del generador de números aleatorios
    
    int calificaciones[NUM_ALUMNOS][NUM_PROGRESOS];
    
    // Generar calificaciones aleatorias para cada alumno en cada progreso
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            calificaciones[i][j] = generarCalificacion();
        }
    }

     printf("Notas por progresos:\n");
    imprimirMatriz(calificaciones, NUM_ALUMNOS, NUM_PROGRESOS);
    
    // Promedio de calificaciones de cada alumno durante el progreso //
       printf("Promedio de calificaciones de cada alumno durante el semestre:\n");

    for (int i = 0; i < NUM_ALUMNOS; i++) {
        int promedioAlumno = obtenerPromedioAlumno(calificaciones[i], NUM_PROGRESOS);
        printf("Alumno %d: %d\n", i + 1, promedioAlumno);
    }

    // Obtener y mostrar el promedio del grupo de estudiantes para cada progreso
    int promediosGrupo[NUM_PROGRESOS];
    obtenerPromedioGrupo(calificaciones, NUM_ALUMNOS, NUM_PROGRESOS, promediosGrupo);

    printf("\nPromedio del grupo de estudiantes para cada progreso:\n");

    for (int i = 0; i < NUM_PROGRESOS; i++) {
        printf("Progreso %d: %d\n", i + 1, promediosGrupo[i]);
    }

    // Obtener y mostrar el número del alumno con el mejor promedio de calificación
    int mejorAlumno = obtenerMejorAlumno(calificaciones, NUM_ALUMNOS, NUM_PROGRESOS);
    printf("\nEl alumno con el mejor promedio de calificacion durante el semestre es: Alumno %d\n", mejorAlumno);

    return 0;
}
