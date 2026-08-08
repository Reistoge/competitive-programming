#include <bits/stdc++.h>
using namespace std;
// DFS Function
void dfs(const vector<vector<pair<int, int>>> &adj, vector<bool> &visited, int start)
{
    stack<int> stk; // Stack to store nodes for DFS
    stk.push(start);

    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();

        if (!visited[node])
        {
            visited[node] = true;
            cout << "Node " << node << " -> ";

            for (const auto &neighbor : adj[node])
            {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                if (!visited[nextNode])
                {
                    
                    stk.push(nextNode);
                }
            }
            cout << endl;
        }
    }
}
int main()
{

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        cin >> n;
        vector<vector<pair<int, int>>> g(n);
        vector<int> w(n, 0);

        for (int j = 0; j < n; j++)
        {
            cin >> w[j];
        }
        for (int k = 0; k < n - 1; k++)
        {
            int n1 = 0;
            int n2 = 0;
            cin >> n1 >> n2;
            g[n1 - 1].push_back({n2 - 1, w[k]});
        }
    }

    return 0;
}