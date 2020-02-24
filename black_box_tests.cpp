//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     JAKUB DVORAK <xdvora3k@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author JAKUB DVORAK
 *
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

class Derived : public BinaryTree, public testing::Test
{

};


TEST_F(Derived, EmptyTree)
{
    BinaryTree t;
    ASSERT_EQ(t.GetRoot(), nullptr);
    EXPECT_EQ(t.FindNode(5), nullptr);
    EXPECT_FALSE(t.DeleteNode(5));
    std::pair<bool, BinaryTree::Node_t*> x1 = t.InsertNode(5);
    ASSERT_NE(t.GetRoot(), nullptr);
    EXPECT_TRUE(x1.first);
    std::pair<bool, BinaryTree::Node_t*> x2 = t.InsertNode(5);
    EXPECT_FALSE(x2.first);
    EXPECT_NE(t.FindNode(5), nullptr);
    EXPECT_TRUE(t.DeleteNode(5));
}

TEST_F(Derived, NonEmptyTree)
{
    BinaryTree k;
    std::pair<bool, BinaryTree::Node_t*> x3 = k.InsertNode(5);
    ASSERT_NE(k.GetRoot(), nullptr);
    std::pair<bool, BinaryTree::Node_t*> x4 = k.InsertNode(6);

}

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

/*** Konec souboru black_box_tests.cpp ***/