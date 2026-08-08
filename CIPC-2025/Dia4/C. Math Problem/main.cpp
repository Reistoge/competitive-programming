#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n = 0;
        cin >> n;
        map<long, long> m;

        for (int j = 0; j < n; j++)
        {
            long long l = 0, r = 0;
            cin >> l >> r;
            m[l] = r;
        }
        cout << endl;
        for (auto u = m.begin(); u != m.end(); u++)
        {
            cout << u->first<<" "<<u->second<<endl;
        }

        cout << endl;
        long long minL = m.begin()->first;
        long long minR = m.begin()->second;

        for (auto u = m.begin(); u != m.end(); u++)
        {

            long long l1 = u->first;
            long long r1 = u->second;
            auto u2 = u++;
            long long l2 = u2->first;
            long long r2 = u2->second;
            cout << endl;
            cout << l1 << " " << r1 << endl;
            cout << l2 << " " << r2 << endl;
            cout << minL << " " << minR << endl;
            cout << endl;
            if (minR < l2)
            {
                minL = minR;
                minR = m.end()->first;
                break;
            }
            if (min(r1, r2) == r2)
            {
                minL = l2;
                minR = r2;
            }
        }
        cout << minR - minL;
    }

    return 0; // Return 0 to indicate successful execution
}