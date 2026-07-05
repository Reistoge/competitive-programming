// K - El neutrino
//https://codeforces.com/gym/640342

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

ll fpow(ll b, ll e){
    if(e <= 0) return 1;
    ll temp = fpow(b, e / 2);
    if(e % 2 == 0){
        return (temp * temp)%MOD;
    } else {
        return (((b * temp)%MOD) * temp)%MOD;
    }
}

int main(){
    ll n;
    cin >> n;

    ll fact = 1;
    ll mult = n - 2;
    
    ll sum = (fpow(2, mult) * fact)%MOD;
    
    for(int i = 2; i <= n; i++){
        sum = (sum + ((fpow(2, mult)*fact)%MOD))%MOD;
        fact = (fact * i)%MOD;
        mult = mult - 1;
        if(mult <= 0) mult = 0;
    }
    
    cout << sum << endl;
    
    return 0;
}