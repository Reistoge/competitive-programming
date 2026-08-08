// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
 
    for(int i = 0; i < t; i++) {
 
        int n, k; cin >> n >> k;
        bool fooR = false;
        bool fooL = false;
 
        for(int j = 0; j < n; j++) {
            int l, r; 
            cin >> l >> r;
            
            if (l == k) {
                fooL = true;
            }
            if (r == k) {
                fooR = true;
            }
 
        }
        
        if(fooL && fooR) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
 
    }
}