#pragma once
#ifndef __FS_CLASSALLOC_H__
#define __FS_CLASSALLOC_H__

#include<iostream>

class Alloc{
    int *d;
    static int Counter;

public:
    Alloc();
    Alloc(int*, static int, const Alloc&);
    ~Alloc();
};

#endif