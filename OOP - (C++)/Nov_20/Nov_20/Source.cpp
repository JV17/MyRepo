#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){

    vector<int> intv;
    list<int> intl;
    unordered_map<int,int> intm;

    //begin() first element of the list
    //end() the element after the last element of the list
    auto f = find(intv.begin(), intv.end(), 22);
    auto fl = find(intl.begin(), intl.end(), 10);

    if(f != intv.end()) // guarantee that we found something
        intv.erase(f);

    sort(intl.begin(), intl.end()); // gonna sort the list for us

    for(auto i = intv.begin(), end = intv.end(); i < end; i++){

    }

    for(auto i = intl.begin(), end = intl.end(); i != end; i++){ //doesnt work with <

    }

    return 0;
}