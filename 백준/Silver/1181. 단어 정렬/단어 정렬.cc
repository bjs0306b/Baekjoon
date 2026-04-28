#include <iostream>
#include <string>
#include <list>
#include <set>
using namespace std;

bool compareSize(const string &str, const string &str2){
    return str.size() < str2.size();
}
int main(){
    int size;
    cin >> size;
    string str;
    list<string> li;
    for(int i=0; i<size; i++) {cin >> str; li.push_back(str);}
    set<string> myset(li.begin(), li.end());
    list<string> mylist(myset.begin(), myset.end());
    mylist.sort(compareSize);

    for(string element: mylist) cout << element << "\n";   
    
}