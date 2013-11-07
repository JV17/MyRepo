//
//  classAlloc.cpp
//  macAlloc
//
//  Created by Jorge Valbuena on 11/7/2013.
//  Copyright (c) 2013 Jorge Valbuena. All rights reserved.
//

#include "classAlloc.h"

// Counting the numbers of objects and keeping track of each object created and destroyed...
/*template <typename T>
 class Countable{
 Countable() { _count++; }
 Countable(const Countable&) { _count++; }
 ~Countable() { _count--; }
 static int get_count() { return _count; }
 private:
 static int _count;
 };
 //d=(int *) malloc(size*sizeof(int));;
 //d=new int[size];
 Alloc *my_alloc;
 //my_alloc = new Alloc[size];                //note that the type is a Myclass pointer
 //for(int i=0; i<size; i++){
 //    my_alloc[i] = new Alloc[size];
 //}
 //for(int i=0; i < size; i++){
 //    d[i]=c.d[i];
 //}

 */

    Alloc::Alloc(){ Counter++; }

    Alloc::Alloc(int size, int Counter, const Alloc*, const Alloc& c){
    
        
        
    }

    Alloc::~Alloc(){ Counter--; }
