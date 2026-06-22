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

    // Promedio por asignatura + max, min, aprobados y reprobados
    printf("\n--- RESULTADOS POR ASIGNATURA ---\n");
    for (int j = 0; j < asignaturas; j++)
    {
        float suma = 0, max = calificaciones[0][j], min = calificaciones[0][j];
        int aprobados = 0, reprobados = 0;
        for (int i = 0; i < n; i++)
        {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
            if (calificaciones[i][j] >= 6) aprobados++;
            else reprobados++;
        }
        printf("Asignatura %d -> Promedio: %.2f | Max: %.2f | Min: %.2f | Aprobados: %d | Reprobados: %d\n",
               j + 1, suma / n, max, min, aprobados, reprobados);
    }

    // Promedio por estudiante + max y min
    printf("\n--- RESULTADOS POR ESTUDIANTE ---\n");
    for (int i = 0; i < n; i++)
    {
        float suma = 0, max = calificaciones[i][0], min = calificaciones[i][0];
        for (int j = 0; j < asignaturas; j++)
        {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
        }
        printf("Estudiante %d -> Promedio: %.2f | Max: %.2f | Min: %.2f\n",
               i + 1, suma / asignaturas, max, min);
    }
    return 0;
}