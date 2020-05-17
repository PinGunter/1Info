/* Programa para implentar una estructura fecha y trabajar con ella.
Calculo del dia siguiente, del anterior y si es a�o bisiesto

03/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

//Declaracion de estructura fecha

struct fecha {
   int dia;
   int mes;
   int anio;
};

//Programa principal

int main (){
   const char barra = '/';    // Constante para separar la fecha
   //Declaracion de variables
   fecha fecha_us;            //Fecha del usuario
   fecha fecha_var;           //Fecha variable con la que trabajaremos
   int dia, mes, anio;        //Variables para referirme a fecha_var.int y no escribir la expresion completa


   //----- Entrada de datos ------
   
   cout << "Introduce el dia, mes y anio (separados por espacios):\n";
   cin >> fecha_us.dia >> fecha_us.mes >> fecha_us.anio;
   
   //Asignamos los valores a la fecha variable para trabajar con ella
   
   fecha_var = fecha_us;   //Apartado d del ejercicio

   dia = fecha_var.dia;
   mes = fecha_var.mes;
   anio = fecha_var.anio;

   //Declaraciones de variables booleanas
   
   bool es_bisiesto = (anio%4 == 0) && ((anio%100 !=0) || (anio%400 == 0));      //Se evalua a True si es bisiesto
   
   bool mes31 = mes%2==1 || mes==8 || mes == 12;                              //Si es true el mes tiene 31 dias
         
   bool fecha_normal = dia <= 27 && dia >= 1;                                 //Consideramos una fecha normal aquella que no esta en el extremo final
   
   bool primero_de_mes = dia == 1;                                            //Primer dia del mes

   bool fin_de_anio = dia == 31 && mes == 12;                                 //Ultimo dia del anio, habra que cambiar dia mes y anio.

   bool primero_de_anio = dia == 1 && mes ==1;                              //Primer dia del anio, habra que cambiar dia mes y anio.


    // ----- Actualizar la fecha al dia siguiente ---- //

    //Comenzamos a escribir las condiciones del programa
    if (fecha_normal){
    dia += 1;
    }
    else if (mes == 2){                                                    //Comprobamos si es febrero, un caso especial
    if (dia ==28 && es_bisiesto){
            dia += 1;
        }
        else{
            dia = 1;
            mes += 1;
        }
    }
    
    else{
    if (dia < 31 && mes31){
            dia += 1;
        }
    
    else{
        dia = 1;
        mes += 1;
    }
    }
    //Puede darse el caso de que la fecha introducida sea el 31 de diciembre o el 1 de enero
    //Establecemos condicion para eso

    if (fin_de_anio){
    dia = 1;
    mes = 1;
    anio += 1;
    }

    //Imprimimos los resultados
    cout << "Un dia siguiente al introducido es: " << dia << barra << mes << barra << anio << endl;
    


    // ----- Actualizar la fecha al dia anterior ----- //

    //Condiciones del programa
    if (primero_de_mes){
    if (mes == 3){
        if (es_bisiesto){
            dia = 29;
            mes -= 1;
        }
        else{
            dia = 28;
            mes -= 1;
        }
    }
    else{
        if (!mes31){
            dia = 31;
            mes -= 1;
        }
        else{
            dia = 30;
            mes -= 1;
        }
    }
    }
    else{
    dia -= 1;
    }

    //Puede darse el caso de que sea 1 de enero
    if (primero_de_anio){
    dia = 31;
    mes = 12;
    anio -= 1;
    }

    //Imprimimos los resultados
    cout << "Un dia anterior al introducido es " << dia << barra << mes << barra << anio << endl;


    system("pause");
   
}


