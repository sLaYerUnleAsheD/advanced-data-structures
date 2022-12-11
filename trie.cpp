#include <vector>
#include <iostream>
#include <string>

using namespace std;
#define ALPHA 26
struct TrieNode
{
    struct TrieNode *child[ALPHA];
    bool isEndOfKey;
};
struct TrieNode *newNode()
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfKey = false;
    for (int i = 0; i < ALPHA; i++)
    {
        pNode->child[i] = nullptr;
    }
    return pNode;
}
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *node = root;
    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (!node->child[index])
            node->child[index] = newNode();
        node = node->child[index];
    }
    node->isEndOfKey = true;
}
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *node = root;
    for (int i = 0; i < key.size(); i++)
    {
        if (!node->child[key[i] - 'a'])
            return false;
        node = node->child[key[i] - 'a'];
    }
    return node->isEndOfKey;
}
bool isEmpty(struct TrieNode *root)
{
    for (int i = 0; i < ALPHA; i++)
    {
        if (root->child[i])
            return false;
    }
    return true;
}
TrieNode *deleteKey(struct TrieNode *root, string key, int depth = 0)
{
    if (!root)
        return nullptr;
    if (depth == key.size())
    {
        if (root->isEndOfKey)
            root->isEndOfKey = false;
        if (isEmpty(root))
        {
            delete root;
            root = nullptr;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->child[index] = deleteKey(root->child[index], key, depth + 1);
    if (isEmpty(root) && !root->isEndOfKey)
    {
        delete root;
        root = nullptr;
    }
    return root;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    vector<string> keys = {"hello", "mihir", "endsem", "boring", "life", "beru"};
    struct TrieNode *root = newNode();
    for (auto key : keys)
    {
        insert(root, key);
    }
    char decision = 'y';
    do
    {
        cout << "Enter key to be searched: ";
        string srch;
        cin >> srch;
        bool isPresent = search(root, srch);
        if (isPresent)
        {
            cout << srch << " is Present in Trie\n";
        }
        else
        {
            cout << srch << " is NOT Present in Trie\n";
        }
        cout << "Search more? (y / any character) ";
        cin >> decision;
    } while (decision == 'y' || decision == 'Y');
    deleteKey(root, "endsem");
    search(root, "endsem") ? cout << "Present\n" : cout << "Not Present\n";
    return 0;
}