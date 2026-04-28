#include <bits/stdc++.h>
using namespace std;

bool visited[4][13];
int cnt[4];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;

    for(int i=0;i<s.size();i+=3){

        int num = stoi(s.substr(i+1, 2));

        if(s[i] == 'P'){
            if(visited[0][num]){
                cout << "GRESKA"; return 0;
            }
            else{
                visited[0][num] = true;
                cnt[0]++;
            }
        }
        else if(s[i] == 'K'){
            if(visited[1][num]){
                cout << "GRESKA"; return 0;
            }
            else{
                visited[1][num] = true;
                cnt[1]++;
            }
        }
        else if(s[i] == 'H'){
            if(visited[2][num]){
                cout << "GRESKA"; return 0;
            }
            else{
                visited[2][num] = true;
                cnt[2]++;
            }
        }
        else if(s[i] == 'T'){
            if(visited[3][num]){
                cout << "GRESKA"; return 0;
            }
            else{
                visited[3][num] = true;
                cnt[3]++;
            }
        }
    }
    for(int i=0;i<4;i++){
        cout << 13 - cnt[i] << " ";
    }

    return 0;
}