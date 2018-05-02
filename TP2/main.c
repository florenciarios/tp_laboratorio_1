/******************************************************************
* Programa: TRABAJO PRACTICO N�2
*
* Descripci�n:
*
* Definir una estructura que represente una persona, con los campos nombre, edad, dni y un
* flag de estado.
* Hacer un programa que defina un array de 20 �tems de esta estructura y con un men� como el
* siguiente:
*    1. Agregar una persona
*    2. Borrar una persona
*    3. Imprimir lista ordenada por nombre
*    4. Imprimir gr�fico de edades
* Se utilizar� el campo de estado para indicar si el �tem del array esta ocupado o no.
* El gr�fico deber� ser un gr�fico de barras en donde se agrupar�n 3 barras:
*    � Menores de 18
*    � De 19 a 35
*    � Mayores de 35.
* En el eje Y se marcar�n la cantidad de personas en el grupo, y en el eje X el grupo.
*
* Autor: Florencia Rios 1�A
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    ePersona p[20];//={{"sofi",40,1,1234},{"rosa",60,1,3123},{"flor",14,1,4166},{"clara",12,1,5655},{"lara",10,1,5844},{"ursula",15,1,4567},{"esther",20,1,6788},{"carla",33,1,1233},{"jorge",25,1,6666},{"walter",30,1,1222},{"dalila",21,1,2323},{"rob",20,1,4544}};

    inicializar(p,20);

    while(seguir=='s')
    {
        system("cls");

        printf("\t--MENU--\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("\tIngrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(p,20);
                system("pause");
                break;
            case 2:
                bajarPersona(p,20);
                system("pause");
                break;
            case 3:
                ordenarxNombre(p,20);
                system("pause");
                break;
            case 4:
                grafico(p,20);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
