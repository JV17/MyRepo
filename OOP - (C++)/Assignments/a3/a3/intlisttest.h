/*
********************************************************************************
IntList Tester

Written by Hasan Kamal-Al-Deen
Modified March 22, 2014
*/
#ifndef __INSTLISTTEST_H__
#define __INSTLISTTEST_H__

#include "listtesthelper.h"
#include "intlist.h"

void testMain(){
    using namespace Testing;
    h1("OOP344 A3 Test 0");
    h1("IntListNode and IntList");

    int testVals[] = {69, -500, 600};
    int numTestVals = sizeof(testVals) / sizeof(int);
    testListNode<IntListNode, int>(testVals, numTestVals);
    testList<IntList, IntListNode, int>(testVals, numTestVals);

    finish();
}
#endif
