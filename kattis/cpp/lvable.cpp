#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    int t = 2;
    for(int i  = 0; i < n; i++){
        if(s[i] == 'l' || s[i] == 'v') {
          
            if(s.substr(i,2) == "lv"){
                t = 0;
                break;
            }
            t = 1; 
        }
        
    }
    cout << t;
    
    
    
    return 0;
}