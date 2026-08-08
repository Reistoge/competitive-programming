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
    float n;
    cin >> n;
    int aux = -INT_MAX;
    int max_sum = 0;
    int max_even = 0;
    int max_odd = 0;

    for (int i = 1; i < n + 1; i++)
    {
        int x;
        cin >> x;
        if (x > aux)
        {

            aux = x;
            max_even = 0;
            max_odd = 0;
            if (i % 2 == 0)
            {
                max_even = 1;
            }
            else
            {
                max_odd = 1;
            }
        }
        else if (x == aux)
        {
            if (i % 2 == 0)
            {
                max_even = 1;
            }
            else
            {
                max_odd = 1;
            }
        }
    }
    //cout << "max even: " << max_even << " max odd: " << max_odd << endl;
    if (max_odd && (int)n % 2 == 1)
    {
        cout << (int)(aux + ceil(((float)n) / 2)) << endl;
    }
    else
    {

        cout << (int)(aux + ((float)n) / 2) << endl;
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