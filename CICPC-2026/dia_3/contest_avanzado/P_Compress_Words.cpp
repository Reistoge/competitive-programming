#include <bits/stdc++.h>
using namespace std;
void solve(string &P, int m)
{

    vector<int> pi = vector<int>(m);
    map<int, int> mm;
    pi[0] = 0;
    int k = 0;

    for (int q = 1; q < m; q++)
    {
        while (k > 0 && P[k] != P[q])
        {
            k = pi[k - 1];
        }
        if (P[k] == P[q])
        {
            k++;
        }
        pi[q] = k;
        if (q != m-1) {
            mm[k] = q;
        }
    }

    for (int i = pi.size()-1; i >= 0; i--)
    {
        if (mm[pi[i]]) {
            cout << P.substr(0, pi[i]);
            return ;
        }
    }
    cout << "Just a legend";

}

int main()
{
    // Your code here
    string s;
    cin >> s;
    solve(s, s.size());
    

    return 0;
}