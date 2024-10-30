#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funciones.h"

// Definición de constantes para las opciones del menú
#define SUMAR 1
#define RESTAR 2
#define MULTIPLICAR 3
#define DIVIDIR 4
#define POTENCIA 5
#define RAIZ_CUADRADA 6
#define VER_HISTORIAL 7
#define SALIR 8

int main()
{
    int opcion;
    double num1, num2, resultado;
    Operacion historial[MAX_OPERACIONES];
    int contador_historial = 0;

    do
    {
        limpiar_pantalla();

        // Mostrar menú
        printf(COLOR_CYAN "====================================\n" COLOR_RESET);
        printf(COLOR_YELLOW "        CALCULADORA BÁSICA\n" COLOR_RESET);
        printf(COLOR_CYAN "====================================\n" COLOR_RESET);
        printf("Seleccione una operación:\n");
        printf("%d. Sumar\n", SUMAR);
        printf("%d. Restar\n", RESTAR);
        printf("%d. Multiplicar\n", MULTIPLICAR);
        printf("%d. Dividir\n", DIVIDIR);
        printf("%d. Potencia\n", POTENCIA);
        printf("%d. Raíz Cuadrada\n", RAIZ_CUADRADA);
        printf("%d. Ver Historial\n", VER_HISTORIAL);
        printf("%d. Salir\n", SALIR);
        printf("====================================\n");
        printf("Ingrese su opción: ");

        // Leer opción del usuario y validar
        if (scanf("%d", &opcion) != 1) {
            printf(COLOR_RED "\nError: Entrada inválida. Por favor, ingrese un número.\n" COLOR_RESET);
            // Limpiar el buffer de entrada
            while (getchar() != '\n');
            continue;
        }

        // Validar opción
        if (opcion < SUMAR || opcion > SALIR) {
            printf(COLOR_RED "\nOpción inválida. Por favor, intente de nuevo.\n" COLOR_RESET);
            while (getchar() != '\n');
            continue;
        }

        if (opcion == SALIR) {
            printf("Saliendo del programa.\n");
            break;
        }

        if (opcion == VER_HISTORIAL) {
            mostrar_historial(historial, contador_historial);
            printf("Presione Enter para continuar...");
            while (getchar() != '\n');
            getchar();
            continue;
        }

        // Solicitar los operandos según la operación
        if (opcion == RAIZ_CUADRADA) {
            // Solo necesita un operando
            printf("Ingrese el número: ");
            if (scanf("%lf", &num1) != 1) {
                printf(COLOR_RED "\nError: Entrada inválida. Por favor, ingrese un número.\n" COLOR_RESET);
                while (getchar() != '\n');
                continue;
            }
        } else {
            // Necesita dos operandos
            printf("Ingrese el primer número: ");
            if (scanf("%lf", &num1) != 1) {
                printf(COLOR_RED "\nError: Entrada inválida. Por favor, ingrese un número.\n" COLOR_RESET);
                while (getchar() != '\n');
                continue;
            }

            printf("Ingrese el segundo número: ");
            if (scanf("%lf", &num2) != 1) {
                printf(COLOR_RED "\nError: Entrada inválida. Por favor, ingrese un número.\n" COLOR_RESET);
                while (getchar() != '\n');
                continue;
            }
        }

        // Realizar la operación seleccionada
        char descripcion[50];
        switch (opcion) {
            case SUMAR:
                resultado = sumar(num1, num2);
                printf("Resultado: %.2lf\n", resultado);
                snprintf(descripcion, sizeof(descripcion), "%.2lf + %.2lf", num1, num2);
                agregar_historial(historial, &contador_historial, descripcion, resultado);
                break;
            case RESTAR:
                resultado = restar(num1, num2);
                printf("Resultado: %.2lf\n", resultado);
                snprintf(descripcion, sizeof(descripcion), "%.2lf - %.2lf", num1, num2);
                agregar_historial(historial, &contador_historial, descripcion, resultado);
                break;
            case MULTIPLICAR:
                resultado = multiplicar(num1, num2);
                printf("Resultado: %.2lf\n", resultado);
                snprintf(descripcion, sizeof(descripcion), "%.2lf * %.2lf", num1, num2);
                agregar_historial(historial, &contador_historial, descripcion, resultado);
                break;
            case DIVIDIR:
                if (num2 == 0) {
                    printf(COLOR_RED "\nError: División por cero no permitida.\n" COLOR_RESET);
                } else {
                    resultado = dividir(num1, num2);
                    printf("Resultado: %.2lf\n", resultado);
                    snprintf(descripcion, sizeof(descripcion), "%.2lf / %.2lf", num1, num2);
                    agregar_historial(historial, &contador_historial, descripcion, resultado);
                }
                break;
            case POTENCIA:
                resultado = potencia(num1, num2);
                printf("Resultado: %.2lf\n", resultado);
                snprintf(descripcion, sizeof(descripcion), "%.2lf ^ %.2lf", num1, num2);
                agregar_historial(historial, &contador_historial, descripcion, resultado);
                break;
            case RAIZ_CUADRADA:
                resultado = raiz_cuadrada(num1);
                if (!isnan(resultado)) {
                    printf("Resultado: %.2lf\n", resultado);
                    snprintf(descripcion, sizeof(descripcion), "√%.2lf", num1);
                    agregar_historial(historial, &contador_historial, descripcion, resultado);
                }
                break;
            default:
                printf(COLOR_RED "\nOpción inválida.\n" COLOR_RESET);
                break;
        }

        // Pausar antes de continuar
        printf("Presione Enter para continuar...");
        while (getchar() != '\n');
        getchar();

    } while(1);

    return 0;
}
