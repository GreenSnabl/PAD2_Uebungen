/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatrixExceptions.h
 * Author: snbl
 *
 * Created on February 21, 2018, 6:44 PM
 */

#ifndef MATRIXEXCEPTIONS_H
#define MATRIXEXCEPTIONS_H

#include <string>
#include <exception>
#include <sstream>


using std::string; using std::ostringstream;


class MatrixOutOfRange : public std::runtime_error
{
public:
    MatrixOutOfRange() 
      : std::runtime_error("Angeforderter Wert übersteigt Matrixgrenzen") {}
};

// what() wird für eigene Fehlermeldung überschrieben

//const char * MatrixOutOfRange::what() override



class MatrixUninitialized : public std::runtime_error {
public:
    MatrixUninitialized() : std::runtime_error("Matrixelemente sind nicht initialisiert\n") {}
};


#endif /* MATRIXEXCEPTIONS_H */

