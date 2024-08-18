#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    node *right;
    int val;

    node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void insert(node* &root, int val) {
    if (!root) {
        root = new node(val);
    } else if (val < root->val) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

void post(node *root)
{
    if (root->left)
        post(root->left);
    if (root->right)
        post(root->right);
    cout << root->val << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    node *root = new node(n);

    while (cin >> n)
    {
        insert(root, n);
    }

    post(root);

    return 0;
}