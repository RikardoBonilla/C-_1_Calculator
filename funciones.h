#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <math.h>

// Definiciones para colores en la interfaz
#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"

// Capacidad máxima del historial
#define MAX_OPERACIONES 100

// Estructura para almacenar las operaciones
typedef struct {
    char descripcion[50];
    double resultado;
} Operacion;

// Declaración de funciones matemáticas
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);
double potencia(double base, double exponente);
double raiz_cuadrada(double numero);

// Declaración de funciones para el historial
void agregar_historial(Operacion historial[], int *contador, char descripcion[], double resultado);
void mostrar_historial(Operacion historial[], int contador);

// Declaración de la función para limpiar la pantalla
void limpiar_pantalla();

#endif // FUNCIONES_H
