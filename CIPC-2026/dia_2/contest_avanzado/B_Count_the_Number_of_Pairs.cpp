    #include <bits/stdc++.h>
    #include <cmath>
    using namespace std;
    typedef long long ll;
     
    // ------- *** MAIN *** ------- //
    int main() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            vector<int> foo(128, 0);
            cin >> n >> k;
            string s;
            cin >> s;
            int c = 0;
            for (int i = 0; i < n; i++) {
              foo[static_cast<int>(s[i])]++;
            }

            for (int i = 65; i < 91; i++) {
              int p = min(foo[i], foo[i+32]);
              c += p;
              foo[i] -= p;
              foo[i+32] -= p;
              int left = foo[i]/2 + foo[i+32]/2;
              // cout << "left: " << left << endl;
              if (left >= k) {
                c += k;
                k = 0;
              } else {
                c += left;
                k -= left;
              }
            }
            
            cout << c << endl;
        }
        return 0;
    }   