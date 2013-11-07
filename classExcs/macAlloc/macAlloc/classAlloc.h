//
//  classAlloc.h
//  macAlloc
//
//  Created by Jorge Valbuena on 11/7/2013.
//  Copyright (c) 2013 Jorge Valbuena. All rights reserved.
//
#pragma once
#ifndef macAlloc_classAlloc_h
#define macAlloc_classAlloc_h

#include <iostream>

using namespace std;

class MemCheck
{
    static unsigned int cnt;
    class Alert
    {
        ~Alert()
        {
            if(cnt != 0u)
            {
                int a;
                std::cout << "Warning: " << cnt << " objects were not deallocated" << std::endl;
                std::cin >> a;
            }
        }
    };
    static Alert alert;
protected:
    MemCheck() {cnt++;}
    virtual ~MemCheck() {cnt--;}
};


#endif
