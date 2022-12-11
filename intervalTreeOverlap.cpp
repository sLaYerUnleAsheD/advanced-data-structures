#include <iostream>

using namespace std;
struct Node
{
    int l, r, max;
    Node *left, *right;
    Node(int l, int r)
    {
        this->l = l;
        this->r = r;
        left = right = nullptr;
        this->max = r;
    }
};
Node *newNode(int l, int r)
{
    Node *node = new Node(l, r);
    return node;
}
Node *insert(Node *&root, int l, int r)
{
    if (!root)
        return newNode(l, r);
    if (l < root->l)
    {
        root->left = insert(root->left, l, r);
    }
    else if (l > root->l)
    {
        root->right = insert(root->right, l, r);
    }
    else
    {
        if (r < root->r)
        {
            root->left = insert(root->left, l, r);
        }
        else if (r > root->r)
        {
            root->right = insert(root->right, l, r);
        }
    }
    if (root->max < r)
    {
        root->max = r;
    }
    return root;
}
bool checkOverlap(Node *&root, int l, int r)
{
    if (!root)
        return false;
    if (root->l <= r && root->r >= l)
    {
        return true;
    }
    if (root->left != nullptr && root->left->max >= l)
    {
        return checkOverlap(root->left, l, r);
    }
    return checkOverlap(root->right, l, r);
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    Node *root = nullptr;
    root = insert(root, 5, 10);
    root = insert(root, 3, 8);
    root = insert(root, 10, 15);
    root = insert(root, 16, 18);
    root = insert(root, 9, 11);
    root = insert(root, 1, 1);
    checkOverlap(root, 1, 2) ? cout << "Yes\n" : cout << "No\n";
    checkOverlap(root, 7, 11) ? cout << "Yes\n" : cout << "No\n";
    checkOverlap(root, 20, 25) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}