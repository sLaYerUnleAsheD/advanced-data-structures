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
bool lookup(bool *bitarr, int arrSize, string s)
{
    int a = hash1(s, arrSize);
    int b = hash2(s, arrSize);
    if (bitarr[a] && bitarr[b])
        return true;
    return false;
}
void insert(bool *bitarr, int arrSize, string s)
{
    if (lookup(bitarr, arrSize, s))
    {
        cout << s << " is probably already present\n";
    }
    else
    {
        int a = hash1(s, arrSize);
        int b = hash2(s, arrSize);
        bitarr[a] = true;
        bitarr[b] = true;
        cout << s << " is inserted\n";
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    bool bitarr[100] = {false};
    int arrSize{100};
    string sarray[33] = {"abound", "abounds", "abundance",
                         "abundant", "accessible", "bloom",
                         "blossom", "bolster", "bonny",
                         "bonus", "bonuses", "coherent",
                         "cohesive", "colorful", "comely",
                         "comfort", "gems", "generosity",
                         "generous", "generously", "genial",
                         "bluff", "cheater", "hate",
                         "war", "humanity", "racism",
                         "hurt", "nuke", "gloomy",
                         "facebook", "geeksforgeeks", "twitter"};
    for (int i = 0; i < 33; i++)
    {
        insert(bitarr, arrSize, sarray[i]);
    }
    lookup(bitarr, arrSize, "abound") ? cout << "Present\n" : cout << "Not Present\n";
    return 0;
}