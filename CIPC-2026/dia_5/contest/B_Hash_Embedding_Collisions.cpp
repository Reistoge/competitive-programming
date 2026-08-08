#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    ll n;
    ll m;
    cin >> n;
    cin >> m;
    unordered_map<ll, ll> h;
    unordered_map<ll, bool> col;
    int c = 0;
    int aux = 0;
    for (int i = 0; i < n; i++)
    {
        ll id;

        cin >> id;

        ll r = id % m;

        if (h[r])
        {

            c++;
            col[r] = true;
        }
        else
        {
            if(id == 0){
                id = m;
            }
            h[r] = id;
        }
    }
    cout << c + col.size();

    return 0;
}