#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
//      signal(SIGSEGV, [](int) { _Exit(0); });
//      converts segfaults into Wrong Answers. Similarly catch `SIGABRT` (assertion failures) and `SIGFPE` (zero divisions).

//      feenableexcept(29);
//      kills the program on NaNs (1), 0-divs (4), infinities (8) and denormals (16)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);
void solve()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    priority_queue<tuple<int, int, char>> pq;
    for (int i = 0; i < k; i++)
    {

        if (i > (k / 2))
        {
            if (s[i] == 'L')
            {
                pq.push({k - i, i, 'L'});
            }
            else
            {
                pq.push({i, i, 'R'});
            }
        }
        else
        {
            if (s[i] == 'R')
            {
                
            }
            else
            {

            }
        }
        pq.push({});
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    int t;
    while (t--)
    {
        solve();
    }

    return 0;
}