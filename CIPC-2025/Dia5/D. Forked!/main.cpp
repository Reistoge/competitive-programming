#include <bits/stdc++.h>
using namespace std;

int solve(pair<int, int> &c, pair<int, int> &k, pair<int, int> &q)
{
    vector<pair<int, int>> sf;
    vector<pair<int, int>>
        s1 = {
            {k.first - c.first, k.second - c.second},
            {k.first + c.first, k.second + c.second},
            {k.first + c.first, k.second - c.second},
            {k.first - c.first, k.second + c.second},

        };
    vector<pair<int, int>>
        s2 = {

            {q.first - c.first, q.second - c.second},
            {q.first + c.first, q.second + c.second},
            {q.first + c.first, q.second - c.second},
            {q.first - c.first, q.second + c.second},
        };

    cout << endl;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (auto it : s1)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
    for (auto it : s2)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;

    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(sf, sf.begin()));
    return sf.size();
}
int main()
{

    int t = 0;
    cin >> t;

    while (t)
    {

        pair<int, int> c;
        cin >> c.first;
        cin >> c.second;

        pair<int, int> k;
        cin >> k.first;
        cin >> k.second;

        pair<int, int> q;
        cin >> q.first;
        cin >> q.second;

        int s = solve(c, k, q);
        cout << s << endl;
        t--;
    }
    return 0;
}