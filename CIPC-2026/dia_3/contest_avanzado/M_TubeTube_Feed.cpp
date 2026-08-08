#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  
// ------- *** MAIN *** ------- //
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int max = 0;
    int max_index = -2;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      if (v[i] <= t-i && s[i] > max) {
        max = s[i];
        max_index = i;
      }
    }
    cout << max_index + 1 << endl;
  
  }
  return 0;
}