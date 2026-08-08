#include <bits/stdc++.h>
using namespace std;
void double(vector<int,int> &v){
    for (int i = 0; i < m.size(); i++)
    {
        m[i]*=2;
    }
    
    
}
int main()
{
    // Your code here
    int t = 0;
    cin >> t;
    while (t)
    {
        int n = 0, c = 0;
        int cost = 0;
        cin >> n >> c;
        it++;
        vector<int> v(n);
        map<int, int> m;
        int mult = 2;
        int cont = 0;
        for (int i = 0; i < n; i++)
        {
            int value = 0;
            cin >> value; 

            if(value <= c){
                v[i] = value;
                m[value]++;
                
            }
            
        }

        int aux = c;
        auto lw = lower_bound(v.begind(),v.end(),c);
        
        
        // if(lw->second == 0) 
        // if (lw->first == c)
        // {
        //     lw->second--;
        //     it++;
        //     aux -= 1;
        //     continue;
        // }
        // else if (lw->first * it < c)
        // {
        //     lw->second--;
        //     it++;
        //     aux = c;
        //     continue;
        // }

        t--;
    }
    return 0;
}