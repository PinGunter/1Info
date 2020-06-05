#include <iostream>
#include <vector>

using namespace std;

void descomposicion (int n, vector<int> &factores, int & num_factores);

int main(){
    int numero = 0; 
    vector<int> factores;
    int n_factores = 0;

    cout << "Introduce el número a descomponer: ";
    cin >> numero;

    descomposicion(numero, factores, n_factores);

    cout << "\nLa descomposición es:\n";
    for (int i=0; i < factores.size(); i++)
        cout << factores.at(i) << " ";
    cout << endl;
}

void descomposicion (int n, vector<int> &factores, int & num_factores){
    if (n != 1){
        bool fin = false;
        int maxdiv = n;

        for (int i=2; !fin; i++){
            if (n % i == 0){
                maxdiv = i;
                fin = true;
            }
        }
        factores.push_back(maxdiv);
        num_factores++;
        descomposicion(n/maxdiv, factores, num_factores);
    }
}