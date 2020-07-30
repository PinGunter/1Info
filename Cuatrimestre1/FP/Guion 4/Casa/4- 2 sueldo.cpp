/*
Programa que sube el sueldo un 5% si es jubilado con ingresos inferiores a 300 euros
Tambien subiremos un 4% si es mayor de 65 o menor de 35. Ademas si es inferior a 300
se le sube otro 3%.

    ENTRADA --> edad y salario de la persona
    SALIDA --> salario resultante

04/10/2019
Salvador Romero Cortes
*/

#include <iostream>                 //Inlcuimos los recursos de E/S

using namespace std;

// Programa principal

int main(){
/*  ###################################################################
    # PRIMER APARTADO                                                 #
    # SUBIR SALARIO 5% SI ES JUBILADO Y GANA MENOS DE 300             #
    #    PRIMERA OPCION                                               #              
    #    Mezclando E/S y computos dentro de la estructura condicional #
    ###################################################################
    
    //Declaracion de constantes
    const double subida_cinco = 1 + 0.05;
    //Declaracion de variables
    int edad;
    double ingresos;
    double ingresos_final;

    if (true){
        cout << "Introduce la edad: ";
        cin >> edad;
        cout << "\nIntroduce el salario: ";
        cin >> ingresos;
        ingresos_final = ingresos;
        
        bool jubilado = edad >= 67;
        bool bajos_ingresos = ingresos < 300;

        if (jubilado && bajos_ingresos){
            ingresos_final *= subida_cinco; 
        }
        else{
            cout << "No es aplicable la subida.\n";
        }

        cout << "El salario resultante es --> " << ingresos_final << " euros" <<endl;
    }
*/
    /*
    ###################################################################
    # PRIMER APARTADO                                                 #
    # SUBIR SALARIO 5% SI ES JUBILADO Y GANA MENOS DE 300             #
    #    SEGUNDA OPCION                                               #              
    #    Separando E/S y computos en bloques distintos                #
    ###################################################################
    
    //Declaracion de constantes para los porcentajes

    const double subida_cinco = 1 + 0.05;

    //Declaracion de variables

    int edad;
    double ingresos;
    double ingresos_final;

    //Entrada de datos
    
    cout << "Introduce tu edad --> ";
    cin >> edad;

    cout << "\nIntroduce tus ingresos --> ";
    cin >> ingresos;

    ingresos_final = ingresos;

    //Declarmos las variables booleanas

    bool jubilado = edad >= 67;
    bool bajos_ingresos = ingresos < 300;

    //Calculos, condicionales

    if (jubilado && bajos_ingresos){
        ingresos_final *= subida_cinco;
    }
    else{
        cout << "No es aplicable la subida.\n";
    }

    //Independientemente de la condicion imprimios el salario final

    cout << "El salario resultante es --> " << ingresos_final << " euros" << endl;
   */
  /*
    ###################################################################
    # SEGUNDO APARTADO                                                #
    # SUBIR SALARIO 4% SI ES MAYOR DE 35 O MENOR DE 35.               #
    # SI ADEMAS  GANA MENOS DE 300 SE LE SUBE OTRO 3%                 #
    ###################################################################
    */

   //Declaramos las constantes de las subidas de precio

   const double subida_cuatro = 1 + 0.04;
   const double subida_tres = 1 + 0.03;

   //Declaracion de variables

   int edad;
   double ingresos;
   double ingresos_final;

   //Entrada de datos

   cout << "Introduce tu edad --> ";
   cin >> edad;

   cout << "Introduce tus ingresos --> ";
   cin >> ingresos;

   ingresos_final = ingresos;

   //Declaramos las variables booleanas

   bool aplicable_por_edad = edad >= 65 || edad <= 35;
   bool bajos_ingresos = ingresos_final < 300;

   //Comenzamos la estructura condicional

   if (aplicable_por_edad)
      ingresos_final *= subida_cuatro;
   else
   	cout << "No es aplicable a la subida.\n";

   if (aplicable_por_edad && bajos_ingresos)
      ingresos_final *= subida_tres;

   //Salida de datos

   cout << "Los ingresos resultantes son --> " << ingresos_final << " euros" << endl;

   //Sentencia para detener el programa

   system("pause");
   
}
