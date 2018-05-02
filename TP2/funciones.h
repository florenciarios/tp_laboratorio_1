#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;


int obtenerEspacioLibre(ePersona[],int);

int buscarPorDni(ePersona[],int,int);

void inicializar(ePersona[],int);

void mostrarPersona(ePersona);

void mostrarPersonas(ePersona p[], int tam);

void agregarPersona(ePersona[],int);

void bajarPersona(ePersona p[],int tam);

char continuaS_N();

void ordenarxNombre(ePersona p[],int tam);

void caracterProlijo(char [50]);

int num_char(char[]);

int validaNumero(char[],char[]);

void grafico(ePersona[],int);

#endif // FUNCIONES_H_INCLUDED

