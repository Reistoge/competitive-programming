#include <bits/stdc++.h>
using namespace std;

/* Segment Tree
 *Description:* Range queries, build $O(n)$, query and update $O(log n)$, positions [0, n - 1]
 *Status:* Highly tested
 */
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
int merge(int a, int b)
{
    return min(a, b);
}

int main()
{

    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        values[i] = x;
    }

    segment_tree<int, merge> sTree(values);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, w;
        cin >> l >> r >> w;
        // l--;
        // r--;
        int ans = -INT_MAX;
        //cout << "i: " << i;
        //cout << endl;
        for (int j = l-1; j <= (r - w); j++)
        {
            //cout << " j: " << j<< " j+w: "<< j+w-1 << endl;
            int query = sTree.query(j, j + w-1);
            //cout <<"query: " <<q << endl;
            ans = max(query, ans);
        }
        cout << ans << endl;
    }

    return 0;
}