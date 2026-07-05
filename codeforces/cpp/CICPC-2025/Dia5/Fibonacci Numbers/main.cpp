#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1722

#include <bits/stdc++.h>
#define forn(i, i0, n) for (int i = int(i0); i < int(n); i++)
typedef long long ll;
using namespace std;

template <class T>
vector<vector<T>> mult(vector<vector<T>> a, vector<vector<T>> b, long long mod)
{
    int n = a.size(), m = b[0].size(), l = a[0].size();
    vector<vector<T>> ans(n, vector<T>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < l; k++)
            {
                T temp = (a[i][k] * b[k][j]) % mod;
                ans[i][j] = (ans[i][j] + temp) % mod;
            }
        }
    }
    /*
    for(auto &line: ans)
        for(T &a: line) a = (a % mod + mod) % mod;
    */
    return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> v, ll n, long long mod)
{
    ll dim = v.size();
    vector<vector<ll>> ans(dim, vector<ll>(dim, 0));
    for (ll i = 0; i < dim; i++)
        ans[i][i] = 1;
    while (n)
    {
        if (n & 1)
            ans = mult(ans, v, mod);
        v = mult(v, v, mod);
        n = n >> 1;
    }
    return ans;
}
int main()
{
    /*
        dp[n] = dp[n-1] + dp[n-2]

        dp[0] = 0       |0 1|   *   |1| = |1|
        dp[1] = 1       |1 1|       |1|   |2|


        |f(n+1)|   = |1 1|^n * |1|
        |f(n)  |     |1 0|     |0|
    */
    


    return 0;
}