/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCeldasEnlazadas.h
 * Author: salva
 *
 * Created on 31 de marzo de 2020, 17:10
 */

#ifndef LISTACELDASENLAZADAS_H
#define LISTACELDASENLAZADAS_H

struct Celda{
    double dato;
    Celda *sig;
};

#endif /* LISTACELDASENLAZADAS_H */

