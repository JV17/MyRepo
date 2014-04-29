#pragma once
#ifndef __FS_CDialog_H__
#define __FS_CDialog_H__
#include "cfg.h"
#include "cframe.h"

namespace cio{ // continuation of namespace cio

	class CField;
	class CDialog : public CFrame{
	private:
		int _fnum;
		int _curidx;
		CField** _fld;
		bool* _dyn;
		bool _editable;
		unsigned int _fldSize;
	public:
		CDialog(CFrame *Container = (CFrame*)0,
			int Row = -1, int Col = -1,
			int Width = -1, int Height = -1,
			bool Borderd = false,
			const char* Border = C_BORDER_CHARS);
		virtual ~CDialog();
		void draw(int fn = C_FULL_FRAME);
		int edit(int fn = C_FULL_FRAME);

		int add(CField* field, bool dynamic = true);
		int add(CField& field, bool dynamic = false);
		CDialog& operator<<(CField* field);
		CDialog& operator<<(CField& field);

		bool editable() const;
		int numFields()const;
		int curIndex()const;

		CField& operator[](unsigned int index);
		CField& curField() const;
	};

} // end of namespace cio
#endif