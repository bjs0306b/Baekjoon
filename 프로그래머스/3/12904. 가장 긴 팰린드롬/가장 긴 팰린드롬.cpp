#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;
    int n = s.size();

    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j=1;;j++){
            if(i-j >= 0 && i+j < n && s[i-j] == s[i+j]){
                cnt += 2;
            }else break;
        }
        answer = max(answer, cnt);
    }
    
    for(int i=0;i<n-1;i++){
        if(s[i] != s[i+1]) continue;
        int cnt = 2;
        for(int j=1;;j++){
            if(i-j >= 0 && i+j+1 < n && s[i-j] == s[i+1+j]){
                cnt += 2;
            }else break;
        }
        answer = max(answer, cnt);
    }

    return answer;
}