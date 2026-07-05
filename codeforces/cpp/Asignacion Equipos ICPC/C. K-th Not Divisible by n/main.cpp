#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int t;
    cin >> t;

    // ir acortando por cantidad de sumas...
    while (t--)
    {

        int n = 0;
        int k = 0;
        cin >> n >> k;
        int c = 0;
        int i = 0;
        int i2 = 0;
 


        i2 = (k / n)+1;
        i = i2 * n;

        c = i - i2;
 

        cout << i<< endl;
        cout << i2 << endl;
        cout << c << endl;
        cout << endl;
        while (c != k)
        {
            i++;
            if (i % n != 0 )
            {
                c++;
          
                if (c == k)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
