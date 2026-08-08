#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
 
// ------- *** MAIN *** ------- //
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll c = 0;
        while (n > 1) {
            ll k = floor( (sqrt(24*n+1) - 1) / 6 );
            n = n - (3*k*k+k)/2;
            c++;
        }
        cout << c << endl;
    }
    return 0;
}