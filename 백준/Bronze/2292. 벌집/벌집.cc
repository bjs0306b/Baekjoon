#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  float n;
  cin >> n;

  int num = ceil((n-1)/6);

  int cnt = 1;
  while(num > cnt*(cnt-1)/2){
    cnt++;
  }


  cout << cnt;
  return 0;
}