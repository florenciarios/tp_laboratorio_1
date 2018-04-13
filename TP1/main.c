#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float opA=0;
    float opB=0;
    int cont=0;

    while(seguir=='s')
    {
        if(opA!=0 || opB!=0)
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",opA);
            printf("2- Ingresar 2do operando (B=%.2f)\n",opB);
        }
        else
        {
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                scanf("%f",&opA);
                printf("\nA = %.2f \n\n",opA);
                cont++;
                system("pause");
                system("cls");
                break;

            case 2:
                scanf("%f",&opB);
                printf("\nB = %.2f \n\n",opB);
                cont++;
                system("pause");
                system("cls");
                break;

            case 3:
                opMissing(cont);
                plusOp(opA,opB);
                system("pause");
                system("cls");
                break;

            case 4:
                opMissing(cont);
                minusOp(opA,opB);
                system("pause");
                system("cls");
                break;

            case 5:
                opMissing(cont);
                divideOp(opA,opB);
                system("pause");
                system("cls");
                break;

            case 6:
                opMissing(cont);
                multiplyOp(opA,opB);
                system("pause");
                system("cls");
                break;

            case 7:
                factoreo(opA);
                system("pause");
                system("cls");

                break;
            case 8:
                opMissing(cont);
                plusOp(opA,opB);
                minusOp(opA,opB);
                divideOp(opA,opB);
                multiplyOp(opA,opB);
                factoreo(opA);
                system("pause");
                system("cls");
                break;

            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
