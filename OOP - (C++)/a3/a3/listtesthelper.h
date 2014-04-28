/*
********************************************************************************
List Test Helper
Contains test operations for lists.

Written by Hasan Kamal-Al-Deen
Modified March 21, 2014

Note to STUDENTS:
You will notice that a fair number of lines have been copy pasted. There is
about 3 to 5 simple tricks and 1 or 2 relatively complex tricks that I could
have used to make this file significantly less redundant in terms of lines of
code. I did not use any of those tricks to maintaim maximum clarity of the code
provided.

-Hasan
*/
#ifndef __LISTTESTHELPER_H__
#define __LISTTESTHELPER_H__

#include <typeinfo>
#include <string>
#include <sstream>
#include "tester.hpp"

// To prevent frivolous conversion warnings from gcc
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion-null"
#endif

template <typename ListNodeType, typename ValueType>
struct ListNodeTesting {
    static bool defaultConstructorShouldCreateSafeEmptyState();

    static bool shouldSetGetVal(const ValueType* testValues, int numTestValues);

    static bool valConstructorShouldSetVal(const ValueType* testValues, int numTestValues);
    static bool nextConstructorShouldSetNext();

    static bool copyConstructorShouldSetNextToNull();
    static bool copyConstructorShouldSetValToOtherVal(const ValueType* testValues, int numTestValues);

    static bool assignmentOperatorShouldSetNextToNull();
    static bool assignmentOperatorShouldSetValToOtherVal(const ValueType* testValues, int numTestValues);
};

template <typename ListType, typename ListNodeType, typename ValueType>
struct ListTesting {
    static bool defaultConstructorShouldCreateSafeEmptyState();

    static bool pushPopHeadSize(const ValueType* testValues, int numTestValues);

    static bool copyConstructor(const ValueType* testValues, int numTestValues);

    static bool assignmentOperator(const ValueType* testValues, int numTestValues);

    static bool shouldHaveDestructor();
};

template <typename ListNodeType, typename ValueType>
bool testListNode(const ValueType* testValues, int numTestValues)
{
    namespace T=Testing;
    typedef ListNodeTesting<ListNodeType, ValueType> Tester;

    T::ssClear();
    T::ss << "ListNode Tests, ListNode type: ["
        << T::getTypeName<ListNodeType>()
        << "], Value type: ["
        << T::getTypeName<ValueType>()
        << "]";
    std::string sectionName = T::ss.str();
    T::sectionBegin(sectionName);

    Tester::defaultConstructorShouldCreateSafeEmptyState();

    Tester::shouldSetGetVal(testValues, numTestValues);

    Tester::valConstructorShouldSetVal(testValues, numTestValues);
    Tester::nextConstructorShouldSetNext();

    Tester::copyConstructorShouldSetNextToNull();
    Tester::copyConstructorShouldSetValToOtherVal(testValues, numTestValues);

    Tester::assignmentOperatorShouldSetNextToNull();
    Tester::assignmentOperatorShouldSetValToOtherVal(testValues, numTestValues);

    T::sectionFinish(sectionName);

    return T::success;
}

template <typename ListType, typename ListNodeType, typename ValueType>
bool testList(const ValueType* testValues, int numTestValues)
{
    namespace T=Testing;
    typedef ListTesting<ListType, ListNodeType, ValueType> Tester;

    T::ssClear();
    T::ss << "List Tests, List type: ["
        << T::getTypeName<ListType>()
        << "], ListNode type: ["
        << T::getTypeName<ListNodeType>()
        << "], Value type: ["
        << T::getTypeName<ValueType>()
        << "]";
    std::string sectionName = T::ss.str();
    T::sectionBegin(sectionName);
    Tester::defaultConstructorShouldCreateSafeEmptyState();

    Tester::pushPopHeadSize(testValues, numTestValues);

    // If above tests failed, don't continue
    if (T::success)
    {
        Tester::copyConstructor(testValues, numTestValues);

        Tester::assignmentOperator(testValues, numTestValues);

        Tester::shouldHaveDestructor();
    }

    T::sectionFinish(sectionName);

    return true;
}

/*
********************************************************************************
ListNode Tests
*/

template <typename ListNodeType, typename ValueType>
bool ListNodeTesting<ListNodeType, ValueType>::defaultConstructorShouldCreateSafeEmptyState()
{
    ListNodeType node;
    SILENT_ASSERT_EQ(node.val(), ValueType(), "ListNode should initialize value to default constructed value");
    SILENT_ASSERT_EQ(node.next(), NULL, "ListNode should initialize next pointer to null");

    return true;
}

