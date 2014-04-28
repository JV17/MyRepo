//const int sun = 1;
//const int mon = 2;
//const int tue = 3;
//const int wed = 4;
//const int thu = 5;
//const int fri = 6;
//const int sat = 7;
//typedef int weekday;
enum weekday{sun = 1, mon , tue, wed, thu, fri, sat};
int main(){
  weekday w;
  for(w = sun; w <= sat; w++){
    // whatever
  }
  return 0;
}