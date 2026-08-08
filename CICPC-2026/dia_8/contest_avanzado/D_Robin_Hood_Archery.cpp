#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
//      signal(SIGSEGV, [](int) { _Exit(0); });
//      converts segfaults into Wrong Answers. Similarly catch `SIGABRT` (assertion failures) and `SIGFPE` (zero divisions).

//      feenableexcept(29);
//      kills the program on NaNs (1), 0-divs (4), infinities (8) and denormals (16)

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
    T query(ll l, ll r)
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
pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first < b.first)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> values(n);

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        values[i] = make_pair(x, i);
        sum += x;
    }

    segment_tree<pair<ll, ll>, merge> sTree(values);
    // for (auto x : sTree.ST)
    // {
    //     cout << x.first << " ";
    // }

    while (q--)
    {
        ll l, r = 0;
        cin >> l >> r;
        ll splits = r - l + 1;
        ll robin = 0;
        ll sheriff = 0;
        bool s = false;
        // cout << "splits: " << splits << endl;

        while (splits)
        {
            // cout << "l - 1 " << l - 1 << endl;
            // cout << "r - 1 " << r - 1 << endl;

            auto p = sTree.query(l - 1, r - 1);
            // cout << "p " << p.first << " " << p.second << endl;
            sTree.update(p.second, make_pair(0, p.second));
            if (s)
            {
                sheriff += p.first;
            }
            else
            {
                robin += p.first;
            }
            s = !s;
            splits--;
        }
        // cout << "sheriff: " << sheriff << " robin: " << robin << endl
        //      << endl;
        if (sheriff < robin)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
        segment_tree<pair<ll, ll>, merge> sTreeAux(values);
        sTree = sTreeAux;
        //     for (auto x : sTree.ST)
        //     {
        //         cout << x.first << " ";
        //     }
        //     cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}