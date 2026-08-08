    #include <bits/stdc++.h>
    #include <cmath>
    #include <bit>
    using namespace std;
    typedef long long ll;
     
// ------- *** MAIN *** ------- //
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans[n];
    ll s[n];
    bool foo = true;
    
    cin >> s[0];
    int c = 1;
    int current = s[0];
    
    for (int i = 1; i < n; i++) {
      ll x;
      cin >> x;
      s[i] = x;
      if (s[i] == current) {
        c++;
      } else if (c == 1) {
        foo = false;
      } else {
        current = s[i];
        c = 1;
      }
    }
    if (c == 1) {
      foo = false;
    }

    int temp_idx = 0;
    for (int i = 0; i < n; i++) {
      if (i == n-1 || s[i] != s[i+1]) {
        ans[i] = temp_idx+1;
        temp_idx = i+1;
      } else {
        ans[i] = i+2;
      }
      
    }

    if (!foo) {
      cout << -1 << endl;
    } else {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}