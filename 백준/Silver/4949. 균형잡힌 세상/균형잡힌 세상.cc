        #include <iostream>
        #include <algorithm>
        #include <vector>
        #include <string>
        using namespace std;




        int check(string s){
            vector<char> vec;
            string::iterator iter;
            int ret = 1;
            for(iter=s.begin();*iter!='.';iter++){
                switch(*iter){
                    case '[':
                    case '(':
                        vec.push_back(*iter);
                        break;
                    case ']':
                        if(!vec.empty() && vec.back() == '['){ vec.pop_back(); break;}
                        else {ret = 0; break;}
                    case ')':
                        if(!vec.empty() && vec.back() == '('){ vec.pop_back(); break;}
                        else {ret = 0; break;}
                }
            }

            if(!vec.empty()) ret = 0;

            return ret;
        }
        int main(){
            ios_base::sync_with_stdio(0);cin.tie(0);
            string str;
            getline(cin, str);
            while(str != "."){
                if(check(str)) cout << "yes" << "\n";
                else cout << "no" << "\n";
                getline(cin, str);
            }
            return 0;
        }