//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"

#include <vector>
class Test : public Matrix, public testing::Test
{
protected:
    Matrix a;

    Matrix get0x0()
    {
        Matrix m = Matrix(0, 0);
        return m;
    }
    Matrix get1x1()
    {
        Matrix m = Matrix(1, 1);
        return m;
    }
    Matrix get6x6()
    {
        Matrix m = Matrix(6, 6);
        return m;
    }
    Matrix get5x3()
    {
        Matrix m = Matrix(5, 3);
        return m;
    }
    Matrix get3x5()
    {
        Matrix m = Matrix(3, 5);
        return m;
    }
    Matrix get3x25()
    {
        Matrix m = Matrix(3, 25);
        return m;
    }
};

TEST_F(Test, kontruktor)
{
    EXPECT_NO_THROW(Matrix(250, 1));
    EXPECT_NO_THROW(Matrix(3, 3));
    EXPECT_ANY_THROW(Matrix(0, 3));
    EXPECT_ANY_THROW(Matrix(14, -3));
}

TEST_F(Test, set)
{
    Matrix b = get6x6();

    EXPECT_TRUE(b.set(0, 3, 3));
    EXPECT_TRUE(b.set(3, 3, 30));
    EXPECT_TRUE(b.set(1, 2, -5)); 

    EXPECT_FALSE(b.set(36, -5, 2));
    EXPECT_FALSE(b.set(1.5, 6, 3));
    EXPECT_FALSE(b.set(0, -5, 36));

    EXPECT_TRUE(b.set({ { 1,2,3,4,5,6 }, { 6,-4,5,-85,3,6 }, { 3,6,5,2,7,8 }, { 0,0,0,0,0,0 }, { 3,74,91,30,25,2 }, { 1,1,2,3,6,5 } }));
    EXPECT_FALSE(b.set({ { 1,2,3,4,5,6,0 }, { 6,-4,5,-85,3,6 }, { 3,6,5,2,7,8 }, { 0,0,0,0,0,0,0 }, { 3,74,91,30,25,2 }, { 1,1,2,3,6,5 } }));
    EXPECT_FALSE(b.set({ { 1,2,3,4,5,6 }, { 6,-4,5,-85,3,6 }, { 3,6,5,2,7,8 }, { 0,0,0,0,0,0 }, { 3,74,91,30,25,2 }, { 1,1,2,3,6,5 }, {63, 84, 26, 6, 6, 9} }));
    EXPECT_FALSE(b.set({ { 1,2,3,4,5,6 }, { 6,-4,5,-85,3,6 }, { 3,6,5,2,7,8 }, { 0,0,0,0,0,0 }, { 3,74,91,30,25,2 } }));
}

TEST_F(Test, get)
{
    Matrix c = get6x6();
    Matrix d = get6x6();
    Matrix e = get6x6();

    c.set(5, 5, 3);
    d.set(3, 4, 63);
    e.set({ { 1,2,3,4,5,6 }, { 6,-4,5,-85,3,6 }, { 3,6,5,2,7,8 }, { 0,0,0,0,0,0 }, { 3,74,91,30,25,2 }, { 1,1,2,3,6,5 } });

    EXPECT_EQ(c.get(5, 5), 3);
    EXPECT_NE(c.get(5, 5), 5);
    EXPECT_NE(c.get(4, 4), 3);
    EXPECT_ANY_THROW(c.get(-1, 0), 5);

    EXPECT_EQ(d.get(3, 4), 63);
    EXPECT_NE(d.get(3, 4), 62);
    EXPECT_NE(d.get(4, 4), 63);
    EXPECT_ANY_THROW(d.get(55, 4), 25);

    EXPECT_EQ(e.get(0, 5), 6);
    EXPECT_EQ(e.get(1, 3), -85);
    EXPECT_NE(e.get(3, 3), 5);
    EXPECT_ANY_THROW(e.get(6, 2), 2);
}

TEST_F(Test, porovnani)
{
    Matrix c1 = get6x6();
    Matrix c2 = get6x6();
    Matrix c3 = get6x6();
    Matrix d = get3x25();

    c1.set(2, 3, 56);
    c2.set(2, 3, 56);
    c3.set(3, 3, 56);
    d.set(2, 3, 56);

    EXPECT_TRUE(c1.operator==(c2));
    EXPECT_TRUE(c2.operator==(c1));
    EXPECT_FALSE(c3.operator==(c1));
    EXPECT_FALSE(c2.operator==(c3));
    EXPECT_ANY_THROW(c1.operator==(d));
    EXPECT_ANY_THROW(d.operator==(c1));
}

TEST_F(Test, scitani)
{
    Matrix e1 = get5x3();
    Matrix e2 = get5x3();
    Matrix e3 = get5x3();
    Matrix f = get3x25();

    e1.set({ { 1,2,3 }, { 2,3,6 }, { 5,4,6 }, { 9,3,5 }, { 2,5,7 } });
    e2.set({ { 6,8,9 }, { 3,4,8 }, { 2,8,6 }, { 1,4,6 }, { 3,9,6 } });
    e3.set(1, 1, 5);
    f.set(1, 14, -5);

    EXPECT_NO_THROW(e1.operator+(e2));
    EXPECT_NO_THROW(e3.operator+(e1));
    EXPECT_ANY_THROW(e2.operator+(f));
}

TEST_F(Test, nasobeniMatici)
{
    Matrix g1 = get5x3();
    Matrix g2 = get3x5();
    Matrix g3 = get3x25();

    g1.set({ { 6,7,8 }, { 3,7,8 }, { 2,8,6 }, { 9,5,1 }, { 2,5,7 } });
    g2.set({ { 6,8,9,3,4 }, { 3,4,8,9,7 }, { 3,5,7,9,4 } });
    g3.set(0, 16, -45);

    EXPECT_NO_THROW(g1.operator*(g2));
    EXPECT_NO_THROW(g2.operator*(g1));
    EXPECT_ANY_THROW(g2.operator*(g3));
}

TEST_F(Test, nasobeniKonstantou)
{
    Matrix h1 = get5x3();
    Matrix h2 = get3x5();
    Matrix h3 = get3x25();

    h1.set({ { 6,7,8 }, { 3,7,8 }, { 2,8,6 }, { 9,5,1 }, { 2,5,7 } });
    h2.set({ { 6,8,9,3,4 }, { 3,4,8,9,7 }, { 3,5,7,9,4 } });
    h3.set(0, 16, -45);

    EXPECT_NO_THROW(h1.operator*(6));
    EXPECT_NO_THROW(h2.operator*(-5));
    EXPECT_NO_THROW(h3.operator*(0));
}

TEST_F(Test, rovnice)
{
    Matrix i1 = get6x6();
    Matrix i2 = get1x1();
    Matrix i3 = get3x5();

    i1.set({ { 6,8,9,3,4,6 }, { 3,4,8,9,7,9 }, { 3,5,7,9,4,5 }, { 3,5,7,6,8,5 }, { 3,3,3,3,4,5 }, { 3,5,4,8,4,5 } });
    i2.set(0, 0, 6);
    i3.set({ { 6,8,9,3,4 }, { 3,4,8,9,7 }, { 3,5,7,9,4 } });

    EXPECT_NO_THROW(i1.solveEquation({ 5,6,8,1,25,2 }));
    EXPECT_NO_THROW(i2.solveEquation({1}));
    EXPECT_ANY_THROW(i3.solveEquation({ 6,5,4,3,2 }));
}


//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

/*** Konec souboru white_box_tests.cpp ***/
