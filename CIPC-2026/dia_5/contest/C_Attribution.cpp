#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    ll w, a, n;
    cin >> w >> a >> n;
    unordered_map<ll, pair<ll, ll>> m;
    vector<ll> ads_rev(a);

    for (int i = 0; i < n; i++)
    {
        char code;
        cin >> code;
        if (code == 'C')
        {
            ll t, ad, p;
            cin >> t >> ad >> p;
            m[p] = {t, ad};
        }
        else
        {
            ll t, p, mount;
            cin >> t >> p >> mount;
            if (t - m[p].first <= w)
            {
                // cout << m[p].second << endl;
                
                if ( m[p].second > 0 && m[p].second <= ads_rev.size())
                {
                    ads_rev[m[p].second - 1] += mount;
                }
            }
        }
    }
    for (auto p : ads_rev)
    {
        cout << p << endl;
    }

    return 0;
}