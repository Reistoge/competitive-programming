    #include <bits/stdc++.h>
    #include <cmath>
    using namespace std;
    typedef long long ll;
     
// ------- *** MAIN *** ------- //
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int even = 0;
        int min_pow = INT_MAX;
        vector<int> a(n,0);
        for (int i = 0; i < n; i++) {
          int x;
          cin >> x;
          if (x % 2 == 0) {
            even++;
            while (x % 2 == 0) {
              a[i] += 1;
              x /= 2;
            }
            min_pow = min(min_pow, a[i]);
          }
        }
        if (even == 0) {
          cout << 0 << endl;
        } else if (even == n) {
          cout << even-1+min_pow << endl;
        } else {
        cout << even << endl;
        }
    }
    return 0;
}