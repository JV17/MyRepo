// Console UI Core Classes
// cuigh.h
//
// Fardad Soleimanloo, Chris Szalwinski
// OCT 06 2011
// Version 1.0
#pragma once
#ifndef ___CFG_H__
#define ___CFG_H__

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <cstdlib>
#define C_MAX_NO_FIELDS 100
#define C_BORDER_CHARS  "/-\\|/-\\|"
#define C_FULL_FRAME -1
#define C_NO_FRAME 0
#define C_NOT_EDITABLE 0
#define C_BUTTON_HIT 1
//#define NULL (void*)0
#define C_MAX_LINE_CHARS  (1024u)

namespace cio{ // continuation of namespace cio

	enum CDirection { C_STATIONARY, C_MOVED_LEFT, C_MOVED_RIGHT, C_MOVED_UP, C_MOVED_DOWN };
	enum MessageStatus{ ClearMessage, SetMessage };

} // end of namespace cio

#ifdef NO_HELPFUNC
# undef NO_HELPFUNC
#endif
#define NO_HELPFUNC ((void(*)(MessageStatus, CDialog&))(0))
#ifdef NO_VALDFUNC
# undef NO_VALDFUNC
#endif
#define NO_VALDFUNC ((bool(*)(const char*, CDialog&))(0))

#define C_MAX_LINE_CHARS  (1024u)
#define C_INITIAL_NUM_OF_LINES (100u)

#endif