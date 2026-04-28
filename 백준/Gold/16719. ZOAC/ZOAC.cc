#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;

    int size = s.size();
    int rep = size;
    vector<bool> visited(size, 0);

    while(rep--){
        unordered_map<string, int> um;
        set<string> st;
        for(int i=0;i<size;i++){
            if(!visited[i]){
                visited[i] = true;
                string temp = "";
                for(int j=0;j<size;j++){
                    if(visited[j]) temp += s[j];
                }
                visited[i] = false;
                um[temp] = i;
                st.insert(temp);
            }
        }
        string front; for(auto k : st){front = k; break;}
        visited[um[front]] = true;

        string temp2 = "";
        for(int j=0;j<size;j++){
            if(visited[j]) temp2 += s[j];
        }
        cout << temp2 << "\n";
    }
    return 0;
}