#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Graph;

void dfs_visit(Graph &adj, vector<int> &v, int s)
{

    v[s] = 1;

    for (int n : adj[s])
    {
        if (v[n] == 0)
        {
            dfs_visit(adj, v, n);
        }
    }
    v[s] = 2;
}
int dfs(Graph &adj, int s)
{
    int min = 0;
    vector<int> v(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
    {
        if (v[i] == 0)
        {
            min++;
            dfs_visit(adj, v, i);
        }
    }
    return min;
}

int main()
{
    // Your code here
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        Graph adj(n);
        for (int j = 0; j < m; j++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        int min = dfs(adj, 0);
        cout << min - 1 << endl;
    }
    return 0;
}