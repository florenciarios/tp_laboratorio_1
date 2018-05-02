#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Busca en el indice de estado el primer espacio libre disponible
 *
 * \param ePersona p[] pasa la estructura
 * \param int tam la cantidad de veces a iterar para la busqueda (tamaño del vector struct)
 * \return indice del espacio libre
 *
 */

int obtenerEspacioLibre(ePersona p[],int tam)
{
    int i;
    int indice=-1;

    for(i=0;i<tam;i++)
    {
        if(p[i].estado==0)
        {
           indice=i;
           break;
        }
    }

    return indice;
}

/** \brief Busca a una persona guardada, con el dato de su dni
 *
 * \param ePersona p[] pasa la estructura
 * \param tam, el tamaño del vector
 * \param dni el dni a buscar
 * \return indice de donde estan los datos de la persona o -1 si no se encontro.
 *
 */

int buscarPorDni(ePersona p[],int tam, int dni)
{
    int indice=-1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(p[i].estado == 1 && p[i].dni==dni)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


/** \brief inicializa el estado de la estructura en 0 (vacio)
 *
 * \param
 * \param
 * \return
 *
 */

void inicializar(ePersona p[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        p[i].estado=0;
    }
}


/** \brief Imprime los datos de la estructura indicada
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarPersona(ePersona p)
{
    printf("%s\t%d\t%d\n",p.nombre,p.edad,p.dni);
}


/** \brief Itera la funcion mostrarPersona, imprimiendo todos los datos guardados.
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarPersonas(ePersona p[], int tam)
{
    int i;
    system("cls");
    printf("\t--LISTA ORDENADA POR NOMBRE--\n\n");
    printf("NOMBRE\tEDAD\tDNI\n");

    for(i=0;i<tam;i++)
    {
        if(p[i].estado==1)
        {
            mostrarPersona(p[i]);
        }
    }
}


/** \brief Carga otra estructura ePersona al sistema, validando que no se repita el dni.
 *
 * \param
 * \param
 * \return
 *
 */

void agregarPersona(ePersona p[],int tam)
{
    int indice,dni,estadni;

    ePersona nuevaP;

    system("cls");

    printf("\t--CARGAR PERSONA--\n\n");

    indice=obtenerEspacioLibre(p,tam);

    if(indice==-1)
    {
        printf("El sistema esta lleno. No hay espacio libre.\n");
    }
    else
    {
        dni=validaNumero("Ingrese numero de dni","Error. Ingrese numero de dni valido");

        estadni=buscarPorDni(p,tam,dni);

        if(estadni!=-1)
        {
            printf("Este dni %d ya esta cargado.\n",dni);
            printf("NOMBRE\tEDAD\tDNI\n");
            mostrarPersona(p[estadni]);

        }
        else
        {
            nuevaP.estado=1;
            nuevaP.dni=dni;

            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%s",nuevaP.nombre);

            while(num_char(nuevaP.nombre)==0)
            {
                printf("Error. Ingrese un nombre valido: ");
                fflush(stdin);
                scanf("%s",nuevaP.nombre);
            }

            caracterProlijo(nuevaP.nombre);

            nuevaP.edad=validaNumero("Ingrese edad","Error. Ingrese una edad valida");

            while(nuevaP.edad<1||nuevaP.edad>120)
            {
                printf("Error. Ingrese una edad valida: ");
                scanf("%d",&nuevaP.edad);
            }

            p[indice]=nuevaP;

            printf("\n\nSe ha realizado la carga.\n\n");
        }
    }
}

/** \brief Cambia el estado a 0, bajando a la persona del sistema
 *
 * \param
 * \param
 * \return
 *
 */
void bajarPersona(ePersona p[],int tam)
{
    int dni,esta;
    char rta;

    system("cls");
    printf("\t--BAJA--\n\n");

    dni=validaNumero("Ingrese numero de dni","Error. Ingrese numero de dni valido");

    esta=buscarPorDni(p,tam,dni);

    if(esta==-1)
    {
        printf("Este dni %d no existe.\n",dni);
    }
    else
    {
        printf("Se encontro la persona. ");
        printf("Nombre\tEdad\tDNI\n");
        mostrarPersona(p[esta]);

        rta=continuaS_N();

        if(rta=='s')
        {
            p[esta].estado=0;
            printf("Se ha dado de baja a la persona.\n");
        }
        else if(rta=='n')
        {
            printf("Se ha cancelado la operacion.\n");
        }
    }
}

char continuaS_N()
{
    char rta;
    printf("Desea continuar con la operacion?: ");
    fflush(stdin);
    scanf("%c",&rta);

    rta=tolower(rta);

    while(!(rta=='n' || rta=='s'))
    {
        printf("Ingrese una respuesta valida S/N: ");
        fflush(stdin);
        scanf("%c",&rta);
        rta=tolower(rta);
    }

    return rta;
}


/** \brief Ordena las estructuras segun el nombre, alfabeticamente.
 *
 * \param en caso de que dos nombres sean iguales, se los ordena segun el salario.
 * \param
 * \return
 *
 */

void ordenarxNombre(ePersona p[],int tam)
{
    int i,j;
    ePersona aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(p[i].nombre,p[j].nombre)>0)
            {
                aux=p[i];
                p[i]=p[j];
                p[j]=aux;
            }
            else if(strcmp(p[i].nombre,p[j].nombre)==0)
            {
                if(p[i].edad>p[j].edad)
                {
                    aux=p[i];
                    p[i]=p[j];
                    p[j]=aux;
                }
            }
        }
    }
    mostrarPersonas(p,tam);
}


