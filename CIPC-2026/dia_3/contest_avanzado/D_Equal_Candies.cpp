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
    int total = 0;
    int min = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      total += x;
      if (x < min) {
        min = x;
      }
    }
    cout << total - min*n << endl;
  }
  return 0;
}