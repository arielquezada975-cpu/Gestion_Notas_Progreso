// Promedio por asignatura
    printf("\n--- RESULTADOS POR ASIGNATURA ---\n");
    for (int j = 0; j < asignaturas; j++)
    {
        float suma = 0;
        for (int i = 0; i < n; i++)
            suma += calificaciones[i][j];
        printf("Asignatura %d -> Promedio: %.2f\n", j + 1, suma / n);
    }
    