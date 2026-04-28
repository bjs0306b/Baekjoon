#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str; cin >> str;
    long long sum = 0;
    if(str == "black") sum+=0;
    else if(str == "brown") sum+=1;
    else if(str == "red") sum+=2;
    else if(str == "orange")  sum +=3;
    else if(str == "yellow")  sum += 4;
    else if(str == "green") sum +=5;
    else if(str == "blue") sum +=6;
    else if(str == "violet")  sum +=7;
    else if(str == "grey") sum  +=8;
    else if(str == "white")  sum += 9;
    sum *= 10;
    cin >> str;
    if(str == "black") sum+=0;
    else if(str == "brown") sum+=1;
    else if(str == "red") sum+=2;
    else if(str == "orange")  sum +=3;
    else if(str == "yellow")  sum += 4;
    else if(str == "green") sum +=5;
    else if(str == "blue") sum +=6;
    else if(str == "violet")  sum +=7;
    else if(str == "grey") sum  +=8;
    else if(str == "white")  sum += 9;
    cin >> str;
    int num;
    if(str == "black")  num = 0;
    else if(str == "brown")  num = 1;
    else if(str == "red")  num = 2;
    else if(str == "orange")   num = 3;
    else if(str == "yellow")   num =  4;
    else if(str == "green")  num = 5;
    else if(str == "blue")  num = 6;
    else if(str == "violet")   num = 7;
    else if(str == "grey")  num = 8;
    else if(str == "white")   num =  9;
    for(int i=0;i<num;i++) sum *= 10;
    cout << sum;
    return 0;
}