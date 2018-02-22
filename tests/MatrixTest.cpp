/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MatrixTest.cpp
 * Author: snbl
 *
 * Created on Feb 21, 2018, 4:26:50 PM
 */

#include "MatrixTest.h"
#include "../Matrix.h"
#include "../MatrixExceptions.h"


CPPUNIT_TEST_SUITE_REGISTRATION(MatrixTest);

MatrixTest::MatrixTest() {
}

MatrixTest::~MatrixTest() {
}

void MatrixTest::setUp() {
    m1 = new Matrix;
    m2 = new Matrix(5, 4);
    m3 = new Matrix(5, 4, 5);
    m4 = new Matrix(5, 4, 3);
    m5 = new Matrix(5, 4, 2);
    m6 = new Matrix(5, 4, 10);
    m7 = new Matrix("matrix01.txt", ascii);
    m8 = new Matrix("matrix02.txt", ascii);
    m9 = new Matrix("bin1.save", binary);
}

void MatrixTest::tearDown() {
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
    delete m6;
    delete m7;
    delete m8;
    delete m9;
}

void MatrixTest::testMatrix() {
    Matrix matrix;
    CPPUNIT_ASSERT(matrix.get_reihen() == 0);
    CPPUNIT_ASSERT(matrix.get_spalten() == 0);
}

void MatrixTest::testMatrix2() {
    int reihen = 5;
    int spalten = 6;
    Matrix matrix(reihen, spalten);
    CPPUNIT_ASSERT(matrix.get_reihen() == 5);
    CPPUNIT_ASSERT(matrix.get_spalten() == 6);

}

void MatrixTest::testMatrix3() {
    int reihen = 3;
    int spalten = 2;
    double wert = 10;
    Matrix matrix(reihen, spalten, wert);
    CPPUNIT_ASSERT(matrix.get_reihen() == 3);
    CPPUNIT_ASSERT(matrix.get_spalten() == 2);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j) {
            if (matrix.at(i, j) != 10)
                CPPUNIT_ASSERT(false);
        }
}

void MatrixTest::testMatrix4() {
    Matrix matrix(*m3);
    CPPUNIT_ASSERT(matrix.get_reihen() == 5 && m3->get_reihen() == 5);
    CPPUNIT_ASSERT(matrix.get_spalten() == 4 && m3->get_spalten() == 4);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j) {
            if (matrix.at(i, j) != 5 || m3->at(i, j) != 5)
                CPPUNIT_ASSERT(false);
        }

}

void MatrixTest::testMatrix5() {
    std::string dateiname = "matrix01.txt";
    std::string dateiname2 = "matrix02.txt";
    std::string dateiname3 = "bin1.save";

    int cnt = 1;

    Filetype Dateityp = ascii;
    Filetype Dateityp2 = binary;

    Matrix matrix1(dateiname, Dateityp);
    Matrix matrix2(dateiname2, Dateityp);
    Matrix matrix3(dateiname3, Dateityp2);

    CPPUNIT_ASSERT(matrix1.get_reihen() == 2 && matrix2.get_reihen() == 2 && matrix3.get_reihen() == 2);
    CPPUNIT_ASSERT(matrix1.get_spalten() == 3 && matrix2.get_spalten() == 3 && matrix3.get_spalten() == 3);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j) {
            CPPUNIT_ASSERT(matrix1.at(i, j) == cnt && matrix2.at(i, j) == cnt && matrix3.at(i, j) == cnt);
            ++cnt;
        }
}

void MatrixTest::testReadFromBinary() {
    std::string dateiname = "bin4.save";
    Matrix matrix;
    matrix.readFromBinary(dateiname);
    CPPUNIT_ASSERT(matrix.get_reihen() == 5 && m3->get_reihen() == 5);
    CPPUNIT_ASSERT(matrix.get_spalten() == 4 && m3->get_spalten() == 4);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 4; ++j) {
            CPPUNIT_ASSERT(matrix.at(i, j) == 5);
        }
    CPPUNIT_ASSERT_THROW(matrix.readFromBinary("ungueltiger_Dateiname.nope"), std::ios_base::failure);
}

void MatrixTest::testWriteToBinary() {
}

void MatrixTest::testGet_reihen() {
    CPPUNIT_ASSERT(m4->get_reihen() == 5);
}

void MatrixTest::testGet_spalten() {
    CPPUNIT_ASSERT(m4->get_spalten() == 4);
}

void MatrixTest::testAt() {
    CPPUNIT_ASSERT_THROW(m1->at(1,1), MatrixUninitialized);
    CPPUNIT_ASSERT_THROW(m3->at(54,54), MatrixOutOfRange);
    Matrix matrix(2, 2, 2);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            matrix.at(i, j) = 10;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CPPUNIT_ASSERT(matrix.at(i, j) == 10);
}

void MatrixTest::testAt2() {
    CPPUNIT_ASSERT_THROW(m1->at(1,1), MatrixUninitialized);
    CPPUNIT_ASSERT_THROW(m3->at(54,54), MatrixOutOfRange);
    for (int i = 0; i < m3->get_reihen(); ++i)
        for (int j = 0; j < m3->get_spalten(); ++j)
            CPPUNIT_ASSERT(m3->at(i, j) == 5);
}


void MatrixTest::testAdd(){;}
void MatrixTest::testSub(){;}
void MatrixTest::testCompoundAdd(){;}
void MatrixTest::testCompoundSub(){;}
void MatrixTest::testMult(){;}
void MatrixTest::testEqual(){;}
void MatrixTest::testParenteses(){;}
void MatrixTest::testAssignment(){;}
