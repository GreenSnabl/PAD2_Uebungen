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
#include "MatrixExceptions.h"
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

/*
 * 
 */ 

int main(int argc, char** argv) {
   
    Matrix m1(2,3,4);
    Matrix m2(3,5,3);
    Matrix m3(4,3,3);
    Matrix m;
    try{
        
        m3 = m1 * m2;
        m.at(23,23);
        m2.at(45,45);
    } catch (logic_error& l)
    {
        cout << l.what() << endl;
    } catch(MatrixOutOfRange& m)
    {
        cout << m.what() << endl;
    } catch (MatrixUninitialized& i)
    {
        cout << i.what() << endl;
    }
    
    
    cout << m3;
    return 0;
}

