#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cout << endl;
        cin >> n;
        vector<int> sum;
        for (int i = 0; i < n.length(); i++)
        {
            char c = n[i];
            // cout << "character "<< c << "to int " << (int) c -'0';  
            if (n[i] == '0')
            {
                continue;
            }

            else
            {
                sum.push_back(pow(10, n.length()-i -1 ) * ((int)c -'0'));
            }
        }
        cout << sum.size()<< endl;
        for (int d : sum)
        {
            cout << d << " ";
        }
    
    }
    return 0;
}