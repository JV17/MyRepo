/*
********************************************************************************
Tester Platform

Written by Hasan Kamal-Al-Deen
Modified March 21, 2014
*/
#ifndef __TESTER_HPP__
#define __TESTER_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#ifdef __GNUC__
#include <cxxabi.h>
#include <cstdlib>
#endif

namespace Testing {
    static const char* indent = "";
    static std::stringstream ss;
    static bool success = true;
    static bool overallSuccess = true;

    template <typename T>
    std::string getTypeName()
    {
#ifdef __GNUC__
        std::string rv;
        // Demangler will allocate string using malloc
        char* demangled = __cxxabiv1::__cxa_demangle(
            typeid(T).name(), NULL, NULL, NULL);
        rv = demangled;
        free(demangled);
        return rv;
#else
        return typeid(T).name();
#endif
    }

    void ssClear(){
        ss.clear();
        ss.str(std::string());
    }

    void msg(const std::string& s){
        std::cout << indent << s << std::endl;
    }

    void write(){
        msg(ss.str());
        ssClear();
    }

    void err(){
        std::string m = ss.str();
        ssClear();
        ss << "ERROR! " << m;
        write();
        success = false;
        overallSuccess = false;
    }

    void h1(const std::string& s){
        std::cout << s << ':' << std::endl;
        indent = "  ";
    }

    void h2(const std::string& s){
        std::cout << "  [" << s << "]:" << std::endl;
        indent = "    ";
    }

    void h3(const std::string& s){
        std::cout << "    [" << s << "]:" << std::endl;
        indent = "      ";
    }

    void h4(const std::string& s){
        std::cout << "      [" << s << "]:" << std::endl;
        indent = "        ";
    }

    void h1w(){
        h1(ss.str());
        ss.clear();
        ss.str(std::string());
    }

    void h2w(){
        h2(ss.str());
        ss.clear();
        ss.str(std::string());
    }

    void h3w(){
        h3(ss.str());
        ss.clear();
        ss.str(std::string());
    }

    void h4w(){
        h4(ss.str());
        ss.clear();
        ss.str(std::string());
    }

    void sectionBegin(std::string name){
        success = true;
        ssClear();
        h1("*    -    *    -    *    -    *    -    *    -    *");
        ss << name << " Tests";
        h1w();
    }

    void newline(){
        std::cout << std::endl;
    }

    void sectionFinish(std::string name){
        ssClear();
        ss << "Finished " << name << " tests ";
        if (success) {
            ss << "with no errors! Success!";
        }
        else {
            ss << "with errors... fix them and try again";
            overallSuccess = false;
        }
        h1w();
    }

    void finish(){
        if (overallSuccess) {
            h1("Finished all enabled tests with no errors! Success!");
        }
        else {
            h1("Finished some enabled tests with errors... fix them and try again");
        }

        std::cout << "Done. Type anything to continue..." << std::endl;
        std::string s;
        std::cin >> s;
    }
}

#define ASSERT(test, m) \
    if (!(test)){\
        Testing::ss << "Test: [" << m << "], FAILED!"; \
        Testing::err(); \
        return false; \
    } \
    else {\
        Testing::ss << "Test: [" << m << "], PASSED!"; \
        Testing::write(); \
    }

#if !defined(VERBOSE_TESTS) || !VERBOSE_TESTS
#define SILENT_ASSERT(test, m) \
    if (!(test)){ \
        Testing::ss << "Test: [" << m << "], FAILED!"; \
        Testing::err(); \
        return false; \
    }
#else
#define SILENT_ASSERT(test, m) ASSERT(test, m)
#endif

#define _EQ(tester, p1, expected, m) tester((p1) == (expected), m << ", got:" << p1 << ", expected:" << expected)
#define _NE(tester, p1, expected, m) tester((p1) != (expected), m << ", got:" << p1 << ", expected NOT:" << expected)

#define ASSERT_EQ(p1, expected, m) _EQ(ASSERT, p1, expected, m)
#define ASSERT_NE(p1, expected, m) _NE(ASSERT, p1, expected, m)
#define SILENT_ASSERT_EQ(p1, expected, m) _EQ(SILENT_ASSERT, p1, expected, m)
#define SILENT_ASSERT_NE(p1, expected, m) _NE(SILENT_ASSERT, p1, expected, m)

#define TESTER_COMMA() ,
#endif
