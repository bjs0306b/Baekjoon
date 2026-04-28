#include <bits/stdc++.h>
using namespace std;

map<char, int> m;

string a_to_r(int n){
    string r = "";
    while(n){
        if(n >= 1000){
            n -= 1000;
            r += 'M';
        }
        else if(n >= 900){
            n -= 900;
            r += "CM";
        }
        else if(n >= 500){
            n -= 500;
            r += 'D';
        }
        else if(n >= 400){
            n -= 400;
            r += "CD";
        }
        else if(n >= 100){
            n -= 100;
            r += 'C';
        }
        else if(n >= 90){
            n -= 90;
            r += "XC";
        }
        else if(n >= 50){
            n -= 50;
            r += 'L';
        }
        else if(n >= 40){
            n -= 40;
            r += "XL";
        }
        else if(n >= 10){
            n -= 10;
            r += 'X';
        }
        else if(n >= 9){
            n -= 9;
            r += "IX";
        }
        else if(n >= 5){
            n -= 5;
            r += 'V';
        }
        else if(n >= 4){
            n -= 4;
            r += "IV";
        }
        else if(n >= 1){
            n--;
            r += 'I';
        }
    }
    return r;
}

int r_to_a(string s){
    int r = 0;
    for(int i=0;i<s.size()-1;i++){
        if(m[s[i]] < m[s[i+1]]){
            r -= m[s[i]];
        }
        else r += m[s[i]];
    }
    r += m[s[s.size()-1]];
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2; cin >> s1 >> s2;
    m['I'] = 1, m['V'] = 5, m['X'] = 10, m['L'] = 50, m['C'] = 100, m['D'] = 500, m['M'] = 1000;
    
    int n1 = r_to_a(s1), n2 = r_to_a(s2);  
    //cout << n1 << " " << n2 << "\n";

    cout << n1 + n2 << '\n' << a_to_r(n1+n2);

    return 0;
}