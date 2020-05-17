//extraordinario practico 2019
#include <iostream>

using namespace std;

class Tramo{
   private:
      string inicio,final;
      double distancia;
   public:
      Tramo();
      Tramo(string ciudad1, string ciudad2, double dist);

      string GetInicio();

      string GetFinal();

      double GetDistancia();

      void Mostrar();

      void SetInicio(string ciudad);
      void SetFinal(string ciudad);
      void SetDistancia(double dist);

};

class Ruta{
   private:
      static const int LONG = 100;
      Tramo recorrido [LONG];
      int numero_rutas;

      int BuscarInicioTramo(string city);
      int BuscarFinalTramo(string city);
      bool IntroValida(Tramo nuevo, int indice);

   public:
      Ruta();
      Ruta(int num_ruta);
      Ruta(int num_ruta, Tramo rutas[]);

      double DistanciaTotal();
      double DistanciaEntre(string ciudad1, string ciudad2);
      
      void AniadirTramo(Tramo nuevo);
      void SustituirTramo(Tramo nuevo);

      void SetNumeroRutas(int num);
      Tramo GetTramo(int indice);
      int GetNumRutas();
};

int main(){
   int numero_tramos = 0;
   string ciudad1, ciudad2;
   double distancia;
   Ruta senda_feliz;
   Tramo auxiliar;
   cout << "Introduce la ruta: \n";
   do{
      cin >> ciudad1;
      if (ciudad1 != "#"){
         cin >> ciudad2 >> distancia;
			auxiliar.SetInicio(ciudad1);
			auxiliar.SetFinal(ciudad2);
			auxiliar.SetDistancia(distancia);
         senda_feliz.AniadirTramo(auxiliar);
         numero_tramos++;
      }
   } while (ciudad1 != "#");
   senda_feliz.SetNumeroRutas(numero_tramos);

   cout << "\nIntroduce el tramo que vas a sustituir: ";
   cin >> ciudad1 >> ciudad2 >> distancia;
	auxiliar.SetInicio(ciudad1);
	auxiliar.SetFinal(ciudad2);
	auxiliar.SetDistancia(distancia);	
	
	senda_feliz.SustituirTramo(auxiliar);
	
	numero_tramos = senda_feliz.GetNumRutas();
   cout << "\nLa ruta queda como:\n";
   for (int i=0; i < numero_tramos; i++){
      senda_feliz.GetTramo(i).Mostrar();
      cout << endl;
   }
}

Tramo::Tramo(string ciudad1, string ciudad2, double dist){
   inicio = ciudad1;
   final = ciudad2;
   distancia = dist;
}

void Tramo::SetInicio(string ciudad){
   inicio = ciudad;
}

void Tramo::SetFinal(string ciudad){
   final = ciudad;
}

void Tramo::SetDistancia(double dist){
   distancia = dist;
}

string Tramo::GetInicio(){
   return inicio;
}

string Tramo::GetFinal(){
   return final;
}

double Tramo::GetDistancia(){
   return distancia;
}

Tramo::Tramo(){
   inicio = final = "";
   distancia = 0;
}

void Tramo::Mostrar(){
   cout << "(" << inicio << " - " << final << ", " << distancia << ")";
}

Tramo Ruta::GetTramo(int indice){
   return recorrido[indice];
}

int Ruta::GetNumRutas(){
   return numero_rutas;
}

void Ruta::SetNumeroRutas(int num){
   numero_rutas = num;
}

Ruta::Ruta(){
   numero_rutas = 0;
}

Ruta::Ruta(int num_rutas){
   numero_rutas = num_rutas;
}

Ruta::Ruta(int num_rutas, Tramo rutas[]){
   numero_rutas = num_rutas;
   for (int i=0; i < numero_rutas; i++)
      recorrido[i] = rutas[i];
}

int Ruta::BuscarInicioTramo(string city){
   int posicion = -1;
   for (int i=0; i < numero_rutas; i++){
      if (recorrido[i].GetInicio()== city)
         posicion = i;
   }
   return posicion;
}

int Ruta::BuscarFinalTramo(string city){
   int posicion = -1;
   for (int i=0; i< numero_rutas; i++){
      if (recorrido[i].GetFinal() == city)
         posicion = i;
   }
   return posicion;
}
bool Ruta::IntroValida(Tramo nuevo, int indice){
   bool valido, condicion1, condicion2;
   condicion1 = BuscarFinalTramo(nuevo.GetInicio()) == indice-1;
   condicion2 = BuscarInicioTramo(nuevo.GetFinal()) == -1 && BuscarFinalTramo(nuevo.GetFinal()) == -1;
   valido = condicion1 && condicion2 && nuevo.GetDistancia() > 0;
   return valido;
}

double Ruta::DistanciaTotal(){
   double total = 0;
   for (int i=0; i < numero_rutas; i++)
      total += recorrido[i].GetDistancia();
   return total;
}

double Ruta::DistanciaEntre(string ciudad1, string ciudad2){
   int inicio = BuscarInicioTramo(ciudad1);
   int final = BuscarFinalTramo(ciudad2);
   double distancia = 0;
   
   if (inicio == -1 || final == -1) 
      distancia = -1;
   else{
      for (int i=inicio; i <= final; i++)
         distancia += recorrido[i].GetDistancia();
   }
   return distancia;
}

void Ruta::AniadirTramo(Tramo nuevo){
   bool valido = IntroValida(nuevo, numero_rutas);
   if (valido){
      recorrido[numero_rutas] = nuevo;
      numero_rutas++;
   }
}

void Ruta::SustituirTramo(Tramo nuevo){
   int distancia_original = DistanciaEntre(nuevo.GetInicio(), nuevo.GetFinal());
   int distancia_nueva = nuevo.GetDistancia();

   if (distancia_original != -1 && distancia_nueva > 0){
      int inicio = BuscarInicioTramo(nuevo.GetInicio());
      int final = BuscarFinalTramo(nuevo.GetFinal());
      if (distancia_nueva <= distancia_original){
         for (int i=inicio+1; i <= final; i++){
            for (int j=i; j < numero_rutas; j++)
               recorrido[j] = recorrido [j+1];
            numero_rutas--;
         }
         recorrido[inicio] = nuevo;
      }
   }
}
