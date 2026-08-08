#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int n = 0;
    string w;
    cin >> n >> w;
    int c = 0;
    int r = 0;
    int xc = 0;
    for (int i = 0; i < n; i++)
    {
        if (w[i] == 'x')
        {   
            c++;
            if (c > 2)
            {
                r++;
            }
        }
        else
        {
            c = 0;
        }
    }

  
    cout << r;

    return 0;
}