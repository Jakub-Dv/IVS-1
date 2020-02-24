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

class EmptyTree : public BinaryTree, public testing::Test
{
public:
    BinaryTree t;
};

class NonEmptyTree : public BinaryTree, public testing::Test
{
public:
    BinaryTree k;

};

TEST_F(EmptyTree, InsertNode)
{
    std::pair<bool, BinaryTree::Node_t*> x = t.InsertNode(5);
    EXPECT_TRUE(x.first);
    EXPECT_NE(x.second, nullptr);
}

TEST_F(EmptyTree, DeleteNode)
{
    EXPECT_FALSE(t.DeleteNode(5));
    t.InsertNode(5);
    EXPECT_TRUE(t.DeleteNode(5));
}

TEST_F(EmptyTree, FindNode)
{
    EXPECT_EQ(t.FindNode(5), nullptr);
    std::pair<bool, BinaryTree::Node_t*> x = t.InsertNode(5);
    EXPECT_NE(t.FindNode(5), nullptr);
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