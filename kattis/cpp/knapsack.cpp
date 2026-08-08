#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=zRza99HPvkQ
int main()
{

    int c;
    int n;

    while (cin >> c && cin >> n)
    {
        vector<vector<int>> m(n + 1, vector<int>(c + 1)); // hold current profit and remaining weight
        vector<pair<int, int>> items(n + 1);              // value - profit, weight
        stack<int> q;
        for (int i = 1; i < n + 1; i++)
        {

            int v, w;
            cin >> v;
            cin >> w;
            items[i] = make_pair(v, w);
        }
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < c + 1; j++)
            {
                auto item = items[i];
                if (i == 0 || j == 0)
                {
                    m[i][j] = 0;
                }
                else if (item.second <= j)
                {
                    int noNewItem = m[i - 1][j]; // default state wtihout placing the item
                    int prev = m[i - 1][j - item.second]; // the optimal state for a weight of j-item.second and without the item and can be placed into (the optimal previous state)
                    m[i][j] = max(item.first + prev, noNewItem);
                }
                else
                {
                    m[i][j] = m[i - 1][j];
                }
            }
        }

        // for (int i = 0; i < n + 1; i++)
        // {
        //     for (int j = 0; j < c + 1; j++)
        //     {
        //         cout << m[i][j] << " ";
        //     }
        //     cout <<endl;
        // }
        int i = n;
        int j = c;
        while (i > 0 && j > 0)
        {
            if (m[i][j] != m[i - 1][j])
            {
                
                q.push(i-1);
                j = j - items[i].second;
            }
            i = i - 1;
        }
        cout << q.size() << endl;
        while (!q.empty())
        {
            cout << q.top() << " ";
            q.pop();
        }
        cout << endl;

     }
    return 0;
}
