README for A3 Tester
====================

Updated by Hasan Kamal-Al-Deen
Last Updated: April 3, 2014

Usage:
======
a3test.cpp is the tester main. The .h and .hpp files are support for the testing
platform and should be placed in the same folder as a3test.cpp (and optionally
included in your visual studio project if working on Windows).

There are multiple tests that can be performed. Your assignment is considered
complete when all tests pass and you've checked your code to ensure conformance
to the spec and style guidelines.

Read the textual output to find whether your code is failing. Tester output
should be read from top to bottom. The system outputs the section it enters
as it enters it and also outputs as it exits a section.

The bonus section has not been put up yet. When it is up, this package will be
updated with further instructions.

Parameters
==========
All parameters mentioned in this README are #defines in a3test.cpp. Update them
as required.

TEST_NUM:
	Controls which test is run. The system includes different files based on
	which test is run. That means that you should be able to test different
	parts of the assignment completely indpendently of each other (Try it!)

	Testing IntListNode and IntList
	===============================
	Set to 0.
	Includes intlist.h. Requires that at least a stub implementation of every
	IntListNode and IntList function is available.

	Testing ListNode and List
	=========================
	Set to 1.
	Includes list.h. Requires that at least a stub implementation of every
	ListNode<T> and List<T> function is available.

HIDE_TIPS:
	When 1, textual tips are hidden from test output. Set this to 0 if the tests
	are failing to complete for some *possibly* helpful ideas on what could be
	wrong.

VERBOSE_TESTS:
	When 1, all tests are printed to screen, whether they pass or fail. When 0,
	only failing tests will be printed (default). Set this to 1 if you want to
	see all of the tests that the system executes on your code.
	
	Also set to 1 if you like to see a lot of text scroll across a screen.

Stub Functions
==============
A stub function is a non-functional but compiling function implementation.
For example, here's a function prototype:
	bool doStuff();

A stub for doStuff would be:
	bool doStuff(){ return false; }

This allows the test code to execute at a minimal level and will allow you
to perform continuous testing as you implement various functions.
