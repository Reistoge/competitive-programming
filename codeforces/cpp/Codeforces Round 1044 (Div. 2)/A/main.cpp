// https://codeforces.com/contest/2133/problem/A
// https://codeforces.com/contest/2133/problems

#include <bits/stdc++.h>
using namespace std;
float checkGear(vector<float>::iterator it, vector<float>::iterator end, float n){
    if (it++ == end) {
        return (((*it)/(it++))/n)
    }
    else{
        checkGear()
    }
 
}
int main() {
    // Your code here
    int t = 0, n = 0;
    cin >> t;
    while(t--){
        cin >> n;
        vector<float> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }



        

        


    }

    return 0; 
}