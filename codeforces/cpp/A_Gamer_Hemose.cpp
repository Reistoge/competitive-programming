#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        int H = 0;
        int d1 = 0;
        int d2 = 0;

        cin >> n >> H;
        for (int j = 0; j < n; j++)
        {

            int a = 0;

            cin >> a;
            if (a >= d1)
            {
                int aux = d1;
                d1 = a;
                d2 = aux;
            }
            else if (a >= d2)
            {
                d2 = a;
            }
        }
        if (d1 >= H)
        {

            cout << 1 << endl;
            continue;
        }
        else if ((d1 + d2) >= H)
        {
            cout << 2 << endl;
            continue;
        }

        int m = H / (d1 + d2);

        int r = H % (d1 + d2);

        if (r != 0)
        {
            int b = 1;
            if (r > d1)
            {
                b++;
            }
            cout << 2 * m + b << endl;
        }
        else
        {
            cout << 2 * m << endl;
        }
    }

    return 0;
}