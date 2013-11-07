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

#include<iostream>

class Alloc{
    int size;
    static int Counter;
    
public:
    Alloc();
    Alloc(int size, int Counter, const Alloc*, const Alloc&);
    ~Alloc();
};


#endif