template <typename ListNodeType, typename ValueType>
bool ListNodeTesting<ListNodeType, ValueType>::shouldSetGetVal(const ValueType* testValues, int numTestValues)
{
    SILENT_ASSERT(numTestValues >= 2, "not enough test values");

    ListNodeType node;
    node.val(testValues[0]);
    SILENT_ASSERT_EQ(node.val(), testValues[0], "ListNode should be able to set and get a value [1st]");
    node.val(testValues[1]);
    SILENT_ASSERT_EQ(node.val(), testValues[1], "ListNode should be able to set and get a value [2nd]");

    return true;
}

template <typename ListNodeType, typename ValueType>
bool ListNodeTesting<ListNodeType, ValueType>::valConstructorShouldSetVal(const ValueType* testValues, int numTestValues)
{
    SILENT_ASSERT(numTestValues >= 1, "not enough test values");

    ListNodeType node(testValues[0]);
    SILENT_ASSERT_EQ(node.val(), testValues[0], "ListNode constructor should set value returnable through val()");

    return true;
}

template <typename ListNodeType, typename ValueType>
bool ListNodeTesting<ListNodeType, ValueType>::nextConstructorShouldSetNext()
{
    ListNodeType node2;
    ListNodeType node1(ValueType(), &node2);

    SILENT_ASSERT_EQ(node1.next(), &node2, "ListNode constructor should set next node returnable through next()");

    return true;
}

template <typename ListNodeType, typename ValueType>
bool ListNodeTesting<ListNodeType, ValueType>::copyConstructorShouldSetNextToNull()
{
    ListNodeType node2, node1(ValueType(), &node2);
    SILENT_ASSERT_EQ(node1.next(), &node2, "ListNode constructor should set next node returnable through next()");
    ListNodeType node3(node1);
    SILENT_ASSERT_EQ(node3.next(), NULL, "ListNode copy constructor should set next to NULL in copied node");

    return true;
}

template <typename ListNodeType, typename ValueType>
bool ListNodeTesting<ListNodeType, ValueType>::copyConstructorShouldSetValToOtherVal(const ValueType* testValues, int numTestValues)
{
    SILENT_ASSERT(numTestValues >= 1, "not enough test values");

    ListNodeType node1, node2(node1);
    SILENT_ASSERT_EQ(node1.val(), ValueType(), "ListNode should initialize value to default constructed value");
    SILENT_ASSERT_EQ(node2.val(), ValueType(), "ListNode copy constructor should set val equal to source node val when src is default constructed");
    ListNodeType node3(testValues[0]), node4(node3);
    SILENT_ASSERT_EQ(node3.val(), testValues[0], "ListNode constructor should set value returnable through val()");
    SILENT_ASSERT_EQ(node4.val(), testValues[0], "ListNode copy constructor should set val equal to source node val when src is non-default");

    return true;
}

template <typename ListNodeType, typename ValueType>
bool ListNodeTesting<ListNodeType, ValueType>::assignmentOperatorShouldSetNextToNull()
{
    ListNodeType node2, node1(ValueType(), &node2);
    SILENT_ASSERT_EQ(node1.next(), &node2, "ListNode constructor should set next node returnable through next()");
    ListNodeType node3;
    SILENT_ASSERT_EQ(node3.next(), NULL, "ListNode should initialize next pointer to null");
    node1 = node3;
    SILENT_ASSERT_EQ(node1.next(), NULL, "ListNode assignment operator should set next to NULL in copied node");

    return true;
}


template <typename ListNodeType, typename ValueType>
bool ListNodeTesting<ListNodeType, ValueType>::assignmentOperatorShouldSetValToOtherVal(const ValueType* testValues, int numTestValues)
{
    SILENT_ASSERT(numTestValues >= 1, "not enough test values");

    ListNodeType node1;
    SILENT_ASSERT_EQ(node1.val(), ValueType(), "ListNode should initialize value to default constructed value");
    ListNodeType node2, node3(testValues[0]);
    SILENT_ASSERT_EQ(node2.val(), ValueType(), "ListNode should initialize value to default constructed value");
    SILENT_ASSERT_EQ(node3.val(), testValues[0], "ListNode constructor should set value returnable through val()");
    node1 = node3;
    SILENT_ASSERT_EQ(node1.val(), testValues[0], "ListNode assignment operator should set val to source node val returnable through val() when src is non-default constructed");
    node1 = node2;
    SILENT_ASSERT_EQ(node1.val(), ValueType(), "ListNode assignment operator should set val to source node val returnable through val() when src is default constructed");

    return true;
}

