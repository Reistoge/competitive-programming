#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,m,r,c;
        cin >> n >> m >> r >> c;

        cout << ((n-r)*(m)) + (n-r)*(m-1) + (m-c)  << endl;
    }   
    return 0; 
}