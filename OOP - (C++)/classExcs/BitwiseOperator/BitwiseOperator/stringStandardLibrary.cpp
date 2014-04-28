#include<vector>

int main(){
    std::vector<int> a;
    a.push_back(0); 
    a.push_back(1);
    //a.pop_back();
    a.front() = 10; //assign the value to the first element of the array
    a.back() = 8; // same thing adding value to the last element
    //a.pop_back();
    a.front(); // it will CRASH the program...
    
    //iterate is going to the elements one by one..
    //iterator points the first element
    auto i = a.begin(); // specialize pointer..
    //without auot
    std::vector<int>::iterator i = a.begin();

    auto t = *i; // * dereference..

    //iterator points to 1 elements after the end of the list (to unallocated memory)
    auto e = a.end();

    for(; i != e; i++)
         *i += 1; // increasing all the elements by 1

    return 0;
}