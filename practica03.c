//Gonzalez Vera Bruno 3CV2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir el mapeo de números a letras
const char *mapa[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Función recursiva para generar combinaciones
void generarCombinaciones(char *digitos, int indice, char *actual, char **resultado, int *contador) {
    if (digitos[indice] == '\0') {
        // Guardar la combinación en el resultado
        resultado[*contador] = strdup(actual);
        (*contador)++;
        return;
    }
    
    // Obtener las letras del dígito actual
    const char *letras = mapa[digitos[indice] - '0'];
    for (int i = 0; letras[i] != '\0'; i++) {
        // Agregar la letra actual
        actual[indice] = letras[i];
        // Llamar recursivamente para el siguiente dígito
        generarCombinaciones(digitos, indice + 1, actual, resultado, contador);
    }
}

// Función principal para obtener combinaciones
char **obtenerCombinaciones(char *digitos, int *tamanio) {
    if (*digitos == '\0') {
        *tamanio = 0;
        return NULL;
    }
    
    int maximo = 100; // Tamaño estimado
    char **resultado = malloc(maximo * sizeof(char *));
    char actual[5] = {0}; // Máximo 4 caracteres + terminador nulo
    int contador = 0;
    
    generarCombinaciones(digitos, 0, actual, resultado, &contador);
    *tamanio = contador;
    return resultado;
}

int main() {
    char digitos[5]; // Espacio suficiente para 4 dígitos + terminador nulo
    int tamanio;
    
    printf("Ingrese los digitos (2-9): ");
    scanf("%4s", digitos); // Leer hasta 4 caracteres
    
    char **combinaciones = obtenerCombinaciones(digitos, &tamanio);
    
    printf("Posibles combinaciones:\n");
    for (int i = 0; i < tamanio; i++) {
        printf("%s\n", combinaciones[i]);
        free(combinaciones[i]); // Liberar memoria
    }
    free(combinaciones); // Liberar memoria del array
    
    return 0;
}
