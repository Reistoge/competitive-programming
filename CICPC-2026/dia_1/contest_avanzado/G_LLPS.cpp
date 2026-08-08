#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
 
// ------- *** MAIN *** ------- //
int main() {
    string t;
    cin >> t;
    char ans = '0';
    int count = 0;
    int n = t.size();
    for (int i = 0; i < n; i++) {
        if (t[i] > ans) {
            ans = t[i];
            count = 1;
        } else if (t[i] == ans) {
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << ans;
    }
    return 0;
}