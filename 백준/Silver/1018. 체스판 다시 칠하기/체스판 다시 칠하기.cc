#include <iostream>
#include <string>
using namespace std;

int main(){
    int m,n, cnt1, cnt2, cnt, i, j, k, l, min;
    cin >> m >> n;
    string *b = new string[m];
    for(i=0;i<m;i++) cin >> b[i];

    string *a = new string[8];
    for(i=0;i<8;i++)  a[i] = "ABCDEFGH";
   
    min = m*n;
    for(l = 0; l < m-7; l++){
        for(k = 0; k < n-7; k++){
            for(i=0; i<8; i++){
                for(j=0; j<8; j++){
                    a[i][j] = b[l+i][k+j];
                }
            }
            cnt1 = 0;       
            cnt2 = 0;
            for(i=0;i<8;i++){
                for(j=(i%2==0)?0:1;j<8;j+=2){
                    if('B' != a[i][j]) cnt1++;
                }   
                for(j=(i%2==0)?1:0;j<8;j+=2){
                    if('B' == a[i][j]) cnt1++;
                }
            }   
            for(i=0;i<8;i++){
                for(j=(i%2==0)?0:1;j<8;j+=2){
                    if('W' != a[i][j]) cnt2++;
                }
                for(j=(i%2==0)?1:0;j<8;j+=2){
                    if('W' == a[i][j]) cnt2++;
                }
            }
            cnt = (cnt1<cnt2)?cnt1:cnt2;
            min = (cnt < min)?cnt:min;
        }
    }
    cout << min;
}