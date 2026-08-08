#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
     
// ------- *** MAIN *** ------- //
int main() {
  int n, m; 
  cin >> n >> m; //columnas yyy quest que hay q hacer (alturas y testcase)
  vector<ll> mundito(n, 0);
  vector<ll> prefixsum(n, 0);
  vector<ll> suffixsum(n, 0);

  for(int i = 0; i < n; i++) {
      ll x; cin >> x;
      mundito[i] = x;
  }

  for(int i = 0; i < n-1; i++) {
      prefixsum[i+1] = prefixsum[i] + max((ll) 0, mundito[i]-mundito[i+1]);
  }

  for (int i = n-1; i > 0; i--) {
      suffixsum[i-1] = suffixsum[i] + max((ll) 0, mundito[i]-mundito[i-1]);
  }


  // for(int i = 0; i < n; i++) {
  //     cout << prefixsum[i] << " " << suffixsum[i] << endl;
  // }

  while(m--) {
      int s, j; cin >> s >> j;
      if (s < j) {
          cout << prefixsum[j-1] - prefixsum[s-1] << endl;
      } else {
          cout << suffixsum[j-1] - suffixsum[s-1] << endl;
      }
  }
  return 0;
}