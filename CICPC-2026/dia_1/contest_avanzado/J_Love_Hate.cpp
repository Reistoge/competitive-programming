#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int n, m, p;
    cin >> n >> m >> p;
    vector<string> v(n);
    map<int, int> h;
    map<float, float> pt;
    vector<int> r(m);
    for (int i = 0; i < n; i++)
    {

        string x = "";

        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == '1')
            {
                h[j]++;
                
                pt[j] = (float)h[j] / (float)n;
                if (h[j] > ceil(m / 2.0))
                {
                    r[j] = 1;
                }
            }
        }
        v[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '0' && ((int)v[i][j] != r[j]))
            {
                h[j]--;
                cout <<  "pt "<< j<<" : " << pt[j] << endl;
                if (h[j] > ceil(m / 2.0) && pt[j]>(.5f))
                {
                    r[j] = 0;
                }
            }
        }
    }
    for(auto xi : r){
        cout << xi << " ";
    }

    return 0;
}