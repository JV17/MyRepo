/*
********************************************************************************
Templated List Tester

Written by Hasan Kamal-Al-Deen
Modified March 22, 2014
*/
#ifndef __TEMPLATEDLISTTEST_H__
#define __TEMPLATEDLISTTEST_H__

#include <string>
#include "listtesthelper.h"
#include "list.h"

void testMain(){
    using namespace Testing;
    h1("OOP344 A3 Test 1");
    h1("ListNode and List");

    int testVals0[] = {69, -500, 600};
    int numTestVals0 = sizeof(testVals0) / sizeof(int);
    testListNode<ListNode<int>, int>(testVals0, numTestVals0);
    Testing::newline();
    testList<List<int>, ListNode<int>, int>(testVals0, numTestVals0);

    newline();
    h1("-----------------------");
    h1("Next tests use std::string as value type for your List/ListNode.");
    h1("When std::string's name is displayed, it is very long, be aware of this...");
    h1("-----------------------");
    newline();

    std::string testVals1[] = {"[string 1]", "[test string 2]", "[another test string 3]"};
    int numTestVals1 = sizeof(testVals1) / sizeof(std::string);
    testListNode<ListNode<std::string>, std::string>(testVals1, numTestVals1);
    Testing::newline();
    testList<List<std::string>, ListNode<std::string>, std::string>(testVals1, numTestVals1);

    finish();
}
#endif
