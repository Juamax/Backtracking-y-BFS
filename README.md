# Backtracking-y-BFS
# Generador y Resolución de Laberinto con DFS en C

## Descripción

Este programa en lenguaje C genera un laberinto de tamaño definido por el usuario y utiliza el algoritmo **DFS (Depth-First Search)** para encontrar un camino desde la entrada hasta la salida.

El laberinto se crea inicialmente lleno de muros y luego se generan caminos aleatorios asegurando al menos una ruta válida entre la entrada y la salida.

Después de generar el laberinto, el programa ejecuta el algoritmo DFS para buscar la salida y muestra el recorrido encontrado.

---

## Características

* Generación de laberintos de tamaño dinámico.
* Reserva dinámica de memoria.
* Uso del algoritmo **DFS (Depth First Search)** con recursividad.
* Implementación de **backtracking**.
* Visualización del laberinto antes y después de encontrar el camino.
* Liberación de memoria al finalizar el programa.

---

## Símbolos utilizados en el laberinto

| Símbolo | Significado            |
| ------- | ---------------------- |
| `#`     | Muro                   |
| `*`     | Camino disponible      |
| `E`     | Entrada del laberinto  |
| `S`     | Salida del laberinto   |
| `.`     | Celda visitada por DFS |

---

## Funcionamiento del programa

1. El usuario ingresa el número de **filas y columnas** del laberinto.
2. Se reserva memoria dinámicamente para crear una matriz que representa el laberinto.
3. Se inicializa el laberinto completamente con muros (`#`).
4. Se define:

   * Entrada (`E`) en la esquina superior izquierda.
   * Salida (`S`) en la esquina inferior derecha.
5. Se genera un camino garantizado desde la entrada hasta la salida.
6. Se abren caminos adicionales aleatorios para hacer el laberinto más complejo.
7. Se muestra el laberinto generado.
8. Se ejecuta el algoritmo **DFS** para encontrar la salida.
9. Se muestra el laberinto con el camino explorado.
10. Se libera la memoria utilizada.

---

## Compilación

Para compilar el programa usando **GCC**:

```bash
gcc laberinto.c -o laberinto
```

---

## Ejecución

```bash
./laberinto
```

El programa solicitará:

```
Ingrese filas y columnas del laberinto:
```

Ejemplo:

```
20 20
```

---

## Ejemplo de salida

```
Laberinto generado:

E * # # *
# * * # *
# # * # *
# # * * *
# # # # S

Camino encontrado por DFS:

E . # # *
# . . # *
# # . # *
# # . . .
# # # # S
```

---

## Conceptos utilizados

* Estructuras de datos
* Recursividad
* Algoritmo DFS
* Backtracking
* Memoria dinámica (`malloc` y `free`)
* Generación de números aleatorios

---

