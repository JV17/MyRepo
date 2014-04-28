#ifndef __FS_FOUT_H__
#define __FS_FOUT_H__

class Output{
public:
  Output& operator<<(int a);
  Output& operator<<(const char*);
};
extern Output fout;


#endif
