#include <vector>
#include <iostream>

using namespace std;

class Stack
{
private:
    int top;
    bool isEmpty;
    vector<int> st;

public:
    float com;
    Stack()
    {
        top = -1;
        com = 0;
        isEmpty = true;
    }
    void push(int);
    void pop();
    int topEl();
    void multiPop(int);
};
void Stack::push(int x)
{
    st.emplace_back(x);
    isEmpty = false;
    top = st.size() - 1;
    com++;
}
int Stack::topEl()
{
    return st[top];
}
void Stack::pop()
{
    int x{-1};
    if (!isEmpty)
    {
        x = st[st.size() - 1];
        st.pop_back();
        top = st.size() - 1;
        com++;
    }
    if (top == -1)
        isEmpty = true;
    cout << "Popped: " << x << endl;
}
void Stack::multiPop(int k)
{
    int x = st.size();
    int noOfPops = min(x, k);
    if (x)
    {
        cout << "Multi-popped: " << noOfPops << " elements:\n";
        for (size_t i = 0; i < noOfPops; i++)
        {
            cout << st[st.size() - 1] << " ";
            st.pop_back();
            com++;
        }
        cout << endl;
    }
    else
    {
        com++;
    }
    top = st.size() - 1;
    if (top == -1)
        isEmpty = true;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    srand(time(NULL));
    Stack mystack;
    int n;
    cout << "Enter no. of functions: ";
    cin >> n;
    int f = n;
    while (f--)
    {
        int x = (rand() * 100) % 3;
        switch (x)
        {
        case 0:
            mystack.push((rand() * 100) % 60);
            break;
        case 1:
            mystack.pop();
            cout << endl;
            break;
        case 2:
            int k;
            cout << "Enter no. of pops: ";
            cin >> k;
            mystack.multiPop(k);
            break;
        }
    }
    cout << "Complexity: " << mystack.com / float(n) << endl;
    return 0;
}