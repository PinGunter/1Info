/* MP JULIO 2018*/

#include "Punto.h"
#include "VectorPuntos.h"
#include "Cluster.h"
#include "KMedias.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int uniforme(int min, int max){
    srand(time(NULL));
    int rng = rand () % max + min;
    return rng;
}

int main(){
    
}