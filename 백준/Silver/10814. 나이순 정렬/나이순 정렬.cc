#include <iostream>
#include <algorithm>
using namespace std;

class student{
public:
    int age;
    string name;
    int order;
};

bool compare(student a, student b){
    if(a.age == b.age) return a.order < b.order;
    else return a.age < b.age;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    student std[n];
    int ord = 1;
    for(int i=0;i<n;i++){
        cin >> std[i].age >> std[i].name;
        std[i].order = ord++;
    }
    sort(std, std+n, compare);

    for(int i=0;i<n;i++){
        cout << std[i].age << " " << std[i].name << "\n";
    }


    return 0;
}