/*
********************************************************************************
List Tests
*/

template <typename ListType, typename ListNodeType, typename ValueType>
bool ListTesting<ListType, ListNodeType, ValueType>
    ::defaultConstructorShouldCreateSafeEmptyState()
{
    ListType list;
    SILENT_ASSERT_EQ(list.head(), NULL, "List should intialize head to NULL");
    SILENT_ASSERT_EQ(list.size(), 0, "List should initialize size to 0");

    return true;
}

template <typename ListType, typename ListNodeType, typename ValueType>
bool ListTesting<ListType, ListNodeType, ValueType>
    ::pushPopHeadSize(const ValueType* testValues, int numTestValues)
{
    SILENT_ASSERT(numTestValues >= 3, "not enough test values");

    // push section
    ListType list;
    SILENT_ASSERT_EQ(list.size(), 0, "List should initialize size to 0");
    SILENT_ASSERT_EQ(list.head(), NULL, "List should initialize head to NULL");
    list.push(testValues[0]);
    SILENT_ASSERT_EQ(list.size(), 1, "After 1 push, List size should be 1");
    ListNodeType* head = list.head();
    SILENT_ASSERT_NE(head, NULL, "After 1 push, List head should not be NULL");
    SILENT_ASSERT_EQ(head->val(), testValues[0], "After 1 push, List head val() should be pushed val");
    SILENT_ASSERT_EQ(head->next(), NULL, "After 1 push, List head next should be NULL");
    list.pop();
    SILENT_ASSERT_EQ(list.size(), 0, "After [push, pop], List size should be 0");
    SILENT_ASSERT_EQ(list.head(), NULL, "After [push, pop], List head should be NULL");
    list.push(testValues[1]);
    list.push(testValues[2]);
    SILENT_ASSERT_EQ(list.size(), 2, "After [push, pop, push, push], List size should be 2");
    SILENT_ASSERT_NE(list.head(), NULL, "After [push, pop, push, push], List head should not be NULL");
    head = list.head();
    ListNodeType* temp = head->next();
    SILENT_ASSERT_NE(temp, NULL, "After [push, pop, push, push], List head->next() should not be NULL");
    SILENT_ASSERT_EQ(temp->next(), NULL, "After [push, pop, push, push], List head->next()->next() should be NULL");
    SILENT_ASSERT_EQ(head->val(), testValues[1], "After [push, pop, push, push], List head val() should be first pushed val");
    SILENT_ASSERT_EQ(temp->val(), testValues[2], "After [push, pop, push, push], List head->next()->val() should be second pushed val");
    list.pop();
    SILENT_ASSERT_EQ(list.size(), 1, "After [push, pop, push, push, pop], List size should be 1");
    SILENT_ASSERT_EQ(list.head(), head, "After [push, pop, push, push, pop], List head should not have changed since [push, pop, push]");
    SILENT_ASSERT_EQ(head->next(), NULL, "After [push, pop, push, push, pop], List head next should be NULL");
    SILENT_ASSERT_EQ(head->val(), testValues[1], "After [push, pop, push, push, pop], List head val() should be first pushed val");
    list.push(testValues[0]);
    list.push(testValues[2]);
    SILENT_ASSERT_EQ(list.size(), 3, "After [push, pop, push, push, pop, push, push], List size should be 3");
    SILENT_ASSERT_EQ(list.head(), head, "After [push, pop, push, push, pop, push, push], List head should not have changed since [push, pop, push]");
    temp = head->next();
    SILENT_ASSERT_NE(temp, NULL, "After [push, pop, push, push, pop, push, push], List head->next() should not be NULL");
    ListNodeType* temp2 = temp->next();
    SILENT_ASSERT_NE(temp2, NULL, "After [push, pop, push, push, pop, push, push], List head->next()->next() should not be NULL");
    SILENT_ASSERT_EQ(temp2->next(), NULL, "After [push, pop, push, push, pop, push, push], List head->next()->next()->next() should be NULL");
    SILENT_ASSERT_EQ(head->val(), testValues[1], "After [push, pop, push, push, pop, push, push], List head val() should be first pushed value");
    SILENT_ASSERT_EQ(temp->val(), testValues[0], "After [push, pop, push, push, pop, push, push], List head->next()->val() should be second pushed value");
    SILENT_ASSERT_EQ(temp2->val(), testValues[2], "After [push, pop, push, push, pop, push, push], List head->next()->next()->val() should be third pushed value");

    // pop section
    list.pop();
    SILENT_ASSERT_EQ(list.size(), 2, "After [push, pop, push, push, pop, push, push, pop], List size should be 2");
    SILENT_ASSERT_EQ(list.head(), head, "After [push, pop, push, push, pop, push, push, pop], List head should not have changed since [push, pop, push]");
    SILENT_ASSERT_EQ(temp, head->next(), "After [push, pop, push, push, pop, push, push, pop], List head->next() should not have changed since [push, pop, push, push, pop, push]");
    SILENT_ASSERT_EQ(temp->next(), NULL, "After [push, pop, push, push, pop, push, push, pop], List head->next()->next() should be NULL");
    SILENT_ASSERT_EQ(head->val(), testValues[1], "After [push, pop, push, push, pop, push, push, pop], List head val() should be first pushed value");
    SILENT_ASSERT_EQ(temp->val(), testValues[0], "After [push, pop, push, push, pop, push, push, pop], List head->next->val() should be second pushed value");

    list.pop();
    SILENT_ASSERT_EQ(list.size(), 1, "After [push, pop, push, push, pop, push, push, pop, pop], List size should be 1");
    SILENT_ASSERT_EQ(list.head(), head, "After [push, pop, push, push, pop, push, push, pop, pop], List head should not have changed since [push, pop, push]");
    SILENT_ASSERT_EQ(head->next(), NULL, "After [push, pop, push, push, pop, push, push, pop, pop], List head->next() should be NULL");
    SILENT_ASSERT_EQ(head->val(), testValues[1], "After [push, pop, push, push, pop, push, push, pop, pop], List head val() should be first pushed value");

    list.pop();
    SILENT_ASSERT_EQ(list.size(), 0, "After [push, pop, push, push, pop, push, push, pop, pop, pop], List size should be 0");
    SILENT_ASSERT_EQ(list.head(), NULL, "After [push, pop, push, push, pop, push, push, pop, pop, pop], List head should be NULL");

    return true;
}

