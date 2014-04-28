
#include "cfg.h"
#include "cfield.h"
#include "cdialog.h"
#include "console.h"
#include "keys.h"

#define C_INITIAL_NO_FIELDS 50

namespace cio{
	CDialog::CDialog(CFrame *Container,
		int Row, int Col,
		int Width, int Height,
		bool Bordered, const char* Border) :
		CFrame(Row, Col, Width, Height, Bordered,
		Border, Container), _fnum(0), _curidx(0) {
		int i;
		_editable = false;
		_fldSize = C_INITIAL_NO_FIELDS;
		_fld = new CField*[C_INITIAL_NO_FIELDS];
		_dyn = new bool[C_INITIAL_NO_FIELDS];
		for (i = 0; i<C_INITIAL_NO_FIELDS; i++){
			_fld[i] = (CField*)0;
			_dyn[i] = false;
		}
	}
	CDialog::~CDialog(){
		int i;
		for (i = 0; i<_fnum; i++){
			if (_fld[i] && _dyn[i]){
				delete _fld[i];
			}
		}
	}
	void CDialog::draw(int fn){
		if (fn == C_FULL_FRAME){
			CFrame::draw();
			fn = 0;
		}
		if (fn == 0){
			for (int i = 0; i<_fnum; i++){
				_fld[i]->draw();
			}
		}
		else{
			_fld[(fn - 1) % _fnum]->draw();
		}
	}

#define GONEXT(x) (x=((x<(_fnum-1))?(x+1):0))
#define GOPREV(x) (x=((x>0)?(x-1):(_fnum-1)))
	int CDialog::edit(int fn){
		int key = 0;
		bool done = false;
		bool down = true;
		if (!_editable) {
			done = true;
			draw(fn);
			console >> key;
		}
		else if (fn <= 0){
			draw(fn);
		}
		if (fn > 0){
			_curidx = (fn - 1) % _fnum;
		}
		while (!done){
			key = _fld[_curidx]->edit();
			switch (key){
			case 0:
				if (down){
					GONEXT(_curidx);
				}
				else{
					GOPREV(_curidx);
				}
				break;
			case ENTER:
			case TAB:
			case DOWN:
				down = true;
				GONEXT(_curidx);
				break;
			case UP:
				down = false;
				GOPREV(_curidx);
				break;
			default:
				done = true;
				break;
			}
		}
		return key;
	}

	int CDialog::add(CField* field, bool dynamic){
		int idx = -1;
		if (_fnum == _fldSize){
			unsigned int i;
			_fldSize += 20;
			CField** temp = new CField*[_fldSize];
			bool* dtemp = new bool[_fldSize];
			for (i = 0; i< _fldSize - 20; i++){
				temp[i] = _fld[i];
				dtemp[i] = _dyn[i];
			}
			for (; i<_fldSize; i++){
				temp[i] = (CField*)0;
				dtemp[i] = false;
			}
			delete[] _fld;
			delete[] _dyn;
			_fld = temp;
			_dyn = dtemp;
		}
		field->frame(this);
		_fld[_fnum] = field;
		_dyn[_fnum] = dynamic;
		_editable = _editable || field->editable();
		idx = _fnum;
		_fnum++;
		return idx;
	}
	int CDialog::add(CField& field, bool dynamic){
		return add(&field, dynamic);
	}
	CDialog& CDialog::operator<<(CField* field){
		add(field);
		return *this;
	}
	CDialog& CDialog::operator<<(CField& field){
		add(field);
		return *this;
	}

	bool CDialog::editable() const{
		return _editable;
	}
	int CDialog::numFields()const{
		return _fnum;
	}
	int CDialog::curIndex()const{
		return _curidx;
	}

	CField& CDialog::operator[](unsigned int index){
		return *_fld[index % _fnum];
	}

	CField& CDialog::curField() const{
		return *_fld[_curidx];
	}

}