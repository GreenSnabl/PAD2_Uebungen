/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MatrixTest.h
 * Author: snbl
 *
 * Created on Feb 21, 2018, 4:26:50 PM
 */

#ifndef MATRIXTEST_H
#define MATRIXTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Matrix.h"

class MatrixTest : public CPPUNIT_NS::TestFixture {
    
    Matrix *m1, *m2, *m3, *m4, *m5, *m6, *m7, *m8, *m9;
    
    CPPUNIT_TEST_SUITE(MatrixTest);

    CPPUNIT_TEST(testMatrix);
    CPPUNIT_TEST(testMatrix2);
    CPPUNIT_TEST(testMatrix3);
    CPPUNIT_TEST(testMatrix4);
    CPPUNIT_TEST(testMatrix5);
    CPPUNIT_TEST(testReadFromBinary);
    CPPUNIT_TEST(testWriteToBinary);
    CPPUNIT_TEST(testGet_reihen);
    CPPUNIT_TEST(testGet_spalten);
    CPPUNIT_TEST(testAt);
    CPPUNIT_TEST(testAt2);

    CPPUNIT_TEST_SUITE_END();

public:
    MatrixTest();
    virtual ~MatrixTest();
    void setUp();
    void tearDown();

private:
    void testMatrix();
    void testMatrix2();
    void testMatrix3();
    void testMatrix4();
    void testMatrix5();
    void testReadFromBinary();
    void testWriteToBinary();
    void testReadMatrixFromFile();
    void testSaveMatrixToFile();
    void testGet_reihen();
    void testGet_spalten();
    void testAt();
    void testAt2();
    
    void testAdd();
    void testSub();
    void testCompoundAdd();
    void testCompoundSub();
    void testMult();
    void testEqual();
    void testParenteses();
    void testAssignment();

};

#endif /* MATRIXTEST_H */

