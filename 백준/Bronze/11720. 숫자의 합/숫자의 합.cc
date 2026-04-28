#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  string str;
  cin >> str;
  int sum = 0;
  for(int i=0;i<t;i++)
  {
    sum += static_cast<int>(str[i]) - static_cast<int>('0'); 
  }
  cout << sum;
  return 0;
}
