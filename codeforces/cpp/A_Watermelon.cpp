#include <bits/stdc++.h>
using namespace std;

int main() {
    // Your code here
    int  t = 0;
    cin >> t;
    
    bool result = t>3 && (t-2)%2 ==0 ;
    cout << (result ? "YES" : "NO");
    return 0; // Return 0 to indicate successful execution
}