template <typename ListType, typename ListNodeType, typename ValueType>
bool _copyAssignmentCommon(ListType& list1, ListType& list2, const ValueType* testValues, const char* msgInit)
{
    // Ensure all sizes and values correct and unattached
    SILENT_ASSERT_EQ(list1.size(), 2, msgInit << ", list 1 should be size 2");
    SILENT_ASSERT_EQ(list2.size(), 2, msgInit << ", list 2 should be size 2");

    SILENT_ASSERT_NE(list1.head(), list2.head(), msgInit << ", list 1 head and list 2 head should not be the same");
    SILENT_ASSERT_EQ(list1.head()->val(), testValues[0], msgInit << ", list 1 head should have val() of first test value");
    SILENT_ASSERT_EQ(list2.head()->val(), testValues[0], msgInit << ", list 2 head should have val() of first test value");

    SILENT_ASSERT_NE(list1.head()->next(), list2.head()->next(), msgInit << ", list 1 head->next() and list 2 head->next() should not be the same");
    SILENT_ASSERT_EQ(list1.head()->next()->val(), testValues[1], msgInit << ", list 1 head->next()->val() should be second test value");
    SILENT_ASSERT_EQ(list2.head()->next()->val(), testValues[1], msgInit << ", list 2 head->next()->val() should be second test value");

    SILENT_ASSERT_EQ(list1.head()->next()->next(), NULL, msgInit << ", list 1 head->next()->next() should be NULL");
    SILENT_ASSERT_EQ(list2.head()->next()->next(), NULL, msgInit << ", list 1 head->next()->next() should be NULL");

    // Set value in 1, ensure not reflected in 2
    list1.head()->next()->val(testValues[2]);
    SILENT_ASSERT_EQ(list1.head()->next()->val(), testValues[2], "After list 1 head->next() set val, list 1 head->next()->val() should be third test value");
    SILENT_ASSERT_EQ(list2.head()->next()->val(), testValues[1], "After list 1 head->next() set val, list 2 head->next()->val() should still be second test value");
    ListNodeType* temp = list1.head()->next();

    // Drop in 2
    list2.pop();
    SILENT_ASSERT_EQ(list2.size(), 1, "After list 2 pop, list 2 size should be 1");
    SILENT_ASSERT_EQ(list1.size(), 2, "After list 2 pop, list 1 size should still be 2");
    SILENT_ASSERT_EQ(list2.head()->next(), NULL, "After list 2 pop, list 2 head->next() should be NULL");
    SILENT_ASSERT_EQ(list1.head()->next(), temp, "After list 2 pop, list 1 head->next() should not have changed");
    SILENT_ASSERT_NE(temp, NULL, "After list 2 pop, list 1 head->next() should not be NULL");

    return true;
}

