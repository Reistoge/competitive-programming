#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<pair<int, int>>> graph;

int main()
{

    int n = 0, c = 0;
    cin >> n >> c;
    graph g = {
        {},
        {{2, 2}, {3, 1}, {4, 2}},
        {{4,1}}
    };
    g.erase();
    for (int i = 0; i < c; i++)
    {
        int n1 = 0, n2 = 0, n3 = 0;
        cin >> n1 >> n2 >> n3 ;
        g[n1].push_back({n2,n3});

    }
    for (int j = 0; j < g.size(); j++)
    {
        for (int i = 0; i < g[j].size(); i++)
        {
            cout << "node " << j << " connects with " << " node: " << g[j][i].first << " weight: " << g[j][i].second << endl;
        }
    }

    return 0;
}