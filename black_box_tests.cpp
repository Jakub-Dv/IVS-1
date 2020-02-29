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
protected:
    BinaryTree t;
};

class NonEmptyTree : public BinaryTree, public testing::Test
{
protected:
    BinaryTree k;
    std::vector<int> v = {1, 5, 20, 9, 14, -4, 3};
    std::vector<std::pair<bool, Node_t *>> outNewNodes;
};

class TreeAxioms : public BinaryTree, public testing::Test
{
protected:
    BinaryTree l;
    std::vector<int> v = {9, 5, 47, -15, -4, 3, 7, -9, 38, 45, 14, 15, 16, 17};
    std::vector<std::pair<bool, Node_t*>> outNewNodes;
    std::vector<Node_t*> outLeafNodes;
    std::vector<Node_t*> outAllNodes;
    std::vector<Node_t*> nonLeafNodes;
};

TEST_F(EmptyTree, InsertNode)
{
    std::pair<bool, BinaryTree::Node_t*> x, y, z;
    EXPECT_FALSE(x.first);
    x = t.InsertNode(5);
    EXPECT_TRUE(x.first);
    EXPECT_NE(x.second, nullptr);

    EXPECT_FALSE(y.first);
    y = t.InsertNode(-5);
    EXPECT_TRUE(y.first);
    EXPECT_NE(y.second, nullptr);
    EXPECT_EQ(y.second->pParent, x.second);
    
    EXPECT_FALSE(z.first);
    z = t.InsertNode(0);
    EXPECT_TRUE(z.first);
    EXPECT_NE(z.second, nullptr);
    EXPECT_EQ(x.second->pParent, z.second);
    EXPECT_EQ(x.second->pParent->pLeft, y.second);
}

TEST_F(EmptyTree, DeleteNode)
{
    std::pair<bool, BinaryTree::Node_t*> x;
    EXPECT_FALSE(t.DeleteNode(5));
    EXPECT_FALSE(t.DeleteNode(-5));
    x = t.InsertNode(5);
    EXPECT_TRUE(x.first);
    EXPECT_NE(x.second, nullptr);
    EXPECT_TRUE(t.DeleteNode(5));
}

TEST_F(EmptyTree, FindNode)
{
    EXPECT_EQ(t.FindNode(5), nullptr);
    EXPECT_EQ(t.FindNode(-5), nullptr);
    std::pair<bool, BinaryTree::Node_t*> x = t.InsertNode(5);
    EXPECT_NE(t.FindNode(5), nullptr);
}

TEST_F(NonEmptyTree, InsertMode)
{
    k.InsertNodes(v, outNewNodes);
    std::pair<bool, BinaryTree::Node_t*> y = k.InsertNode(5);
    EXPECT_FALSE(y.first);
    std::pair<bool, BinaryTree::Node_t*> z1 = k.InsertNode(4);
    EXPECT_TRUE(z1.first);
    EXPECT_NE(z1.second, nullptr);
    std::pair<bool, BinaryTree::Node_t*> z2 = k.InsertNode(-5);
    EXPECT_TRUE(z2.first);
    EXPECT_NE(z2.second, nullptr);
    EXPECT_EQ(z1.second->pParent->pParent, z2.second->pParent->pParent);
}

TEST_F(NonEmptyTree, FindNode)
{
    k.InsertNodes(v, outNewNodes);
    EXPECT_TRUE(k.FindNode(-4));
    EXPECT_FALSE(k.FindNode(6));
    
}

TEST_F(NonEmptyTree, DeleteNode)
{
    k.InsertNodes(v, outNewNodes);
    EXPECT_FALSE(k.DeleteNode(-3));
    EXPECT_TRUE(k.DeleteNode(5));
}

TEST_F(TreeAxioms, Axiom1)
{
    l.InsertNodes(v, outNewNodes);
    l.GetLeafNodes(outLeafNodes);
    for (int i = 0; i < outLeafNodes.size(); i++)
    {
        EXPECT_TRUE(outLeafNodes[i]->color);
    }
}

TEST_F(TreeAxioms, Axiom2)
{
    l.InsertNodes(v, outNewNodes);
    l.GetNonLeafNodes(nonLeafNodes);
    for (int i = 0; i < nonLeafNodes.size(); i++)
    {
        if (!(nonLeafNodes[i]->color))
        {
            EXPECT_TRUE(nonLeafNodes[i]->pLeft->color && nonLeafNodes[i]->pRight->color);
        }
    }
}

TEST_F(TreeAxioms, Axiom3)
{
    l.InsertNodes(v, outNewNodes);
    l.GetLeafNodes(outLeafNodes);
    for (int i = 0; i < outLeafNodes.size(); i++)
    {

        int count2 = 0, count1 = -1;
        Node_t* parent = outLeafNodes[i];
        while (parent)
        {
            if (parent->color == BLACK)
            {
                count2++;
            }
            parent = parent->pParent;
        }
        if (count1 >= 0)
        {
            EXPECT_EQ(count1, count2);
        }
        count1 = count2;
    }
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