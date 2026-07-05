#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    string r ="";
    string c="";
    while (t)
    {

        string w;
        cin >> w;
        int l = w.length();
        c = (l > 10) ? w[0] + to_string(l - 2) + w[l - 1] : w;
        r+= c + "\n";

        t--;
    }
    cout << r;

    return 0; 
}