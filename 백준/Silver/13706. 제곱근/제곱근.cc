#include <bits/stdc++.h>
using namespace std;

// 문자열로 이분 탐색

// a <= b 이면 true
bool compare(string a, string b){
    if(a.size() < b.size()) return true;
    else if(a.size() == b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i] < b[i]) return true;
            if(a[i] > b[i]) return false;
        }
        return true; // 동일
    }
    else return false;
}

string add(string a, string b){
    if(a.size() < b.size()) swap(a,b);

    string temp(a.size(), '0');
    for(int i=0;i<a.size()-b.size();i++){
        temp[i] = a[i];
    }
    for(int i=a.size()-b.size();i<a.size();i++){
        int num  = (a[i] - '0') + (b[i - (a.size()-b.size())] - '0');
        temp[i] = ('0' + num);
    }
    bool bonus_num = false;
    for(int i=temp.size()-1;i>=0;i--){
        int num = temp[i] - '0';
        if(bonus_num){
            num++;
            bonus_num = false;
        }
        if(num > 9){
            num -= 10;
            bonus_num = true;
        }

        temp[i] = '0' + num;
    }
    if(bonus_num) return "1"+temp;
    return temp;
}

string multiply(string a, string b){
    vector<int> v(a.size() + b.size(), 0);

    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            int num = (a[i] - '0') * (b[j] - '0');
            v[a.size() + b.size() - i - j - 2] += num;
        }
    }

    for(int i=0;i<v.size();i++){
        v[i+1] += (v[i] / 10);
        v[i] %= 10;
    }

    string ret = "";
    for(int i=v.size()-1;i>=0;i--){
        ret += (v[i] + '0');
    }

    for(int i=0;i<ret.size();i++){
        if(ret[i] != '0') return ret.substr(i, ret.size());
    }
}

string minus_one(string a){

    string b(a.size(), '9');

    string temp(a.size(), '0');
    for(int i=0;i<a.size()-b.size();i++){
        temp[i] = a[i];
    }
    for(int i=a.size()-b.size();i<a.size();i++){
        int num  = (a[i] - '0') + (b[i - (a.size()-b.size())] - '0');
        temp[i] = ('0' + num);
    }
    bool bonus_num = false;
    for(int i=temp.size()-1;i>=0;i--){
        int num = temp[i] - '0';
        if(bonus_num){
            num++;
            bonus_num = false;
        }
        if(num > 9){
            num -= 10;
            bonus_num = true;
        }

        temp[i] = '0' + num;
    }

    for(int i=0;i<temp.size();i++){
        if(temp[i] != '0') return temp.substr(i, temp.size());
    }
}

string aver(string a, string b){
    string sum = add(a,b);

    bool bonus_num = false;
    for(int i=0;i<sum.size();i++){
        int num = sum[i] - '0';
        if(bonus_num){
            num += 10;
            bonus_num = false;
        }
        char c = '0' + (num/2);
        sum[i] = c;
        if(num % 2) bonus_num = true;
    }

    for(int i=0;i<sum.size();i++){
        if(sum[i] != '0') return sum.substr(i, sum.size());
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n; cin >> n;

    string s = "0", e = "1" + string(400, '0');

    string ans;
    while(compare(s,e)){
        string m = aver(s,e);

        // cout << s << " " << m << " " << e << "\n";

        string mm = multiply(m,m);
        if(compare(mm, n)){
            s = add(m, "1");
            ans = m;
        }
        else e = minus_one(m);
    }

    cout << ans;

    return 0;
}