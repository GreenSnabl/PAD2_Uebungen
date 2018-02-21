/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snbl
 *
 * Created on February 18, 2018, 1:41 PM
 */

#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

/*
 * 
 */ 

int main(int argc, char** argv) {
   
    
 /*
    cout << m2;
    ifstream infile("matrix01.txt");
    if(infile.good()) infile >> m2;
    cout << m2;
   */ 
    
    Matrix m1("matrix01.txt", ascii);
    ofstream ofs("matrix02.txt");
    ofs << m1;
    ofs.close();
    m1.writeToBinary("bin1.save");
    Matrix m2("matrix03.txt", ascii);
    
    
    cout << m1;
    cout << m2;
    
    Matrix m3 = m1 * m2;
    Matrix m4 = m2 * m1;
    
    m3.print();
    m4.print();
    
    cout << m3;
    cout << m4;
    
    m3.writeToBinary("bin2.save");
    m4.writeToBinary("bin3.save");
    Matrix m5("bin2.save", binary);
    Matrix m6("bin3.save", binary);
    cout << m5;
    cout << m6;
    
    Matrix m7(5,4,5);
    m7.writeToBinary("bin4.save");
    
    
    return 0;
}

