/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.cpp
 * Author: snbl
 * 
 * Created on February 18, 2018, 1:42 PM
 */

#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "MatrixExceptions.h"

using std::cout;
using std::endl;




Matrix::Matrix() : m_reihen{0}, m_spalten{0}, m_data{nullptr}
{
}

Matrix::Matrix(int reihen, int spalten) : m_reihen{reihen}, m_spalten{spalten}
{
    m_data = new double*[m_reihen];
    for (int i = 0; i < m_reihen; ++i) {
        m_data[i] = new double[m_spalten];
    }
}

Matrix::Matrix(int reihen, int spalten, double wert) : m_reihen{reihen}, m_spalten{spalten}
{
    m_data = new double*[m_reihen];
    for (int i = 0; i < m_reihen; ++i) {
        m_data[i] = new double[m_spalten];
    }

    for (int i = 0; i < m_reihen; ++i)
        for (int j = 0; j < m_spalten; ++j)
            m_data[i][j] = wert;
}

Matrix::Matrix(const Matrix& matrix) : m_reihen{matrix.get_reihen()}, m_spalten{matrix.get_spalten()}
{
    m_data = new double*[matrix.get_reihen()];
    for (int i = 0; i < matrix.get_reihen(); ++i) {
        m_data[i] = new double[matrix.get_spalten()];
    }
    for (int i = 0; i < get_reihen(); ++i)
        for (int j = 0; j < get_spalten(); ++j)
            at(i, j) = matrix.at(i, j);
}

Matrix::Matrix(std::string dateiname, Filetype dateityp) : m_spalten{0}, m_reihen{0}, m_data{nullptr}
{
    if(dateityp == binary) this->readFromBinary(dateiname);
    else {
        std::ifstream infile(dateiname);
        infile >> *this;
    }
}


Matrix::~Matrix() {
    for (int i = 0; i < m_reihen; ++i) {
        delete[] m_data[i];
    }
    delete[] m_data;
}

double& Matrix::at(int reihe, int spalte) {
    if(m_data == nullptr) throw MatrixUninitialized();
    if (reihe >= m_reihen || spalte >= m_spalten) throw MatrixOutOfRange();
    return m_data[reihe][spalte];
}

const double Matrix::at(int reihe, int spalte) const {
    if(m_data == nullptr) throw MatrixUninitialized();
    if (reihe >= m_reihen || spalte >= m_spalten) throw MatrixOutOfRange();
    return m_data[reihe][spalte];
}

const bool Matrix::same_size(const Matrix& matrix) const {
    return (matrix.get_reihen() == get_reihen() && matrix.get_spalten() == get_spalten());
}

const int Matrix::get_reihen() const {
    return m_reihen;
}

const int Matrix::get_spalten() const {
    return m_spalten;
}

const bool Matrix::operator==(const Matrix& matrix) const {
    if (!same_size(matrix)) {
        return false;
    }
    for (int i = 0; i < get_reihen(); ++i)
        for (int j = 0; j < get_spalten(); ++j) {
            if (matrix.at(i, j) != at(i, j)) {
                return false;
            }
        }
    return true;
}

Matrix Matrix::operator+(const Matrix& matrix) const {
    if (!same_size(matrix)) { throw std::logic_error("Addition nicht möglich: Matrizen besitzen unterschiedliche Größe.\n");//return Matrix(*this);
    }
    Matrix temp(*this);
    for (int i = 0; i < temp.get_reihen(); ++i)
        for (int j = 0; j < temp.get_spalten(); ++j) {
            temp.at(i, j) += matrix.at(i, j);
        }
    return temp;
}

Matrix Matrix::operator-(const Matrix& matrix) const {
    if (!same_size(matrix)) { throw std::logic_error("Subtraktion nicht möglich: Matrizen besitzen unterschiedliche Größe.\n");// return Matrix(*this);
    }
    Matrix temp(*this);
    for (int i = 0; i < temp.get_reihen(); ++i)
        for (int j = 0; j < temp.get_spalten(); ++j) {
            temp.at(i, j) -= matrix.at(i, j);
        }
    return temp;
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
    if (!(this->get_spalten() == matrix.get_reihen()) || this->get_spalten() == 0) throw std::logic_error("Multiplikation nicht möglich: Ungleiche Spalten- und Reihengröße\n");// {return Matrix(*this);}
    Matrix temp(this->get_reihen(), matrix.get_spalten(), 0);
    for(int i = 0; i < this->get_reihen(); ++i){
        for(int j = 0; j < matrix.get_spalten(); ++j){
            for(int k = 0; k < this->get_spalten(); ++k)
            {
                temp.at(i,j) +=  this->at(i,k) * matrix.at(k,j);
            }            
        }
    }
    return temp;
}

