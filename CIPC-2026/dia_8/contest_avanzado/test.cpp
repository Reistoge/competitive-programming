#include <bits/stdc++.h>
using namespace std;

int calc_distance(string &s1, string &s2)
{
    int sum = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            sum += abs(s1[i] - s2[i]);
        }
    }
    return sum;
}

int main()
{
    int n, k;

    cin >> n >> k;
    vector<string> v(k);

    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        v[i] = s;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < k - 1; i++)
    {
        string s1, s2, s3;
        s1 = v[i - 1];
        s2 = v[i];
        s3 = v[i + 1];
        auto c1 = calc_distance(s2, s3);
        auto c2 = calc_distance(s1, s2);

        cout << "c1: " << c1 << " c2: " << c2 << endl;
    }
}