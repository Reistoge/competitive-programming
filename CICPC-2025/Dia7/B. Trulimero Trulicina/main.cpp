#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/group/TY5qlgX1RN/contest/626062/problem/B
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
 
        int n = 0, m = 0, k = 0;
        cin >> n >> m >> k;
        int count = 1;
        int freq = 0;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        map<int, int> mn;
        int max = m - floor(m / 2);
        if(n % k == 0 && m%k == 0){
            //  6 3 3 
        }
        // int shift = 0;
        // if ((n * m) / k > max && (n * m) / k < m) shift = 1;
 
        for (int i = 0; i < n; i++)
        {
 
            for (int j = 0; j < m; j++)
            {
                if (freq >= ((n * m) / k))
                {
                    // if (count >= k)
                    // {
                    //     count = 0;
                    // }
                    count++;
                    freq = 0;
                }
                int index = j;
                if (i % 2 == 0 && index % 2 == 1)
                {
                    // index = m - j + 1;
                    mat[i][index] = count;
                    mn[count]++;
                    freq++;
                }
                else if (i % 2 == 1 && index % 2 == 0)
                {
                    mat[i][index] = count;
                    mn[count]++;
                    freq++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
 
            for (int j = 0; j < m; j++)
            {
                if (freq >= ((n * m) / k))
                {
                    // if (count > k)
                    // {
                    //     count = 0;
                    // 1 2 3 4 5 6 7
                    // 7 6 4 5 3 2 1
 
                    // }
                    count++;
                    freq = 0;
                }
                int index = j;
                if (i % 2 == 1 && index % 2 == 1)
                {
                    // index = m - j + 1;
                    mat[i][index] = count;
                    mn[count]++;
                    freq++;
                }
                else if (i % 2 == 0 && index % 2 == 0)
                {
                    mat[i][index] = count;
                    mn[count]++;
                    freq++;
                }
            }
        }
 
        // print
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        // for (auto it : mn)
        // {
        //     cout << it.first << " value:  " << it.second << endl;
        // }
       // 
        /*
            1 2 3 4 5
            6 7 8 9 10
            
        
        
        
        */
        

    }
 
    return 0;
}