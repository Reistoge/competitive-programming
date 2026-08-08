#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll x = n - 1;
    ll ans = 0;

    while (x > 1) {
        x >>= 1;
        ans++;
    }

    cout << ans + 1 << endl;

    return 0;
}