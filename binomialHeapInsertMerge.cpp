#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int data, degree;
    Node *child, *parent, *sibling;
};
Node *newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->degree = 0;
    node->child = node->parent = node->sibling = nullptr;
    return node;
}
Node *merge(Node *b1, Node *b2)
{
    if (b1->data > b2->data)
        swap(b1, b2);
    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;
    return b1;
}
list<Node *> adjust(list<Node *> heap)
{
    if (heap.size() <= 1)
        return heap;
    list<Node *>::iterator it1, it2, it3;
    it1 = it2 = it3 = heap.begin();
    if (heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = heap.end();
    }
    else
    {
        it2++;
        it3 = it2;
        it3++;
    }
    while (it1 != heap.end())
    {
        if (it2 == heap.end())
        {
            it1++;
        }
        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if (it3 != heap.end())
                it3++;
        }
        else if (it3 != heap.end() &&
                 (*it1)->degree == (*it2)->degree && (*it1)->degree == (*it3)->degree)
        {
            it1++;
            it2++;
            it3++;
        }
        else if ((*it1)->degree == (*it2)->degree)
        {
            *it1 = merge(*it1, *it2);
            it2 = heap.erase(it2);
            if (it3 != heap.end())
                it3++;
        }
    }
    return heap;
}
list<Node *> unionHeap(list<Node *> l1, list<Node *> l2)
{
    list<Node *> new_heap;
    list<Node *>::iterator it1 = l1.begin();
    list<Node *>::iterator it2 = l2.begin();
    while (it1 != l1.end() && it2 != l2.end())
    {
        if ((*it1)->degree <= (*it2)->degree)
        {
            new_heap.push_back(*it1);
            it1++;
        }
        else
        {
            new_heap.push_back(*it2);
            it2++;
        }
    }
    while (it1 != l1.end())
    {
        new_heap.push_back(*it1);
        it1++;
    }
    while (it2 != l2.end())
    {
        new_heap.push_back(*it2);
        it2++;
    }
    return new_heap;
}
list<Node *> treeHeap(list<Node *> _heap, Node *node)
{
    list<Node *> temp;
    temp.push_back(node);
    temp = unionHeap(_heap, temp);
    return adjust(temp);
}
list<Node *> insert(list<Node *> _heap, int key)
{
    Node *node = newNode(key);
    return treeHeap(_heap, node);
}
void printTree(Node *tree)
{
    while (tree)
    {
        cout << tree->data << " ";
        printTree(tree->child);
        tree = tree->sibling;
    }
}
void printHeap(list<Node *> _heap)
{
    list<Node *>::iterator it = _heap.begin();
    while (it != _heap.end())
    {
        printTree(*it);
        it++;
        if (it != _heap.end())
        {
            cout << "--------->";
        }
    }
    cout << endl;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    list<Node *> bHeap, bHeap2, bHeap3;
    bHeap = insert(bHeap, 10);
    bHeap = insert(bHeap, 20);
    bHeap2 = insert(bHeap2, 6);
    bHeap2 = insert(bHeap2, 7);
    bHeap2 = insert(bHeap2, 8);
    bHeap2 = insert(bHeap2, 9);
    bHeap3 = insert(bHeap3, 11);
    cout << "After insertion Heap1: \n";
    printHeap(bHeap);
    cout << "After insertion Heap2: \n";
    printHeap(bHeap2);
    cout << "After insertion Heap3: \n";
    printHeap(bHeap3);
    // merging bHeap & bHeap2
    bHeap = unionHeap(bHeap, bHeap2);
    bHeap = adjust(bHeap);
    cout << "After merging bHeap & bHeap2: \n";
    printHeap(bHeap);
    // merging bHeap & bHeap3 (will contain bHeap, bHeap2, bHeap3)
    bHeap = unionHeap(bHeap, bHeap3);
    bHeap = adjust(bHeap);
    cout << "After merging bHeap & bHeap3: \n";
    printHeap(bHeap);
    return 0;
}