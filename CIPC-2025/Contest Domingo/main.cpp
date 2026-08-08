#include <bits/stdc++.h>
using namespace std;

int main() {
    // Your code here
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        int value = 0;
        cin >> value; 
        v[i] = value;
        m[value]++;
    }
    
    
    return 0; 
}