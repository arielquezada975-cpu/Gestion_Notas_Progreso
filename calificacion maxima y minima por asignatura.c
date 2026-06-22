float max = calificaciones[0][j], min = calificaciones[0][j];
        for (int i = 0; i < n; i++)
        {
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
        }
        printf("Max: %.2f | Min: %.2f\n", max, min);
        