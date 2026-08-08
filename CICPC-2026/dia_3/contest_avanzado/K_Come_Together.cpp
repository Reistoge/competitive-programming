#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  
// ------- *** MAIN *** ------- //
int main() {
  int t;
  cin >> t;
  while (t--) {
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    
  int ans = 1;

  if ((bx > ax && cx > ax) || (bx < ax && cx < ax))
    ans += min(abs(bx - ax), abs(cx - ax));

  if ((by > ay && cy > ay) || (by < ay && cy < ay))
    ans += min(abs(by - ay), abs(cy - ay));
    
    cout << ans << endl;

  }
  return 0;
}