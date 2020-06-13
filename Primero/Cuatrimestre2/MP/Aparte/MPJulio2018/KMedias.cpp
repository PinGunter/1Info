/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "KMedias.h"

void KMedias::reservarMemoria(int n) {
    if (n > 0) {
        clusters = new Cluster[n];
        K = n;
    } else {
        clusters = nullptr;
        K = 0;
    }
}

void KMedias::liberar() {
    if (clusters != nullptr)
        delete [] clusters;
    clusters = nullptr;
    K = 0;
}

void KMedias::copiar(const KMedias& otro){
    for (int i=0; i < otro.K; i++)
        clusters[i] = otro.clusters[i];
    K = otro.K;
}

KMedias::KMedias(){
    reservarMemoria(2);
}

KMedias::~KMedias(){
    liberar();
}

KMedias & KMedias::operator =(const KMedias& otro){
    if (this != &otro){
        liberar();
        reservarMemoria(otro.K);
        copiar(otro);
    }
    return *this;
}

void KMedias::clearAndSetX(int n){
    liberar();
    reservarMemoria(n);
}

std::ostream & operator<<(std::ostream & os, const KMedias &km){
    os << km.K;
    for (int i=0; i < km.K; i++)
        os << km.clusters[i] << std::endl;
    return os;
}

std::istream & operator>>(std::istream &is, KMedias & km){
    int in_k;
    is >> in_k;
    if (is){
        km.clearAndSetX(in_k);
        for (int i=0; i < in_k; i++)
            is >> km.clusters[i];
    } else {
        std::cerr << "error leyendo KMedias " << std::endl;
    }
    
    return is;
}

int KMedias::clusterMasCercano(const Punto& p) const{
    double minimo = 0.0;
    double calculado = 0.0;
    int i_minimo = 0;
    for (int i=0; i < K; i++){
       calculado = p.getDistancia(clusters[i].getCentroide());
       if (i == 0){
           minimo = calculado;
           i_minimo = i;
       } else{
           if (calculado < minimo){
               minimo = calculado;
               i_minimo = i;
           }
       }
    }
    
    return i_minimo;
}

double KMedias::cohesion() const{
    double distancia_media = 0.0;
    int num_comb = 0;
    for (int i=0; i < K; i++){
        for (int j = i+1; j < K; j++){
            distancia_media += clusters[i].getCentroide().getDistancia(clusters[j].getCentroide());
            num_comb ++;
        }
    }
    distancia_media /= num_comb;
    return distancia_media;
}