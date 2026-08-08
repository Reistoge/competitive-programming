#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> p(n, 0);


        for (int i = 0; i < p.size(); i++)
        {
            p[i] = i + 1;
        }
        int count = n + 1;
        cout << n << endl;
        do
        {
            for (int i = 0; i < p.size(); i++)
            {
                cout << p[i] << " ";
            }
            cout << endl;
            count--;
        } while (next_permutation(p.begin(), p.begin() + count));

        //next_permutation(p.begin(), p.end());
    }
    return 0;
}