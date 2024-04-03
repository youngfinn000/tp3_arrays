#include <stdio.h>
#include <stdlib.h>
void cargarArregloPorConsola (int* A[],int validos);
void mostrarArray  (int A[],int validos);

int main()
{
    /*arrays*/
    /*declaracion de array*/
    /*tipo de dato  nombre_del_array  [dimensión];*/
    int arregloCero [3];

cargarArregloPorConsola(arregloCero,3);

mostrarArray(&arregloCero,3);


    return 0;
}
//carga de arreglo
void cargarArregloPorConsola (int* A[],int validos){
    int i =0;
    char c='s';
    while((i<validos)&&(c=='s')){
            printf("ingrese un numero para cargar");
    scanf("%i",&A[i]);

    printf("para cargar otro numero ingrese's' ");
    fflush(stdin);
    scanf("%c",&c);
    i++;
    }
}

//muestra contenido de arreglo
void mostrarArray  (int A[],int validos){
int i=0;
printf("\nContenido del arreglo:\n");
while(i<validos)
{
    /*lee varios valores dentro de un vector */
 printf("[%d]\n",A[i]);
 i++;
}
}

//carga arreglos paralelos
/*funcion que carga un arreglo paralelo hasta que el usuario lo decida*/
int cargaArreglosParalelos(int matricula[20],char nombre[20][30])/*20 es la dimension de los arreglos y 30 es la longitud del string*/
{
    int i=0;
    char rta='s';

    while(i<20 && rta=='s')
    {
    printf("\Ingrese matricula del alumno:");
    scanf("%d",&matricula[i]);//arreglo de numeros enteros
    printf("ingrese el nombre del alumno(hasta 30 caracteres):");
    fflush(stdin);
    scanf("%c",&nombre[i]);//arreglo de palabras
    i++;
    printf("\n\nDesea ingresar los datos de otro alumno? (s/n):");
    fflush(stdin);
    scanf("%c",&rta);
    }

    return i;
}

void mostrarArrayParalelo (int matricula[20],char nombre[20][30],int cant)
{
    int i=0;

    while(i<cant)
    {
       printf("\tMatricula:%d\n",matricula[i]);
       printf("\tNombre:%s\n",nombre[i]);//%s se usa para las cadenas de caracteres
       i++;;
    }
}
