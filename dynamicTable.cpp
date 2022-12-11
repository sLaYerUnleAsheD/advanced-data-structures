#include <vector>
#include <iostream>

using namespace std;

class DynamicTable
{
private:
    vector<int> table;
    int it;

public:
    float cost;
    DynamicTable()
    {
        it = 0;
        cost = 0;
    }
    int insert(int);
    void print();
};
void DynamicTable::print()
{
    cout << "Table content: ";
    for (auto el : table)
        cout << el << " ";
    cout << endl;
}
int DynamicTable::insert(int x)
{
    int n = table.size();
    // cost = 0; //for testing cost of each operation
    if (it == n)
    {
        table.resize(n * 2);
        if (n == 0)
        {
            table.emplace_back(x);
            it++;
            cost++;
        }
        for (size_t i = 1; i <= it + 1 && n != 0; i++)
            cost++;
    }
    if (n)
    {
        
        if (it != n)
            cost++;
        table[it++] = x;
    }
    cout << "cost: " << cost << endl;
    return table.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    DynamicTable t;
    float n{0};
    for (size_t i = 0; i < 5; i++, n++)
        cout << "Table size after inserting " << i << " : " << t.insert(i) << endl;
    cout << endl;
    t.print();
    cout << "Amortized cost = " << t.cost / n << endl;
    return 0;
}