template <typename ListType, typename ListNodeType, typename ValueType>
bool ListTesting<ListType, ListNodeType, ValueType>
    ::copyConstructor(const ValueType* testValues, int numTestValues)
{
    Testing::h1("Entering copy constructor tests");
#if !HIDE_TIPS
    Testing::h2("If test goes on forever, likely your copy constructor's loop is not ending.");
    Testing::h2("Ensure that your end condition is correct!");
#endif
    SILENT_ASSERT(numTestValues >= 3, "not enough test values");

    ListType list1;
    list1.push(testValues[0]);
    list1.push(testValues[1]);

    ListType list2(list1);

    bool val = _copyAssignmentCommon<ListType, ListNodeType, ValueType>(
        list1, list2, testValues, "After copy constructor");
    Testing::h1("Finished copy constructor tests");
    return val;
}

template <typename ListType, typename ListNodeType, typename ValueType>
bool ListTesting<ListType, ListNodeType, ValueType>
    ::assignmentOperator(const ValueType* testValues, int numTestValues)
{
    Testing::h1("Entering assignment operator tests");
#if !HIDE_TIPS
    Testing::h2("If test goes on forever, likely your assignment operator's loop is not ending.");
    Testing::h2("Ensure that your end condition is correct!");
    Testing::h2("Also ensure that your assignment operator is well-behaved in cases");
    Testing::h2("where the object is assigned to itself (ie List x; x = x;).");
    Testing::newline();
    Testing::h2("TIP: In the case mentioned above, the assignment operator shouldn't change the list in any way.");
    Testing::h2("Use memory address comparison to find out if the object is being assigned to itself.");
#endif
    SILENT_ASSERT(numTestValues >= 3, "not enough test values");

    ListType list1;
    list1.push(testValues[0]);
    list1.push(testValues[1]);

    ListType list2;
    SILENT_ASSERT_EQ(list2.size(), 0, "List 2 size should initialize to 0");
    SILENT_ASSERT_EQ(list2.head(), NULL, "List 2 head should initialize to NULL");
    list2.push(testValues[2]);
    list2.push(testValues[1]);
    list2.push(testValues[0]);
    SILENT_ASSERT_EQ(list2.size(), 3, "List 2 size should be 3 after 3 pushes");
    SILENT_ASSERT_NE(list2.head(), NULL, "List 2 head should not be NULL after 3 pushes");
    SILENT_ASSERT_EQ(list2.head()->val(), testValues[2], "List 2 head val() should be third test value");
    SILENT_ASSERT_EQ(list2.head()->next()->val(), testValues[1], "List 2 head val() should be second test value");
    SILENT_ASSERT_EQ(list2.head()->next()->next()->val(), testValues[0], "List 2 head val() should be first test value");

    Testing::newline();
    Testing::h2("Next tests should clear the 3 values currently assigned to list 2");
    Testing::h2("before assigning the values in list 1");
    list2 = list1;

    bool val = _copyAssignmentCommon<ListType, ListNodeType, ValueType>(
        list1, list2, testValues, "After assignment operator");

    // If all is well above, ensure that list successfully survives self-assignment test
    if (!val) return false;

    // Expecting list 1 to have sequence values testValues[0], testValues[2]
    ListNodeType* head = list1.head();
    ListNodeType* temp = head->next();
    list1 = list1;

    SILENT_ASSERT_EQ(list1.size(), 2, "After self assignment, list 1 should have size 2");
    SILENT_ASSERT_EQ(list1.head(), head, "After self assignment, head should not have changed");
    SILENT_ASSERT_EQ(head->next(), temp, "After self assignment, head->next() should not have changed");
    SILENT_ASSERT_EQ(temp->next(), NULL, "After self assignment, head->next()->next() should be NULL");
    SILENT_ASSERT_EQ(head->val(), testValues[0], "After self assignment, list head val() should be first test value");
    SILENT_ASSERT_EQ(temp->val(), testValues[2], "After self assignment, list head->next()->val() should be third test value");

    Testing::h1("Finished assignment operator tests");
    return true;
}

template <typename ListType, typename ListNodeType, typename ValueType>
bool ListTesting<ListType, ListNodeType, ValueType>
    ::shouldHaveDestructor()
{
    Testing::newline();
    Testing::h1("[!IMPORTANT!] Make sure that your list has a well defined destructor that deallocates all memory allocated!");
    Testing::msg("TIP: the clear function destroys all nodes and leaves the list in a safe empty state!");
    Testing::newline();
    return true;
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#endif
