#include <stdlib.h>
#include <iostream>
using namespace std;

int gene_num(int n){
  string str = to_string(n);
  int len = str.length();
  int sum = n;
  for(int i=0;i<len;i++) 
    sum += (static_cast<int>(str[i])-static_cast<int>('0'));
  
  return sum;
}
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    if(n == gene_num(i)){
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}