#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"
#include "stdbool.h"

/// /// /// ///       PROTOTIPOS       ////////////////

/// 1   funciones int
int cargarArregloIntPorConsola(int A[],int dimension);

//2
void mostrarArrayInt  (int A[],int validos);

//3
int sumaArrayInt (int A[],int validos);

//4
void copiarArrayAPila (int A[],int validos,Pila* B);
/// 5   funciones float
int cargarArreglofloatPorConsola(float A[],int dimension);

void mostrarArrayfloat  (float A[],int validos);

//5
float sumaArrayFloat (float A[],int validos);

int llenarArrayFloat (float A[], int dimension);

/// 6   funciones char
int cargarArregloCharPorConsola(char A[],int dimension);

void mostrarArrayChar  (char A[],int validos);
//6
void printfFlag(int FLAG);
int flagParaCharacteres (char A[],int validos,char wanted);

/// 7

void insertarCaracter(char A[],int validos, char letraAinsertar);

/// 8

char maximoCaracterDeArray (char A[],int validos);

/// 9
bool arregloCapicua(char A[],int validos);

/// 10
void invertirArray (int A[],int validos);

/// 11
int posMenorArrayInt (int A[],int validos,int pos);
void ordenacionSeleccion(int A[],int validos);

void insertar(int A[ ], int U, int dato);
void ordenacionInsercion(int A[ ], int cantVal);

