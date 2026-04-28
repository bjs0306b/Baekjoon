#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b,c;
};

bool visited[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    if(a == b && b == c){
        cout << 1; return 0;
    }
    if(a > b) swap(a,b);
    if(a > c) swap(a,c);
    if(b > c) swap(b,c);
    node n = {a,b,c};
    queue<node> q;
    q.push(n);
    visited[a][b] = true;

    while(!q.empty()){
        node temp = q.front(); q.pop();
        int aa = temp.a, bb = temp.b, cc = temp.c;
        if(aa > bb) swap(aa,bb);
        if(aa > cc) swap(aa,cc);
        if(bb > cc) swap(bb,cc);

        int aaa = aa*2, bbb = bb-aa, ccc = cc;
        if(aaa > bbb) swap(aaa,bbb);
        if(aaa > ccc) swap(aaa,ccc);
        if(bbb > ccc) swap(bbb,ccc);
        node temp1 = {aaa,bbb,ccc};
        if(aaa==bbb && bbb==ccc){
            cout << 1; return 0;
        }
        if(!visited[aaa][bbb]){q.push(temp1); visited[aaa][bbb] = true;}

        aaa = aa*2, bbb= bb, ccc = cc-aa;
        if(aaa > bbb) swap(aaa,bbb);
        if(aaa > ccc) swap(aaa,ccc);
        if(bbb > ccc) swap(bbb,ccc);
        node temp2 = {aaa,bbb,ccc};
        if(aaa==bbb && bbb==ccc){
            cout << 1; return 0;
        }
        if(!visited[aaa][bbb]) {q.push(temp2); visited[aaa][bbb] = true;}

        aaa = aa, bbb = bb*2, ccc = cc-bb;
        if(aaa > bbb) swap(aaa,bbb);
        if(aaa > ccc) swap(aaa,ccc);
        if(bbb > ccc) swap(bbb,ccc);
        node temp3 = {aaa,bbb,ccc};
        if(aaa==bbb && bbb==ccc){
            cout << 1; return 0;
        }
        if(!visited[aaa][bbb]) {q.push(temp3); visited[aaa][bbb] = true;}
    }
    cout << 0;

    return 0;
}