Matrix& Matrix::operator+=(const Matrix& matrix) {
    if (!same_size(matrix)) { throw std::logic_error("Addition nicht möglich: Matrizen besitzen unterschiedliche Größe.\n");// return *this;
    }
    for (int i = 0; i < get_reihen(); ++i)
        for (int j = 0; j < get_spalten(); ++j) {
            at(i, j) += matrix.at(i, j);
        }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& matrix) {
    if (!same_size(matrix)) { throw std::logic_error("Subtraktion nicht möglich: Matrizen besitzen unterschiedliche Größe.\n");//  return *this;
    }
    for (int i = 0; i < get_reihen(); ++i)
        for (int j = 0; j < get_spalten(); ++j) {
            at(i, j) -= matrix.at(i, j);
        }
    return *this;
}

Matrix& Matrix::operator=(const Matrix& matrix) {
    if (same_size(matrix)) {
        for (int i = 0; i < get_reihen(); ++i)
            for (int j = 0; j < get_spalten(); ++j) {
                at(i, j) = matrix.at(i, j);
            }
        return *this;
    }
    if (m_data != nullptr) {
        for (int i = 0; i < get_reihen(); ++i) {
            delete[] m_data[i];
        }
        delete[] m_data;
    }

    m_reihen = matrix.get_reihen();
    m_spalten = matrix.get_spalten();

    m_data = new double*[matrix.get_reihen()];
    for (int i = 0; i < matrix.get_reihen(); ++i) {
        m_data[i] = new double[m_spalten];
    }

    for (int i = 0; i < get_reihen(); ++i)
        for (int j = 0; j < get_spalten(); ++j) {
            at(i, j) = matrix.at(i, j);
        }
    return *this;
}

double& Matrix::operator()(int reihe, int spalte) {
    if(m_data == nullptr) throw MatrixUninitialized();
    if (reihe >= m_reihen || spalte >= m_spalten) throw MatrixOutOfRange();
    return m_data[reihe][spalte];
}

const double Matrix::operator()(int reihe, int spalte) const {
    if(m_data == nullptr) throw MatrixUninitialized();
    if (reihe >= m_reihen || spalte >= m_spalten) throw MatrixOutOfRange();
    return m_data[reihe][spalte];
}

void Matrix::readFromBinary(std::string dateiname)
{
    std::ifstream binary(dateiname, std::ios::binary);
    if(!binary.good()) throw std::ios_base::failure("Datei konnte nicht geöffnet werden: Dateiname ungültig\n");
    
    if(m_data != nullptr){
    for(int i = 0; i < get_reihen(); ++i){
        delete[] m_data[i];
    }
    delete[] m_data;
    }
    binary.read(reinterpret_cast<char*>(&m_reihen), sizeof(m_reihen));
    binary.read(reinterpret_cast<char*>(&m_spalten), sizeof(m_spalten));
    
    m_data = new double*[m_reihen];
    for (int i = 0; i < m_reihen; ++i)
    {
        m_data[i] = new double[m_spalten]; 
    }
    for(int i = 0; i < m_reihen; ++i)
        for (int j = 0; j < m_spalten; ++j)
        {
            binary.read(reinterpret_cast<char*>(&m_data[i][j]),sizeof(m_data[i][j]));
        }
}
void Matrix::writeToBinary(std::string dateiname)
{
    std::ofstream binary(dateiname, std::ios::binary);
    binary.write(reinterpret_cast<char*>(&m_reihen), sizeof(m_reihen));
    binary.write(reinterpret_cast<char*>(&m_spalten), sizeof(m_spalten));
    for(int i = 0; i < m_reihen; ++i)
        for(int j = 0; j < m_spalten; ++j)
        {
            binary.write(reinterpret_cast<char*>(&m_data[i][j]), sizeof(m_data[i][j]));        
        }
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    os << matrix.m_reihen << "x" << matrix.m_spalten << " - Matrix\n";
    for (int i = 0; i < matrix.get_reihen(); ++i){
        for (int j = 0; j < matrix.get_spalten(); ++j)
        {
            os << matrix(i,j) << " ";
        }
        os << "\n";
    }
    os << "\n";
}

std::istream& operator>>(std::istream& is, Matrix& matrix)
{
    for(int i = 0; i < matrix.get_reihen(); ++i){
        delete[] matrix.m_data[i];
    }
    delete[] matrix.m_data;
    char c;
    is >> matrix.m_reihen >> c >> matrix.m_spalten;
    while(is >> c) {
        if(isdigit(c)) 
        {
            is.unget(); 
            break;
        }
    }
    
    /*for(int i = 0; i < 7; ++i)
        is >> c;*/

    matrix.m_data = new double*[matrix.m_reihen];
    for (int i = 0; i < matrix.m_reihen; ++i)
    {
        matrix.m_data[i] = new double[matrix.m_spalten]; 
    }
    for(int i = 0; i < matrix.m_reihen; ++i)
        for (int j = 0; j < matrix.m_spalten; ++j)
            is >> matrix(i,j);
}



void Matrix::print() const {
    cout << get_reihen() << "x" << get_spalten() << " - " << "Matrix\n\n";
    for (int i = 0; i < get_reihen(); ++i) {
        for (int j = 0; j < get_spalten(); ++j) {
            cout << at(i, j) << " ";
        }
        cout << "\n";
    }
    cout << endl;
}