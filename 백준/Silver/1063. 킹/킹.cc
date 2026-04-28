#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    char ayc, byc;
    int ax, bx, n;
    cin >> ayc >> ax >> byc >> bx >> n;

    int ay = ayc - 'A' + 1;
    int by = byc - 'A' + 1;

    for(int i=0;i<n;i++){
        string s; cin >> s;
        string ss[8] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
        int pos = find(ss, ss+8, s) - ss;
        int x[8] = {0, 0, -1, 1, 1, 1, -1, -1};
        int y[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        if(ax+x[pos] <= 8 && ax+x[pos] >= 1 && ay+y[pos] <= 8 && ay+y[pos] >= 1){
            if(ax + x[pos] == bx && ay + y[pos] == by){
                if(bx + x[pos] <= 8 && bx + x[pos] >= 1 && by + y[pos] <= 8 && by + y[pos] >= 1){
                    ax += x[pos];
                    ay += y[pos];
                    bx += x[pos];
                    by += y[pos];
                }
            }
            else{
                ax += x[pos];
                ay += y[pos];
            }
        }
    }
    char ans_ay = ay + 'A' - 1;
    char ans_by = by + 'A' - 1;

    cout << ans_ay << ax << "\n" << ans_by  << bx;


    
    return 0;
}