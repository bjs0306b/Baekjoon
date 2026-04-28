#include <bits/stdc++.h>
using namespace std;

bool used[26];

void func(string s){

    vector<string> words;

    int start = 0, size = s.size();

    for(int i=0;i<size;i++){
        if(s[i] == ' '){
            string temp = s.substr(start, i - start);
            words.push_back(temp);
            start = i+1;
        }
    }

    words.push_back(s.substr(start, size - start));

    vector<string> vv;
    bool flag = false;
    for(auto k : words){
        if(!flag){
            if(!used[tolower(k[0]) - 'a']){
                flag = true;
                used[tolower(k[0]) - 'a'] = true;
                string ss = "[";
                ss += k[0];
                ss += ']';
                ss += k.substr(1, k.size() - 1);

                vv.push_back(ss);
            }
            else vv.push_back(k);     
        }
        else vv.push_back(k);
    }
    if(flag){
        for(auto k : vv) cout << k << " ";
        cout << "\n";
    }
    else{
        bool flag2 = false;
        for(int i=0;i<size;i++){
            if(!flag2){
                if(!used[tolower(s[i]) - 'a'] && s[i] != ' '){
                    cout << "[";
                    cout << s[i];
                    cout << "]";
                    flag2 = true;
                    used[tolower(s[i]) - 'a'] = true;
                }
                else cout << s[i];
            }
            else cout << s[i];
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();

    for(int i=0;i<n;i++){
        string s; getline(cin, s);
        //cout << s << "\n";
        func(s);
    }

    return 0;
}