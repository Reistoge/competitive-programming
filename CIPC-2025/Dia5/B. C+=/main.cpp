#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int t = 0;
    cin >> t;
    while (t)
    {
        int n1 = 0, n2 = 0, n = 0;
        cin >> n1 >> n2 >> n;
        int it = 0;
        while (n1 < n && n2 < n)
        {
            n1+=n2;
            
        }
        cout << it << endl;

        t--;
    }
    return 0;
}