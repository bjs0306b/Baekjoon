#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int A[500001],tmp[500001], cnt;

void merge(int p, int q, int r);    
void merge_sort(int p, int r) { 
    if (p < r) {
        int q = (p + r) / 2;       
        merge_sort(p, q);    
        merge_sort(q + 1, r);  
        merge(p, q, r);        
    }
}

void merge(int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]){ tmp[t++] = A[i++];}
        else tmp[t++] = A[j++]; 
    }
    while (i <= q) 
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];
    i = p; t = 1;
    while (i <= r){
        A[i++] = tmp[t++]; 
        cnt--; if(cnt==0) cout << tmp[t-1];
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n >> cnt;
    for(int i=0;i<n;i++) cin >> A[i];
    merge_sort(0,n-1);
    if(cnt>0) cout << -1;
    return 0;
}