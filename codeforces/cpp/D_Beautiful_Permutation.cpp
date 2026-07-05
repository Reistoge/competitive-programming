#include <bits/stdc++.h>
using namespace std;

int query(int type, int l, int r)
{
    cout << type << " " << l << " "<< r << endl<< flush;
    int x;
    cin >> x;
    return x;
}
int main()
{

    int c = 0;
    cin >> c;
    while (c--)
    {

        bool found = false;
        int n;
        cin >> n;

        int t = ((n * n) + n) / 2;
        int l = n / 2;
        int r = (n / 2) + 1;

        int p = 1;
        int f = n;

        while (!found)
        {

            int q1 = query(1, p, l);
            int q2 = query(1, r, f);

            int q3 = query(2, p, l);
            int q4 = query(2, r, f);

            int ldif = q3 - q1;
            int rdif = q4 - q2;

            if (ldif == 0)
            {
                p = r;
                l = ((f - r) / 2) + r;
                r = ((f - r) / 2 + r) + 1;
            }
            else if (rdif == 0)
            {
                f = l;
                l = (l / 2);
                r = (l / 2) + 1;
            }

            else if (ldif != 0 && rdif != 0)
            {
                

                int i = l - ldif + 1;
                //cout << "l: " << l << "ldif: "<<ldif;
                
                int d = r + rdif - 1 ;
                //cout << "r: " << r << "rdif: "<<rdif;

                found = true;
                cout << "! " << i << " " << d << endl << flush;
            }
        }
    }
    return 0;
}