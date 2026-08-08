#include <bits/stdc++.h>
using namespace std;
template <class T, T m_(T, T)>
struct segment_tree
{
    int n;
    vector<T> ST;
    segment_tree() {}
    segment_tree(vector<T> &a)
    {
        n = a.size();
        ST.resize(n << 1);
        for (int i = n; i < (n << 1); i++)
            ST[i] = a[i - n];
        for (int i = n - 1; i > 0; i--)
            ST[i] = m_(ST[i << 1], ST[i << 1 | 1]);
    }
    void update(int pos, T val)
    { // replace with val
        ST[pos += n] = val;
        for (pos >>= 1; pos > 0; pos >>= 1)
            ST[pos] = m_(ST[pos << 1], ST[pos << 1 | 1]);
    }
    T query(int l, int r)
    { // [l, r]
        T ansL, ansR;
        bool hasL = 0, hasR = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ansL = (hasL ? m_(ansL, ST[l++]) : ST[l++]), hasL = 1;
            if (r & 1)
                ansR = (hasR ? m_(ST[--r], ansR) : ST[--r]), hasR = 1;
        }
        if (!hasL)
            return ansR;
        if (!hasR)
            return ansL;
        return m_(ansL, ansR);
    }
};
int mergeSum(int a, int b)
{
    return a+b;
}
int main()
{
    // Your code here
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> e(m, 0);
    vector<int> r(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int employees = 0;
        cin >> employees;
        e[i] = employees;
    }
    segment_tree<int,mergeSum> st(e);
    for (int i = 0; i < n; i++)
    {
        if(a[i] >= e[i]){

        }   
    }
    


    return 0;
}