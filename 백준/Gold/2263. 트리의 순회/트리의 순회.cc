#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> in, post;
unordered_map<int, int> in_m;
bool visited[100000];

void func(int s, int e)
{
    if (s == e)
        cout << post[e] << " ";
    else if (s < e)
    {
        int temp = post[e];
        int pos = in_m[temp];
        cout << temp << " ";  //<< s << " " << e << "\n";
        visited[pos] = 1;

        int a = pos-1;
        int left = 0;
        while (a >= 0 && !visited[a])
        {
            a--;
            left++;
        }
        int b = pos+1;
        int right = 0;
        while (b < n && !visited[b])
        {
            b++;
            right++;
        }
        //cout << left << " " << right << "\n";

        func(s, s + left - 1);
        func(e - right, e - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        in.push_back(num);
        in_m[num] = i; // 어떤 수가 어떤 위치에 있는 지 저장.
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        post.push_back(num);
    }

    func(0, n - 1);

    return 0;
}