/** \brief Se asegura de que los nombres esten guardados con primer letra Mayus y las demas Minus
 *
 * \param
 * \param
 * \return
 *
 */

void caracterProlijo(char cadena[50])
{
    strlwr(cadena);
    cadena[0]=toupper(cadena[0]);
}


/** \brief Informa al usuario si el dato ingresado es numero o caracteres
 *
 * \param
 * \param
 * \return el valor de flag. [0] si es numero, [1] si son caracteres.
 *
 */

int num_char(char palabra[])
{
    int flag,i,cant;

    flag = 0;
    cant = strlen(palabra);


        for(i=0; i<cant; i++)
        {
            if(!isdigit(palabra[i]))
            {
                flag = 1;
                break;
            }
        }

    return flag;
}

/** \brief Pide un numero y valida que asi lo sea.
 *
 * \param message mensaje especifico a mostrar para ingresar el dato.
 * \param eMessage mensaje a mostrar en caso de error.
 * \param Guarda el numero en un array de caracteres, lo recorre con un for.
 * \param Comprueba que sea un numero. Si no es asi, lo pide nuevamente.
 * \param Si es un numero, lo castea a entero.
 * \return Numero validado
 *
 */

int validaNumero(char message[],char eMessage[])
{
    char dato[15];
    int flag,i, cant,num;
    int cont=0;

    do
    {
        if(cont>=1)
        {
            printf("%s: ",eMessage);
            fflush(stdin);
            scanf("%s",dato);
        }
        else if(cont==0)
        {
            printf("%s: ",message);
            fflush(stdin);
            scanf("%s",dato);
        }

        cont++;

        flag = 0;
        cant = strlen(dato);

        for(i=0; i<cant; i++)
        {
            if(!isdigit(dato[i]))
            {
                flag = 1;
                break;
            }
        }

    }while(flag == 1);

    if(flag==0)
    {
        num=atoi(dato);
    }

    return num;

}


/** \brief Imprime un grafico de tres barras segun los grupos de edades requeridos
 *
 * \param
 * \param
 * \return
 *
 */

void grafico(ePersona p[],int tam)
{
    int i,mayor;
    int flag=0;
    int edad[3];
    /*  edad[0]= <18
        edad[1]= 19-35
        edad[2]= >35
    */

    system("cls");
    printf("\t--GRAFICO--\n\n");

    for(i=0;i<3;i++)
    {
        edad[i]=0;
    }

    for(i=0;i<tam;i++)
    {
        if(p[i].estado==1)
        {
            if(p[i].edad<19)
            {
                edad[0]=edad[0]+1;
            }
            else if(p[i].edad>35)
            {
                edad[2]=edad[2]+1;
            }
            else
            {
                edad[1]=edad[1]+1;
            }

        }
    }


    for(i=0;i<3;i++)
    {
        if(edad[i]>mayor||flag==0)
        {
            mayor=edad[i];
            flag=1;
        }
    }

    //printf("<18: %d, 19-35: %d, >35: %d\n\n\n",edad[0],edad[1],edad[2]);

    for(i=mayor;i>0;i--)
    {
        if(i%5==0)
        {
            printf("%d.",i);
        }
        else if(i==1)
        {
            printf("1.");
        }

        if(i<=edad[0])
        {
            printf("\t *\t\t  ");
        }
        else
        {
            printf("\t  \t\t  ");
        }

        if(i<=edad[1])
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }

        if(i<=edad[2])
        {
            printf("\t\t *\n");
        }
        else
        {
            printf("\t\t  \n");
        }
    }

    printf("\n\t<18\t\t19-35\t\t>35\n\n");
}

