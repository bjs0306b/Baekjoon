#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> answer(5, 0);

    vector<int> S(367, 0), T(367, 0);
    for(int i=0;i<n;i++){
        char c; cin >> c;
        int s, e; cin >> s >> e;
        answer[4] = max(answer[4], e-s+1);
        if(c == 'S') for(int i=s;i<=e;i++) S[i]++;
        else if(c == 'T')  for(int i=s;i<=e;i++) T[i]++;
    }

    for(int i=1;i<=366;i++){
        if(S[i] || T[i]) answer[0]++;
        answer[1] = max(answer[1], S[i]+T[i]);
        
        if(!(S[i] == 0 && T[i] == 0 || S[i] != T[i])){
            answer[2]++;
            answer[3] = max(answer[3], S[i]+T[i]);
        }

    }
    for(int i=0;i<5;i++) cout << answer[i] << "\n";

    return 0;
}