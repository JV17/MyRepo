/*const int sun = 1;
const int mon = 2;
const int tue = 3;
const int wed = 4;
const int thu = 5;
const int fri = 6;
const int sat = 7;

typedef int weekday; */

enum weekday{sun = 1 , mon , tue, wed, thu, fri, sat};
enum boolean{False, True};
/* C version because structs and enum and etc don't create types automatically
typedef enum {False, Ture} boolean; */

void foo(){
  weekday day;
  for(day = sun ;day <= sat; day++){
    // whatever
  }

}