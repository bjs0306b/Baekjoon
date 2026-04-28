#include <bits/stdc++.h>
using namespace std;

string s; // 초기 입력값
int cnt; // 괄호 수

bool unactive[200]; // 비활성화된 s의 index
set<string> ans; // 출력할 문자열열

vector<pair<int, int>> prs;//괄호 쌍의 index

void dfs(int n)
{
    if (n == cnt)
    {   
        bool flag = false;
        string temp = "";
        for (int i = 0;i<s.size();i++){
            if(!unactive[i]){
                temp.push_back(s[i]);
            }
            else flag = true;
        }
        if(flag) ans.insert(temp);
        return;
    }

    unactive[prs[n].first] = true, unactive[prs[n].second] = true;
    dfs(n+1);

    unactive[prs[n].first] = false, unactive[prs[n].second] = false;
    dfs(n+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;

    stack<int> stk; 
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '('){
            stk.push(i);
            cnt++;
        }
        else if (s[i] == ')')
        {
            prs.push_back({stk.top(), i});
            stk.pop();
        }
    }

    dfs(0);

    for (auto k : ans)
        cout << k << "\n";

    return 0;
}