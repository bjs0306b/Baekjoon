#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class student{
public:
    int weight,height,rank;
    student(){}
    student(int w, int h):weight(w),height(h),rank(1){}
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, he, we;
    cin >> n;
    vector<student> vec;
    for(int i=0;i<n;i++){
        cin >> we >> he;
        vec.push_back(student(we,he));
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(vec[i].height < vec[j].height && vec[i].weight < vec[j].weight)
                vec[i].rank++;
            else if(vec[i].height > vec[j].height && vec[i].weight > vec[j].weight)
                vec[j].rank++;
            else
                continue;
        }
    }
    for(int i=0;i<n;i++) cout << vec[i].rank << " ";
    
    return 0;
}