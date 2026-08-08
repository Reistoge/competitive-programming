#include <bits/stdc++.h>
#define forn(i,i0,n) for(int i = int(i0); i < int(n); i++)
typedef long long ll;

using namespace std;

template<class T>
vector<vector<T>> mult(vector<vector<T>> a, vector<vector<T>> b,long long mod){
    int n = a.size(),m = b[0].size(),l = a[0].size();
    vector<vector<T>> ans(n,vector<T>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < l; k++){
                T temp = (a[i][k]*b[k][j]) % mod;
                ans[i][j] = (ans[i][j] + temp) % mod;
            }
        }
    }
    /*
    for(auto &line: ans)
        for(T &a: line) a = (a % mod + mod) % mod;
    */
    return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> v,ll n,long long mod){
    ll dim = v.size(); vector<vector<ll>> ans(dim,vector<ll>(dim,0));
    for(ll i = 0; i < dim; i++) ans[i][i] = 1;
    while(n){
        if(n & 1) ans = mult(ans,v,mod);
        v = mult(v,v,mod);
        n = n >> 1;
    }
    return ans;
}

int main(){

    ll t; cin >> t;
    while(t--){
        vector<vector<ll>> mat(23,vector<ll>(23));
        vector<vector<ll>> wea(23,vector<ll>(1,0));
        wea[22][0] = 1;
        
        forn(i,0,22){
            mat[i][i+1] = 1;
        }
        
        vector<ll> pos = {6,10,14,18};
        for(ll a: pos) mat[22][22 - a + 1] = 3;
        ll n; cin >> n;
        mat = binpow(mat,n,1e9+7);
        mat = mult(mat,wea,1e9+7);
        ll ans = 0;
        forn(i,0,20) ans += mat[22 - i][0],ans %= (ll) 1e9+7;
        cout << ans << endl;
    }
    
    
    return 0;
}