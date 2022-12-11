#include <iostream>
#include <math>

using namespace std;
int getSum(int *st, int ss, int se, int qs, int qe, int si)
{
    if (ss >= qs && se <= qe)
    {
        return st[si];
    }
    if (ss > qe || se < qs)
    {
        return 0;
    }
    int mid = ss + (se - ss) / 2;
    return getSum(st, ss, mid, qs, qe, 2 * si + 1) + getSum(st, mid + 1, se, qs, qe, 2 * si + 2);
}
int constructST(int arr[], int *st, int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = ss + (se - ss) / 2;
    st[si] = constructST(arr, st, ss, mid, 2 * si + 1) + constructST(arr, st, mid + 1, se, 2 * si + 2);
    return st[si];
}
int *construct(int arr[], int n)
{
    int height = ceil(log2(n));
    int max_size = 2 * pow(2, height) - 1;
    int *st = new int[max_size];
    constructST(arr, st, 0, n - 1, 0);
    return st;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *st = construct(arr, n);
    cout << "Sum of values in given range = " << getSum(st, 0, n - 1, 1, 3, 0) << endl;
    return 0;
}