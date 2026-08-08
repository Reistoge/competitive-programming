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
    string n;
    cin >> n;
    bool foo;
    if (static_cast<int>(n[0])+static_cast<int>(n[1])+static_cast<int>(n[2]) == static_cast<int>(n[n.length()-1])+static_cast<int>(n[n.length()-2])+static_cast<int>(n[n.length()-3])) {
      foo = true;
    } else {
      foo = false;
    }
    cout << (foo ? "YES" : "NO") << endl;
  }
  return 0;
}