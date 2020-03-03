//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy 
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{

}

PriorityQueue::~PriorityQueue()
{
    Element_t* position = GetHead();
    while (position != nullptr)
    {
        position = position->pNext;
        delete position->pPrev;
    }
}

void PriorityQueue::Insert(int value)
{
    Element_t* el = new Element_t;
    el->value = value;
    Element_t* position = GetHead();
    while (value < position->value)
    {
        position = position->pNext;
    }
    el->pNext = position->pNext;
    el->pPrev = position;

    position->pNext->pPrev = el;
    position->pNext = el;
}

bool PriorityQueue::Remove(int value)
{
    Element_t* position = Find(value);
    if (position == NULL)
    {
        return false;
    }
    position->pNext->pPrev = position->pPrev;
    position->pPrev->pNext = position->pNext;
    delete position;
    return true;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{
    Element_t* position = GetHead();
    while (value != position->value)
    {
        position = position->pNext;
        if (position == NULL)
        {
            return NULL;
        }
    }
    return position;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{


    return NULL;
}

/*** Konec souboru tdd_code.cpp ***/
