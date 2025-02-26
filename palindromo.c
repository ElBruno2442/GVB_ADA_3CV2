//Gonzalez Vera Bruno 3CV2

#include <stdio.h>

int main(){
    int num=0;
    int temp=0;
    int inverso=0;
    int digito=0;
    
    printf("Ingrese el numero: ");
    scanf("%d", &num);
    
    temp = num;
    if (num >= 0){
        while (temp != 0){

            digito = temp % 10;
            inverso = inverso * 10 + digito;
            temp = temp / 10;
        }
    }

    if (num == inverso){
        printf("\nEl numero %d es PALINDROMO\n", num);
    } else {
        printf("\nEl numero %d NO es PALINDROMO\n", num);
    }

    return 0;
}

