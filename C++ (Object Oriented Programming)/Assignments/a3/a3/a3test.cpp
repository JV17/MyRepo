/*
********************************************************************************
Primary test file for OOP344 A3.

Written by Hasan Kamal-Al-Deen.
Modified April 3, 2014.

Usage:
Modify the TEST_NUM define to induce various tests.
Define VERBOSE_TESTS to 1 to force all tests (pass or fail) to produce output. Maybe useful for some debugging.
Define HIDE_TIPS to 1 to silence tip-related messages. Set to 1 if tips are making reading difficult.

The tests are divided as follows:

Test 0: int linked list
Test 1: templated linked list
*/

// Modify these defines to control behavior of test engine
#define TEST_NUM 1
#define VERBOSE_TESTS 0
#define HIDE_TIPS 1

// Defines for internal engine use. DO NOT MODIFY
#ifndef VERBOSE_TESTS
#define VERBOSE_TESTS 0
#endif

#ifndef HIDE_TIPS
#define HIDE_TIPS 0
#endif

#if TEST_NUM == 0
#include "intlisttest.h"
#elif TEST_NUM == 1
#include "templatedlisttest.h"
#endif

int main(){
    testMain();
}
