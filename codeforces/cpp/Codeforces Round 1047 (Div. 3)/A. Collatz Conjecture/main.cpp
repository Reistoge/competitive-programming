#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
   
    int x = 1;

    int t;
    cin >> t;
    while (t--)
    {
        int k = 0;
        int y = 0;
        cin >> k >> y;

        while (k >= 0)
        {
            if (x % 2 == 0)
            {
                x = x / 2;
            }
            else
            {
                x = (3 * x) + 1;
            }
            k--;
            
        }
    }
    return 0;
}