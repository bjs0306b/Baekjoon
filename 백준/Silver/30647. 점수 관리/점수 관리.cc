#include<bits/stdc++.h>
using namespace std;

class student{
public:
    string name;
    int score;
    bool isHidden;

    student(){}
    student(string n, int s, bool i):name(n),score(s),isHidden(i){}

    bool operator<(student other){
        if(score == other.score) return name < other.name;
        return score > other.score;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n; cin >> n;

    student st[n];

    for(int i=0;i<n;i++){
        string s; cin >> s;
        auto iter1 = find(s.begin(), s.end(), ':'), iter2 = find(s.begin(), s.end(), ',');
        int pos1 = iter1 - s.begin(), pos2 = iter2 - s.begin();
        string name = s.substr(pos1+2, pos2-pos1-3);

        auto iter3 = find(iter2+1, s.end(), ':'), iter4 = find(iter2+1, s.end(), ',');
        int pos3 = iter3 - s.begin(), pos4 = iter4 - s.begin();
        string score_str = s.substr(pos3+1, pos4-pos3-1);
        int score = stoi(score_str);

        auto iter5 = find(iter4+1, s.end(), ':');
        char zero_or_one = *(iter5+1);
        int flag = zero_or_one - '0';

        st[i] = student(name, score, flag);
    }

    sort(st, st+n);

    int num1 = 0, num2 = 0, pre_score = 0;
    for(auto k : st){
        num1++;
        if(pre_score != k.score) num2 = num1;
        if(!k.isHidden) cout << num2 << " " << k.name << " " << k.score << "\n";
        pre_score = k.score;
    }   
    return 0;
}