#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int FILAS, COLUMNAS;
int encontrado = 0;

/* Mostrar laberinto */
void mostrarLaberinto(char **laberinto) {
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            printf("%c ", laberinto[f][c]);
        }
        printf("\n");
    }
    printf("\n");
}

/* DFS con backtracking */
void dfs(char **laberinto, int f, int c) {
    if (f < 0 || f >= FILAS || c < 0 || c >= COLUMNAS)
        return;

    if (laberinto[f][c] == '#' || laberinto[f][c] == '.')
        return;

    if (encontrado)
        return;

    if (laberinto[f][c] == 'S') {
        encontrado = 1;
        return;
    }

    if (laberinto[f][c] != 'E')
        laberinto[f][c] = '.';

    int df[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        dfs(laberinto, f + df[i], c + dc[i]);
        if (encontrado)
            return;
    }

    if (!encontrado && laberinto[f][c] != 'E')
        laberinto[f][c] = '*';
}

int main() {
    srand(time(NULL));

    printf("Ingrese filas y columnas del laberinto: ");
    scanf("%d %d", &FILAS, &COLUMNAS);

    /* Reserva dinámica de memoria */
    char **laberinto = (char **)malloc(FILAS * sizeof(char *));
    for (int i = 0; i < FILAS; i++) {
        laberinto[i] = (char *)malloc(COLUMNAS * sizeof(char));
    }

    /* Inicializar todo como muro */
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            laberinto[f][c] = '#';
        }
    }

    laberinto[0][0] = 'E';
    laberinto[FILAS - 1][COLUMNAS - 1] = 'S';

    /* Crear camino garantizado */
    int f = 0, c = 0;

    while (f != FILAS - 1 || c != COLUMNAS - 1) {
        if (laberinto[f][c] != 'E')
            laberinto[f][c] = '*';

        if (f == FILAS - 1)
            c++;
        else if (c == COLUMNAS - 1)
            f++;
        else if (rand() % 2 == 0)
            f++;
        else
            c++;
    }

    /* Abrir caminos adicionales */
    for (int i = 0; i < FILAS * COLUMNAS / 3; i++) {
        int rf = rand() % FILAS;
        int rc = rand() % COLUMNAS;

        if (laberinto[rf][rc] == '#')
            laberinto[rf][rc] = '*';
    }
    clock_t inicio, fin;
    double tiempo;

    printf("\nLaberinto generado:\n");
    mostrarLaberinto(laberinto);

    inicio = clock();

    dfs(laberinto, 0, 0);

    fin = clock();
    tiempo = (double)(fin-inicio) /
    CLOCKS_PER_SEC;

    printf("Camino encontrado por DFS:\n");
    mostrarLaberinto(laberinto);

    printf("Tiempo que tardo en encontrar el camino: %f segundos\n", tiempo);
    /* Liberar memoria */
    for (int i = 0; i < FILAS; i++) {
        free(laberinto[i]);
    }
    free(laberinto);

    return 0;
}
