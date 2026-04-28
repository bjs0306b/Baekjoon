#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class student{
public:
    int name, three, two, one, sum;
    student():three(0),two(0),one(0),sum(0){} 

    bool operator==(student other){
        return (three == other.three && two == other.two && one == other.one);
    }

    bool operator<(student other){
        if(sum == other.sum){
            if(three == other.three){
                if(two == other.two){
                    return one < other.one;
                }
                return two < other.two;
            }
            return three < other.three;
        }
        return sum < other.sum;
    }

    void cul(){
        sum = three*3+two*2+one;
    }


};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    student s[3]; for(int i=0;i<3;i++) s[i].name = i+1;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int num; cin >> num;
            if(num == 3){
                s[j].three++;
            }
            else if(num == 2){
                s[j].two++;
            }
            if(num == 1){
                s[j].one++;
            }
        }
    }
    for(int i=0;i<3;i++) s[i].cul();
    sort(s, s+3);
    if(s[1] == s[2]) cout << 0 << " " << s[1].sum;
    else cout << s[2].name << " " << s[2].sum;  
    return 0;
}