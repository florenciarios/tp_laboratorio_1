#include <stdio.h>
/**
 * \brief realiza la operacion de SUMA de dos float
 * \param recibe las variables
 * \param suma las variables
 * \return el resultado de la suma de variables
 *
 */

 float suma(float x, float y)
 {
     float result;

     result = x + y;

     printf("Suma: %.2f \n",result);

     return result;
 }

 /**
 * \brief realiza la operacion de RESTA de dos float
 * \param recibe las variables
 * \param resta las variables
 * \return el resultado de la resta de variables
 *
 */

 float resta(float x, float y)
 {
     float result;

     result = x - y;

     printf("Resta: %.2f \n",result);

     return result;
 }

 /**
 * \brief realiza la operacion de DIVISION de dos float
 * \param recibe las variables
 * \param valida que la segunda variable recibida (y) no sea 0
 * \param realiza la division
 * \return el resultado de la division de variables
 *
 */

 float division(float x, float y)
 {
     float result;

     while(y==0)
     {
         printf("Error. No se puede hacer una division por 0: ");
         scanf("%f",&y);
     }

     result = x / y;

     printf("Division: %.2f \n",result);

     return result;
 }

 /**
 * \brief realiza la operacion de MULTIPLICACION de dos float
 * \param recibe las variables
 * \param multiplica las variables
 * \return el resultado de la multiplicacion de variables
 *
 */

 float multiplicacion(float x, float y)
 {
     float result;

     result = x * y;

     printf("Multiplicacion: %.2f \n",result);

     return result;
 }

/**
 * \brief realiza la operacion de FACTOREO de una variable
 * \param recibe la variable factorear en float, la convierte a int
 * \param valida que el numero no sea negativo
 * \param se hace la factorizacion
 * \return el resultado del factoreo de la variable
 *
 */

 int factoreo(float x)
 {
    int result=1,i;

    while((int)x<=0)
    {
        printf("Error. Reingrese. Para la factorizacion el numero debe ser positivo: ");
        scanf("%f",&x);
    }

    for(i=(int)x;i>0;i--)
    {
        result=result*i;
    }

    printf("Factoreo de %d: %.2d \n",(int)x,result);

    return result;
 }
