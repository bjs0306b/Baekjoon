#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class node{
public:
    node* left;
    node* right;
    char name;
    node():left(NULL),right(NULL){}
    node(char c, node* l, node* r):name(c),left(l),right(r){}
};

void preorder(node* root){
    if(root){
        cout << root->name;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout << root->name;
        inorder(root->right);
    }
}

void postorder(node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->name;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a; cin >> a;
    node n[a];
    for(int i=0;i<a;i++){
        char c = 'A'+i;
        n[i].name = c;
    }
    for(int i=0;i<a;i++){
        char c1,c2,c3; cin >>c1>>c2>>c3;
        int num1 = c1 - 'A',num2,num3;
        if(c2 == '.'){
            n[num1].left = NULL;
        }
        else{
            num2 = c2 - 'A';
            n[num1].left = n+num2;
        }
        if(c3 == '.'){
            n[num1].right = NULL;
        }
        else{
            num3 = c3 - 'A';
            n[num1].right = n+num3;
        }
    }
    
    preorder(n); cout << "\n";
    inorder(n); cout << "\n";
    postorder(n);
    return 0;
}