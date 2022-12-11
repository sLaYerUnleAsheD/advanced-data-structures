#include <iostream>
#include <queue>

using namespace std;
enum Color
{
    RED,
    BLACK
};
struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;
    Node(int key)
    {
        this->data = key;
        this->color = RED;
        left = right = parent = nullptr;
    }
};
class RBTree
{
    Node *root;

public:
    RBTree()
    {
        root = nullptr;
    }
    void insert(int);
    void fix(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void rotateLeft(Node *&, Node *&);
    void levelOrder();
};
void RBTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != nullptr)
    {
        pt->right->parent = pt;
    }
    pt_right->parent = pt->parent;
    if (!pt->parent)
    {
        root = pt_right;
    }
    else if (pt == pt->parent->left)
    {
        pt->parent->left = pt_right;
    }
    else
    {
        pt->parent->right = pt_right;
    }
    pt->parent = pt_right;
    pt_right->left = pt;
}
void RBTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;
    pt->left = pt_left->right;
    if (pt->left != nullptr)
    {
        pt->left->parent = pt;
    }
    pt_left->parent = pt->parent;
    if (!pt->parent)
    {
        root = pt_left;
    }
    else if (pt == pt->parent->left)
    {
        pt->parent->left = pt_left;
    }
    else
    {
        pt->parent->right = pt_left;
    }
    pt->parent = pt_left;
    pt_left->right = pt;
}
Node *BST(Node *&root, Node *&pt)
{
    if (!root)
        return pt;
    if (pt->data < root->data)
    {
        root->left = BST(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BST(root->right, pt);
        root->right->parent = root;
    }
    return root;
}
void RBTree::fix(Node *&root, Node *&pt)
{
    Node *parent_pt = nullptr;
    Node *gParent_pt = nullptr;
    while (pt != root && pt->color != BLACK && pt->parent->color == RED)
    {
        parent_pt = pt->parent;
        gParent_pt = pt->parent->parent;
        // CASE 1
        if (parent_pt == gParent_pt->right)
        {
            Node *uncle_pt = gParent_pt->left;
            // uncle is red
            if (uncle_pt != nullptr && uncle_pt->color == RED)
            {
                gParent_pt->color = RED;
                uncle_pt->color = BLACK;
                parent_pt->color = BLACK;
                pt = gParent_pt;
            }
            else
            {
                // appropriate rotation required
                if (pt == parent_pt->left)
                {
                    // right rotation required
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(root, gParent_pt);
                swap(parent_pt->color, gParent_pt->color);
                pt = parent_pt;
            }
        }
        else
        {
            Node *uncle_pt = gParent_pt->right;
            // uncle is red
            if (uncle_pt != nullptr && uncle_pt->color == RED)
            {
                gParent_pt->color = RED;
                uncle_pt->color = BLACK;
                parent_pt->color = BLACK;
                pt = gParent_pt;
            }
            else
            {
                // appropriate rotation required
                if (pt == parent_pt->right)
                {
                    // left rotation required
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(root, gParent_pt);
                swap(parent_pt->color, gParent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}
void RBTree::insert(int data)
{
    Node *ptr = new Node(data);
    root = BST(root, ptr);
    fix(root, ptr);
}
void levelTraverse(Node *&root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << " ";
        Node *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}
void RBTree::levelOrder()
{
    levelTraverse(root);
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    RBTree t;
    t.insert(5);
    t.insert(15);
    t.insert(2);
    t.insert(11);
    t.insert(13);
    t.insert(34);
    t.insert(42);
    t.insert(55);
    cout << "Level order traversal after insertion: \n";
    t.levelOrder();
    return 0;
}
