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
            string s1, s2;
            cin >> s1 >> s2;
            bool foo = true;
            for (int i = 0; i < n; i++) {
                if ((s1[i] == 'R' && s2[i] != 'R') || (s1[i] != 'R' && s2[i] == 'R')) {
                    foo = false;
                    break;
                }
            }
            cout << (foo ? "YES" : "NO") << endl;
        }
        return 0;
    }