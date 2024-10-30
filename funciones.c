#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 

#include "funciones.h"

// Función para sumar dos números
double sumar(double a, double b) {
    return a + b;
}

// Función para restar el segundo número del primero
double restar(double a, double b) {
    return a - b;
}

// Función para multiplicar dos números
double multiplicar(double a, double b) {
    return a * b;
}

// Función para dividir el primer número por el segundo
double dividir(double a, double b) {
    return a / b;
}

// Función para calcular la potencia a^b
double potencia(double base, double exponente) {
    return pow(base, exponente);
}

// Función para calcular la raíz cuadrada de un número
double raiz_cuadrada(double numero) {
    if (numero < 0) {
        printf(COLOR_RED "\nError: No se puede calcular la raíz cuadrada de un número negativo.\n" COLOR_RESET);
        return NAN; // Retorna Not-A-Number
    }
    return sqrt(numero);
}

// Función para agregar una operación al historial
void agregar_historial(Operacion historial[], int *contador, char descripcion[], double resultado) {
    if (*contador < MAX_OPERACIONES) {
        strcpy(historial[*contador].descripcion, descripcion);
        historial[*contador].resultado = resultado;
        (*contador)++;
    } else {
        printf(COLOR_RED "\nEl historial está lleno.\n" COLOR_RESET);
    }
}

// Función para mostrar el historial de operaciones
void mostrar_historial(Operacion historial[], int contador) {
    if (contador == 0) {
        printf("\nEl historial está vacío.\n");
        return;
    }
    printf("\nHistorial de Operaciones:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d: %s = %.2lf\n", i + 1, historial[i].descripcion, historial[i].resultado);
    }
}

// Función para limpiar la pantalla
void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
