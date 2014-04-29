// Jorge E. Valbuena S.
// OOP344A - Assignment #2
#pragma once
#ifndef __CFIELD_H__
#define __CFIELD_H__

#include "cframe.h"

namespace cio { // continuation of namespace cio

	class CField : public CFrame {
	protected:
		void* _data;
	public:
		virtual bool editable() const = 0; // returns the field's editable status
		virtual void set(const void*) = 0; 		// stores the field's data
		virtual int edit() = 0;
		CField(int row = 0, int col = 0, int width = 0, int height = 0, void* data = NULL, 
			bool visible = false, const char* border = C_BORDER_CHARS);
		~CField();
		void* data() const;
		void data(void*);
	};

} // end of namespace cio
#endif