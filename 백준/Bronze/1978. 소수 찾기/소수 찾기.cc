#include <stdlib.h>
#include <iostream>
using namespace std;
int primary_num(int n);

int main(){
  int t;
  cin >> t;

  int a[t];
  int cnt = 0;
  for(int i=0;i<t;i++){
    cin >> a[i];
    if(primary_num(a[i])) cnt++;
  }
  cout << cnt;
  return 0;
}

int primary_num(int n){
  int cnt = 0;
  for(int i=1;i<n+1;i++)
  {
    if(n%i==0) cnt++;
  }

  if(cnt == 2) return 1;
  else return 0;
}