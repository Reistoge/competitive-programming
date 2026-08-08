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
    string s;
    cin >> s;

    char smallest = s[0];

    for (int i = 1; i < n; i++) {
      if (s[i] < smallest) {
        smallest = s[i];
      }
    }
    
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == smallest) {
        s[i] = ' ';
        break;
      } 
    }

    cout << smallest;
    
    for (int i = 0; i < n; i++) {
      if (s[i] != ' ') {
        cout << s[i];
      }
    }
    
    cout << endl;
  }
  return 0;
}