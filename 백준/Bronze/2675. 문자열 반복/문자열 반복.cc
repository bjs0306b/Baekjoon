#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
  int t, c;
  string st;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> c >> st;

    int len = st.length();
    for(int k=0;k<len;k++){
      for(int j=0;j<c;j++)
        cout << st[k];
    }
    
    cout << endl;
  }
  return 0;
}
