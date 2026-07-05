#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {

        int n = 0, s = 0, m = 0;
        cin >> n >> s >> m;
        vector<int> v(m,0);

        for (int j = 0; j < n; j++)
        {
            int l = 0, r = 0;
            cin >> l >> r;
            

            for (int q = l; q < r ; q++)
            {
                v[q] = 1;
                
                
            }
    
        }
 
     
        int c = 0;
        string res = "NO";
        for (int k = 0; k < m; k++)
        {
            if (v[k] == 0)
            {
                c++;
                if(c == s){
                    res ="YES";
                    break;
                }
                
            }
            else if(v[k]==1){
                c = 0;
            }
        }
        cout << res << endl;
        
    }

    return 0;
}