#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {

        int h = 0, m = 0;
        cin >> h >> m;
        cout <<  (60-m) + 60*(23-h)<<endl;
    }

    return 0;
}