#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    float sum1=0, sum2=0;
    for(int i=0;i<20;i++){
        string s; cin >> s;
        float f; cin >>f;
        string s2; cin >> s2; if(s2 == "P") continue;
        sum1 += f;
        switch (s2[0]) {
            case 'A':{
                float f2 = 4.0;
                if(s2[1] == '+') f2 += 0.5;
                sum2 += f2*f;
                break;  
            }
            case 'C':{
                float f2 = 2.0;
                if(s2[1] == '+') f2 += 0.5;
                sum2 += f2*f;
                break;
            }
            case 'B':{
                float f2 = 3.0;
                if(s2[1] == '+') f2 += 0.5;
                sum2 += f2*f;
                break;
            }
            case 'D':{
                float f2 = 1.0;
                if(s2[1] == '+') f2 += 0.5;
                sum2 += f2*f;
                break;
            }
        }
    }   
    cout << sum2/sum1; 
    
    return 0;
}