/// 12
void nuevoArrayOrdenado(int A[],int B[],int destino[],int valDestino);
/// 13
void paseAcumulativo (int A[],int destino[],int validos);
int main()
{
    /// srand (time(NULL) al inicio para que cada vez que se use (rand()%algun num) funcione
    srand(time(NULL));
    /*arrays*/
    /// /// /// declaracion de array /// /// ///
    /*tipo de dato  nombre_del_array  [dimensión];*/
    int arregloCero [9];
    int arrayDesordenado [] = {2,4,7,6,3,5,1};
    int ordenadoUno [5] = {1,3,5,7,9};
    int ordenadoDos[4] = {2,4,6,8};
    int destiny[9] ;
    int vector[5]= {1,5,6,7,8};

    float arregloFloat [100];
    char arregloChar [4];
    char abc [5] = {'a','e','i','o','u'};
    char capicua [90] = {'n','e','u','q','u','e','s'};

    /// declaracion de pilas // // // // // //

    Pila pilita;
    inicpila(&pilita);

    /// //////////     declaracion de variables      ////////////////////


    char letrota;
    char WANTED ='l';
    float   resultadofloat;
    int bandera=0;
    int caso,numero;
    int validos;
    char seguir='s';


    do
    {
        printf("ingrese un numero entero del 1 al 13 para ver los distintos ejercicios\n");
        printf("1:carga arreglo de enteros  \n2:muestra arreglo de enteros  \n3:suma elementos de un arreglo de enteros\n");
        printf("4:copia los datos de un arreglo a una pila    \n5:suma arreglo de float   \n6:avisa si un elemento se encuentra dentro del arreglo\n");
        printf("7:inserta un caracter en un arreglo ordenado alfabeticamente   \n8:obtiene el maximo caracter de un arreglo dado  \n9:determina si un arreglo es capicua\n");
        printf("10:invierte los elementos de un arreglo\n11:ordema un arreglo segun los metodos de seleccion e insercion\n12:crear un arreglo en base a dos arreglos ordenados de caracteres intercalando los elementos\n");
        printf("13:suma de forma acumulativa los datos del arreglo;{1,5,6,7,8}:{1,6,12,19,27}:\n");

        scanf("%d", &caso);
        switch(caso)
        {
        case 1:

            validos = cargarArregloIntPorConsola(arregloCero,9);
            printf("la cantidad de validos son %d\n",validos);

            break;
        case 2:

            mostrarArrayInt(arregloCero,validos);
            break;
        case 3:

            numero=sumaArrayInt(arregloCero,validos);
            printf("la suma del arreglo es %d\n",numero);

            break;
        case 4:
            copiarArrayAPila(arregloCero,validos,&pilita);

            mostrar(&pilita);
            break;
        case 5:
            validos=llenarArrayFloat(arregloFloat,100);
            printf("------------\n");
            mostrarArrayfloat(arregloFloat,validos);
            printf("------------\n");
            resultadofloat = sumaArrayFloat(arregloFloat,validos);
            printf("resultado de la suma: %f",resultadofloat);

            break;
        case 6:
            validos=cargarArregloCharPorConsola(arregloChar,4);

            mostrarArrayChar(arregloChar,validos);
            bandera=flagParaCharacteres(arregloChar,validos,WANTED);
//printf("\n!!!estado de bandera[%d]!!!\n",bandera);
            printfFlag(bandera);
            break;
        case 7:
            validos=5;
            //printf("%d",validos);
            mostrarArrayChar(abc,validos);
            insertarCaracter(abc,validos,'k');
            validos++;
            mostrarArrayChar(abc,validos);

            break;
        case 8:
            ///   validos=sizeof(abc);
            validos=5;
            mostrarArrayChar(abc,validos);
            letrota=maximoCaracterDeArray(abc,validos);
            printf("\nla letra mas grande del arreglo es :[%c]\n",letrota);

            break;
        case 9:
            validos=7;
            mostrarArrayChar(capicua,validos);
            if (arregloCapicua(capicua,validos))
            {
                printf("\nel arreglo es capicua\n");
            }
            else
            {
                printf("\nel arreglo NO es capicua\n");
            }

            break;
        case 10:
            validos=cargarArregloIntPorConsola(arregloCero,9);
            printf("estos son los validos\n%d\n",validos);
            mostrarArrayInt(arregloCero,validos);
            printf("------------------------\n");
            invertirArray(arregloCero,validos);
            mostrarArrayInt(arregloCero,validos);

            break;
        case 11:
            validos=7;

            mostrarArrayInt(arrayDesordenado,validos);

           //ordenacionInsercion(arrayDesordenado,validos);

           ordenacionSeleccion(arrayDesordenado,validos);

           mostrarArrayInt(arrayDesordenado,validos);
            break;
        case 12:
            validos=9;

            mostrarArrayInt(ordenadoUno,5);
            mostrarArrayInt(ordenadoDos,4);
            nuevoArrayOrdenado(ordenadoUno,ordenadoDos,destiny,validos);

            mostrarArrayInt(destiny,validos);

            break;
        case 13:
            validos=5;
            mostrarArrayInt(vector,validos);
            paseAcumulativo(vector,destiny,validos);
            mostrarArrayInt(destiny,validos);

            break;

        default:
            printf("error, caso inexistente\n ingrese un numero del 1 al 13:");
            scanf("%d",&caso);
        }
        printf("si desea ver otro ejercicio presione s, si quiere finalizar presione algo distinto de s:\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while (seguir == 's');





    return 0;
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// /////////////////////////////////////////////////           funciones          ///////////////////////////////////////////////////////////////////////////////////

/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/// //////////1carga de arreglo
int cargarArregloIntPorConsola(int A[],int dimension)
{
    int validos =0;
    char c='s';
    while((c=='s')&&(validos<dimension))
    {
        printf("ingrese un numero para cargar:");
        scanf("%d",&A[validos]);

        validos++;
        printf("para cargar otro numero ingrese's' ");
        fflush(stdin);
        scanf("%c",&c);

    }
    return validos;
}

/// //////////2 muestra contenido de arreglo
void mostrarArrayInt  (int A[],int validos)
{
    int i=0;
    printf("\nContenido del arreglo:\n");
    while(i<validos)
    {
        /*lee varios valores dentro de un vector */
        printf("[%d]\n",A[i]);
        i++;
    }
}

/// /////////////3 suma los elementos de un arreglo
int sumaArrayInt (int A[],int validos)
{
    int total=0;
    int i =0;

    for(i; i<validos; i++)
    {
        total+=A[i];
    }
    return total;
}
/// /////////////////// 4 copia un arreglo a una pila
void copiarArrayAPila (int A[],int validos,Pila* B)
{
    int i=0;

    for(i; i<validos; i++)
    {
        apilar(B,A[i]);
    }
}

/// //////////////// 5 subfunciones para datos tipo float y sumar elementos de array float

int cargarArreglofloatPorConsola(float A[],int dimension)
{
    int validos =0;
    char c='s';
    while((c=='s')&&(validos<dimension))
    {
        printf("ingrese un numero para cargar:");
        scanf("%f",&A[validos]);

        validos++;
        printf("para cargar otro numero ingrese's' ");
        fflush(stdin);
        scanf("%c",&c);

    }
    return validos;
}

void mostrarArrayfloat  (float A[],int validos)
{
    int i=0;
    printf("\nContenido del arreglo:\n");
    while(i<validos)
    {
        /*lee varios valores dentro de un vector */
        printf("[%.2f]\n",A[i]);
        i++;
    }
}

float sumaArrayFloat (float A[],int validos)
{
    float total=0;
    int i =0;

    for(i; i<validos; i++)
    {
        total+=A[i];
    }
    return total;
}

int llenarArrayFloat (float A[], int dimension)
{
    int validos =0;

    while(validos<dimension)
    {
        A[validos]=(float)(rand()%99) * 1.01;

        validos++;
    }
    return validos;
}

/// ///////////////// 6 subfunciones para datos tipo char y encontrar elemento buscado
int cargarArregloCharPorConsola(char A[],int dimension)
{
    int validos =0;
    char c='s';
    while((c=='s')&&(validos<dimension))
    {
        printf("ingrese una letra para cargar:");
        fflush(stdin);
        scanf("%c",&A[validos]);

        validos++;
        printf("para cargar otra letra ingrese's' ");
        fflush(stdin);
        scanf("%c",&c);

    }
    return validos;
}
void mostrarArrayChar  (char A[],int validos)
{
    int i=0;
    printf("\nContenido del arreglo:\n");
    while(i<validos)
    {
        /*lee varios valores dentro de un vector */
        printf("[%c]",A[i]);
        i++;
    }
}

void printfFlag(int FLAG)
{
    if(FLAG==0)
    {
        printf("\nel elemento buscado no se encuentra aqui\n");
    }
    else
    {
        printf("\nel elemento buscado si se encuentra aca!!!!!\n");
    }

}

int flagParaCharacteres (char A[],int validos,char wanted)
{
    int flag=0;
    int i =0;

    for(i; i<validos; i++)
    {
        if(A[i] == wanted)
        {
            flag+=1;
            break;
        }
        else
        {
            flag=0;
        }
    }
    return flag;

}

/// //////////////// 77777777 ////////////////////
void insertarCaracter(char A[],int validos, char letraAinsertar)
{
    //busca la posicion donde se va a insertar
    int i=0;
    while(i<validos && letraAinsertar>A[i])
    {
        i++;
    }
//desplaza los elementos posteriores a la posicion de la insercion copiando el dato de la posicion j en una posicion adelante
    for(int j=validos; j>=i+1; j--)
    {
        A[j]=A[j-1];
    }
//inserta caracter en la posicion correcta
    A[i]=letraAinsertar;
}

/// /////////// 8888888888888 ///////////////////////////

char maximoCaracterDeArray (char A[],int validos)
{
    /// Le asigno el valor de la primera posicion del arreglo
    char maxChar=A[0];

    for(int i=0; i<=validos; i++)
    {
        if (maxChar<A[i])
        {
            maxChar=A[i];
        }

    }
    return maxChar;
}

/// /////////////////// 999 ////////////////////////////////
bool arregloCapicua(char A[],int validos)
{
    int i=0;

    int j=validos-1;

    while (i<j)
    {
        if(A[i]!=A[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

/// /////////// 10 10 10 10 10 10 10 10 10 /////////////////////////////

void invertirArray (int A[],int validos)
{
    int i=0;
    int j=validos-1;
    int cajita=0;

    while(i<=j)
    {
        cajita=A[i];
        A[i]=A[j];
        A[j]=cajita;
        i++;
        j--;
    }

}

/// ///////// 11 11 11 11 11 11 11 11 11 11 11 11 /////////////////////////

/// subfuncion para ordenacion por seleccion
int posMenorArrayInt (int A[],int validos,int pos)
{
    int menor=A[pos];
    int posMenor=pos;
    int index=pos+1;

    while(index<validos)
    {
        if(menor>A[index])
        {
            menor=A[index];
            posMenor=index;
        }
        index++;
    }
    return posMenor;
}
/// funcion principal para ordenar por seleccion un arreglo
void ordenacionSeleccion(int A[],int validos)
{
    int aux;
    int posmenor;
    int i=0;
    while(i<validos-1) /// no hace falta revisar la ultima posicion ya que va a ser el mayor
    {
        posmenor = posMenorArrayInt(A,validos,i);
        aux=A[posmenor]; /// intercambia los valores utilizando un auxiliar
        A[posmenor] = A[i];
        A[i] = aux;
        i++;
    }
}


/// subfuncion para ordenacion por insercion
void insertar(int A[ ], int U, int dato)
{

    int i= U; //ultima pos valida izq
    while (i >= 0 && dato < A[i]){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = dato;
}
/// funcion principal para ordenar por insercion un arreglo de numeros
void ordenacionInsercion(int A[ ], int cantVal)
{
    int u=0;
    while (u < cantVal - 1){
     //llega hasta la posición del anteúltimo elemento del arreglo.
        insertar(A, u, A[u+1]);
        u++;
    }
}

/// 12
void nuevoArrayOrdenado(int A[],int B[],int destino[],int valDestino)
{
    int i=0;
    int u=0;
    while(i<=valDestino)
    {
        destino[i]=A[u];
        i++;
        destino[i]=B[u];
        i++;
        u++;

    }
}

void paseAcumulativo (int A[],int destino[],int validos)
{
    int i=0;

    destino[i]=A[i];
    i++;
    while(i<=validos)
    {
        destino[i]=destino[i-1]+A[i];
        i++;
    }
}


/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//carga arreglos paralelos
/*funcion que carga un arreglo paralelo hasta que el usuario lo decida*/
//int cargaArreglosParalelos(int matricula[20],char nombre[20][30])/*20 es la dimension de los arreglos y 30 es la longitud del string*/
/*
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
*/
