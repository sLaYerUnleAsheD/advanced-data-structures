#include <vector>
#include <iostream>

using namespace std;

class BinaryCounter
{
    int kBits;
    vector<int> ctr;

public:
    float cost;

    BinaryCounter()
    {
        kBits = 8;
        cost = 0;
        ctr.resize(kBits);
        cout << "Initial binary no.: ";
        for (auto el : ctr)
            cout << el;
    }
    BinaryCounter(int k)
    {
        kBits = k;
        cost = 0;
        ctr.resize(kBits);
        cout << "Initial binary no.: ";
        for (auto el : ctr)
            cout << el;
    }
    void increment();
};
void BinaryCounter::increment()
{
    int i;
    i = ctr.size() - 1;

    while (ctr[i] != 0)
    {
        ctr[i--] = 0;

        cost++;
    }
    if (i > -1)
    {
        ctr[i] = 1;

        cost++;
    }
    // cout << "cost: " << cost << endl;
    for (auto el : ctr)
    {
        cout << el;
    }
}
int main()
{
    BinaryCounter b;
    int i{1};
    char decision{'Y'};
    cout << endl;
    float n{0}, acc{0};
    while (decision == 'Y' || decision == 'y')
    {
        cout << "Increment no. " << i << "\nBinary no.: ";
        b.increment();
        n++;
        i++;
        cout << "\nContinue increment? (Y/any character): ";
        cin >> decision;
    }
    cout << endl;
    cout << "No. of operations: " << n << endl;
    cout << "Amortized Complexity: " << b.cost / n << endl;
    return 0;
}