#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
     
// ------- *** MAIN *** ------- //
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> foo(27, 0);
    vector<int> del(27, 0);
    string w;
    cin >> w;
    int p;
    cin >> p;
    int k = 0;

    for (int i = 0; i < w.length(); i++) {
      foo[static_cast<int>(w[i])-96]++;
      k += static_cast<int>(w[i])-96;
    }

    for (int i = 26; i > 0; i--) {
      while (k > p && foo[i] > 0) {
        k -= i;
        foo[i]--;
        del[i]++;
      }

    }
    for (int i = 0; i < w.length(); i++) {
      if (del[static_cast<int>(w[i])-96] > 0) {
        del[static_cast<int>(w[i])-96]--;
      } else {
        cout << w[i];
      }
    }
    cout << endl;
  }
  return 0;
}