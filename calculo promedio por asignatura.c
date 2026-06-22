#include <stdio.h>

int main()
{
    int n;
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    float calificaciones[n][3];
    int asignaturas = 3;

    for (int i = 0; i < n; i++)
    {
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < asignaturas; j++)
        {
            do {
                printf("  Asignatura %d: ", j + 1);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                    printf("  Error: calificacion debe estar entre 0 y 10\n");
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    // Promedio por asignatura
    printf("\n--- RESULTADOS POR ASIGNATURA ---\n");
    for (int j = 0; j < asignaturas; j++)
    {
        float suma = 0, max = calificaciones[0][j], min = calificaciones[0][j];
        for (int i = 0; i < n; i++)
        {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
        }
        printf("Asignatura %d -> Promedio: %.2f | Max: %.2f | Min: %.2f\n",
               j + 1, suma / n, max, min);
    }

    // Promedio por estudiante
    printf("\n--- RESULTADOS POR ESTUDIANTE ---\n");
    for (int i = 0; i < n; i++)
    {
        float suma = 0;
        for (int j = 0; j < asignaturas; j++)
            suma += calificaciones[i][j];
        printf("Estudiante %d -> Promedio: %.2f\n", i + 1, suma / asignaturas);
    }
    return 0;
}
