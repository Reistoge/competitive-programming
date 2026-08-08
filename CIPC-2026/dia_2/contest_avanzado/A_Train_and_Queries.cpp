#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
        
int main() {
    // Your code here
    ll t; cin >> t;
    
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll> v(n);
        map<ll,pair<ll,ll>> m;
        for(ll i = 0; i<n;i++){
            ll ui; cin >> ui;
            v[i] = ui;
            
            if(m.find(ui) == m.end()){
                m[ui] = {i,i};
 
            }
            m[ui].second = i;
        
        }
        for(ll i = 0; i<k; i ++){
            ll l, r;
            cin >> l >> r;
            if (m.find(l) == m.end() || m.find(r) == m.end()){
                cout << "NO"<< endl;
            } else if(m[l].first < m[r].second){
                cout << "YES"<< endl;
            }
            else{
                cout << "NO"<< endl;
            }
        }
        // for( auto x : m){
        //     cout <<"x: "<< x.first <<" l: "<< x.second.first<< " r: "<< x.second.second<< endl;
        // }
 
    }
 
    return 0; 
}