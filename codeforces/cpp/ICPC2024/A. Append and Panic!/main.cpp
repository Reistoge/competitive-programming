#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    map<char,int> m;
    
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    cout<< s.size() - m.size();

    return 0; 
}