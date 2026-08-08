#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    string a;
    string e;
    string i;
    string o;
    string u;
    while (t--)
    {
        int n;
        cin >> n;
        int rest = n % 5;
        //cout << rest << endl;
        int mult = n / 5;
        //cout << mult << endl;

        float add = ((float)rest / 5);

       // cout << add << endl;

        a = string(mult + (add >= .2f ? 1 : 0), 'a');
        e = string(mult + (add >= .4f ? 1 : 0), 'e');
        i = string(mult + (add >= .6f ? 1 : 0), 'i');
        o = string(mult +(add >= .8f ? 1 : 0),'o');
        u = string(mult, 'u');
        cout << a + e + i + o + u << endl;
    }

    return 0;
}