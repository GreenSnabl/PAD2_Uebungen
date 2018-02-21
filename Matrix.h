/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.h
 * Author: snbl
 *
 * Created on February 18, 2018, 1:42 PM
 */

#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include <iostream>

enum Filetype {binary, ascii};


class Matrix {
public:
    Matrix();
    Matrix(int reihen, int spalten);
    Matrix(int reihen, int spalten, double wert);
    Matrix(const Matrix& matrix);
    Matrix(std::string dateiname, Filetype Dateityp);
    ~Matrix();
    
    const bool operator==(const Matrix& matrix) const;
    Matrix& operator+=(const Matrix& matrix);
    Matrix& operator-=(const Matrix& matrix);
    Matrix operator+(const Matrix& matrix) const;
    Matrix operator-(const Matrix& matrix) const;
    Matrix operator*(const Matrix& matrix) const;
    Matrix& operator=(const Matrix& matrix);
    double& operator()(int, int);
    const double operator()(int, int) const;
    
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);
    
    void readFromBinary(std::string);
    void writeToBinary(std::string);
    
    const int get_reihen() const;
    const int get_spalten() const;
    
    double& at(int reihe, int spalte);
    const double at(int reihe, int spalte) const;
        
    void print() const;
    
private:
    const bool same_size(const Matrix& matrix) const;
        
    double** m_data;
    int m_reihen;
    int m_spalten;
};


std::ostream& operator<<(std::ostream&, const Matrix&);
std::istream& operator>>(std::istream&, Matrix&);

#endif /* MATRIX_H */

