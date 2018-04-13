#include <stdio.h>


/**
 * \brief realiza la operación de SUMA de dos float
 * \param recibe las variables
 * \param result = suma las variables
 * \return el resultado de la suma de variables
 *
 */

 float plusOp(float x, float y)
 {
     float result;

     result = x + y;

     printf("\nSuma: %.2f \n\n",result);

     return result;
 }

 /**
 * \brief realiza la operación de RESTA de dos float
 * \param recibe las variables
 * \param result = resta las variables
 * \return el resultado de la resta de variables
 *
 */

 float minusOp(float x, float y)
 {
     float result;

     result = x - y;

     printf("\nResta: %.2f \n\n",result);

     return result;
 }

 /**
 * \brief realiza la operación de DIVISIÓN de dos float
 * \param recibe las variables
 * \param valida que la segunda variable recibida (y) no sea 0
 * \param result = realiza la division
 * \return el resultado de la division de variables
 *
 */

 float divideOp(float x, float y)
 {
     float result;

     while(y==0)
     {
         printf("Error. No se puede hacer una division por 0: ");
         scanf("%f",&y);
     }

     result = x / y;

     printf("\nDivision: %.2f \n\n",result);

     return result;
 }

 /**
 * \brief realiza la operación de MULTIPLICACION de dos float
 * \param recibe las variables
 * \param result = multiplica las variables
 * \return el resultado de la multiplicación de variables
 *
 */

 float multiplyOp(float x, float y)
 {
     float result;

     result = x * y;

     printf("\nMultiplicacion: %.2f \n\n",result);

     return result;
 }

/**
 * \brief realiza la operación de FACTOREO de una variable
 * \param recibe la variable en float, la convierte a int
 * \param valida que el número no sea negativo
 * \param se hace la factorización
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

    printf("\nFactoreo de %d: %.2d \n\n",(int)x,result);

    return result;
 }

/**
* \brief si el usuario no ingresa ambos operandos, se le advierte
* \param recibe la cantidad de veces que se han ingresado operandos
* \param realiza la advertencia con un if
* \return void
*
*/

void opMissing(int x)
{
    if(x<2)
    {
        printf("\nAdvertencia. No le asigno valor a todos los operandos.\nSe le establece el valor de 0. \n \n");

    }
}
