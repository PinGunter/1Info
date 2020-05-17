/* Programa para implementar una clase fecha con metodos para modificarla y trabajar con ella

    25/11/2019
    Salvador romero Cortes
*/

#include <iostream>

using namespace std;

class Fecha{
     private:
        /*Metodo para comprobar si la fecha es valida
        * Creamos un vector booleano indicando si los meses son de 31 dias o no
        * Los anios siempre son validos
        * Comprobamos que el mes este entre 1 y 12
        * Si es febrero comprobamos si es bisiesto
            *Si es bisiesto el dia entre 1 y 29
            *Si no entre 1 y 28
        * Miramos si es de 31 o 30 dias y que este entre 1 y 31 o 30 respectivamente
        */
        bool FechaValida(int d, int m, int a){
            bool valida = false;
            bool meses31[12] = {1,0,1,0,1,0,1,1,0,1,0,1};
            
            if (m >= 1 && m <= 12){
                if (m ==2){
                    es_bisiesto = (a%4 == 0) && ((a%100 !=0) || (a%400 == 0));
                    
                    if (es_bisiesto){
                        if (d <= 29 && d >= 1)
                            valida = true;
							}
							else
								if (d <= 28 && d >= 1)
									valida = true;
                }
                else if ( meses31[m-1] ){
                    if (d <= 31 && d >= 1)
                        valida = true;
                }
                else
                    if (d <= 30 && d>=1)
                        valida = true;
            }
            
            return valida;
        }

        bool fecha_normal = dia <= 27 && dia >= 1;
        bool es_bisiesto = (anio%4 == 0) && ((anio%100 !=0) || (anio%400 == 0));    
        bool meses31[12] = {1,0,1,0,1,0,1,1,0,1,0,1};


    public:
        int dia,mes,anio;
        
        void IntroducirFecha(){
            bool valida;
            do{
                cout << "Introduce la fecha:\nDia: ";
                cin >> dia;
                
                cout << "\nMes: ";
                cin >> mes;

                cout << "\nAnio: ";
                cin >> anio;
                
                valida = FechaValida(dia, mes, anio);
                
                if(!valida)
                    cout << "Fecha incorrecta.\n";
                
            } while(!valida);
        }

        void MostrarFecha(){
            cout << dia << "/" << mes << "/" << anio << endl;
        }

        void DiaSiguiente(){
            if (fecha_normal){
                dia += 1;
            }
            else if (mes == 2){                                                         //Comprobamos si es febrero, un caso especial
                if (dia ==28 && es_bisiesto){
                        dia += 1;
                    }
                    else{
                        dia = 1;
                        mes += 1;
                    }
                }
            else{
                if (dia < 31 && meses31[mes-1]){
                        dia += 1;
                    }
                else{
                    if (dia < 30 && !meses31[mes-1]){
                        dia += 1;
                        }
                        else{
                            dia = 1;
                        mes += 1;
                            }
                }
            }
            //Puede darse el caso de que la fecha introducida sea el 31 de diciembre o el 1 de enero
            //Establecemos condicion para eso
            if (dia == 31 && mes == 12){
                dia = 1;
                mes = 1;
                anio += 1;
            }
        }
        void DiaAnterior(){
            if (dia == 1){
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
                    if (!meses31[mes-1]){
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
            if (mes == 1 && dia == 1){
                dia = 31;
                mes = 12;
                anio -= 1;
            }
        }
};

int main(){
    //declaracion de variables
    Fecha date;
    //introduccion de datos
    date.IntroducirFecha();

    //computos
    cout << "La fecha siguiente es: ";
    date.DiaSiguiente();
    date.MostrarFecha();

    cout << "\nLa fecha anterior es: ";
    //lo ejecutamos dos veces para no volver solo al original
    date.DiaAnterior();
    date.DiaAnterior();
    date.MostrarFecha();
}
