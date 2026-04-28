#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
  int a[8];
  for(int i=0;i<8;i++) cin >> a[i];
  int cnt = 0;
  for(int i=0;i<7;i++){
    if(a[i]<a[i+1])
      cnt++;
  }

  if(cnt==7) cout<<"ascending";
  else if(cnt==0) cout << "descending";
  else cout << "mixed";
}
