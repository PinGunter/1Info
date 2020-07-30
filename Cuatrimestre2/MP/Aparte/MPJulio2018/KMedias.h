/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KMedias.h
 * Author: salva
 *
 * Created on 13 de junio de 2020, 19:55
 */

#ifndef KMEDIAS_H
#define KMEDIAS_H
#include "Cluster.h"
class KMedias{
private:
    int K;
    Cluster *clusters;
    void reservarMemoria(int n=0);
    void liberar();
    void copiar(const KMedias &otro);
public:
    KMedias();
    KMedias(const KMedias & otro);
    ~KMedias();
    KMedias & operator=(const KMedias & otro);
    void clearAndSetX(int n);
    int clusterMasCercano(const Punto &p) const;
    double cohesion() const;
    
    friend std::ostream & operator<<(std::ostream & os, const KMedias &km);
    friend std::istream & operator>>(std::istream & is, KMedias & km);
};
std::ostream & operator<<(std::ostream & os, const KMedias &km);

#endif /* KMEDIAS_H */

