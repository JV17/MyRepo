// iFrame Header
// iframe.h
//
// Fardad Soleimanloo, Chris Szalwinski
// August 27 2011
// Version 1.0
//
#pragma once
#ifndef _FS_IFRAME_H_
#define _FS_IFRAME_H_

#include "cfg.h"  // for C_FULL_FRAME, CDirection, and C_STATIONARY

namespace cio { // continuation of namespace cio

	class iFrame {
	public:
		virtual void draw(int fn = C_FULL_FRAME) = 0;
		virtual void move(CDirection dir) = 0;
		virtual void hide(CDirection dir = C_STATIONARY) = 0;
	};
	void move(iFrame &cf);

}  // end of namespace cio 
#endif