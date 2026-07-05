#include <bits/stdc++.h>
using namespace std;

 
 
template <class T>
vector<int> kmp(T s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if(s[j] == s[i]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string a ="oso oso";
    for(int i : kmp(a)){
        cout << i<<" ";
    }

    return 0;
}





