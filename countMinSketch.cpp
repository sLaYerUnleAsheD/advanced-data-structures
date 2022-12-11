#include <iostream>
#include <string>

using namespace std;
#define ll long long
int hash1(string s, int arrSize)
{
    ll h = 0;
    for (int i = 0; i < s.size(); i++)
    {
        h += (int)s[i];
        h = h % arrSize;
    }
    return h;
}
int hash2(string s, int arrSize)
{
    ll h = 4;
    for (int i = 0; i < s.size(); i++)
    {
        h *= ((int)s[i] + 1) + 42432;
        h = h % arrSize;
    }
    return h;
}
int hash3(string s, int arrSize)
{
    ll h = 4;
    for (int i = 0; i < s.size(); i++)
    {
        h *= (((int)s[i] + 1) / 23) * 45 + 45532;
        h = h % arrSize;
    }
    return h % arrSize;
}
int hash4(string s, int arrSize)
{
    ll h = 0;
    for (int i = 0; i < s.size(); i++)
    {
        h += (((int)s[i] + 1) / 23) * (h + i + 1);
        h = h % arrSize;
    }
    return h % arrSize;
}
int findFreq(int bitarr[4][100], int arrSize, string s)
{
    int a = hash1(s, arrSize);
    int b = hash2(s, arrSize);
    int c = hash3(s, arrSize);
    int d = hash4(s, arrSize);
    return min(min(bitarr[0][a], bitarr[1][b]), min(bitarr[2][c], bitarr[3][d]));
}
void insertInTable(int bitarr[4][100], int arrSize, string s)
{
    int a = hash1(s, arrSize);
    int b = hash2(s, arrSize);
    int c = hash3(s, arrSize);
    int d = hash4(s, arrSize);
    bitarr[0][a]++;
    bitarr[1][b]++;
    bitarr[2][c]++;
    bitarr[3][d]++;
    cout << s << " is inserted\n";
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int bitarr[4][100] = {0};
    int arrSize{100};
    string sarray[7] = {"A", "B", "K", "A", "A", "K", "S"};
    for (int i = 0; i < 7; i++)
    {
        insertInTable(bitarr, arrSize, sarray[i]);
    }
    cout << "Frequency of A: " << findFreq(bitarr, arrSize, "A");
    cout << "Frequency of K: " << findFreq(bitarr, arrSize, "K");
    cout << endl;
    return 0;
}