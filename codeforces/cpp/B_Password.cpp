#include <bits/stdc++.h>
using namespace std;
int q_max = -INT_MAX;
vector<int> lps(string &s)
{
    vector<int> pi = vector<int>(s.size());
    int q = 0;
    for (int i = 1; i < s.size(); i++)
    {

        while (q > 0 && s[q] != s[i])
        {
            q = pi[q];
        }

        if (s[q] == s[i])
        {
            q++;
        }

        pi[i] = q;
        q_max = max(q_max, q);

    }

    return pi;
}

int main()
{
    // Your code here
    string s;
    // 0 0 0 0 0 1 2 3 4 5 0 0 0 0
    cin >> s;
    vector<int> v = lps(s);
    q_max = -INT_MAX;
    int k = v[s.size() - 1];
    if (k <= 0)
    {
        cout << "Just a legend";
    }

    else
    {
        cout << "k: " << k << endl;
        string sub = s.substr(0, s.size() - k );
        cout << "sub: " << sub << endl;

        vector<int> v2 = lps(sub);
        cout <<"q_max: " << q_max << endl;
        for (auto x : v2)
        {
            cout << x << " ";
        }

        string r = s.substr(0,q_max);
        if(r !="" ){
            cout << r;
        }
        else{
            cout << "Just a legend";
        }
    }

    return 0;
}
