#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<pair<int, int>>> graph;

void dijsktra(graph &adj, int source, vector<int> &distance, int n)
{
    vector<bool> processed(n, false);
    for (int i = 1; i < n; ++i)
        distance[i] = INT_MAX;
    distance[source] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, source});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (processed[a])
        {
            continue;
        }

        processed[a] = true;
        for (auto u : adj[a])
        {
            int b = u.first;
            int w = u.second;
            if ((distance[a] != INT_MAX) && (distance[a] + w < distance[b]))
            {
                distance[b] = distance[a] + w;
                q.push({distance[b], b});
            }
        }
    }
}
void print(graph g)
{
    for (int j = 0; j < g.size(); j++)
    {
        for (int i = 0; i < g[j].size(); i++)
        {
            cout << "node " << j << " connects with " << " node: " << g[j][i].first << " weight: " << g[j][i].second << endl;
        }
    }
}
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int s = 0;
    cin >> s;
    graph g(s + 1);

    for (int i = 0; i < s - 1; i++)
    {
        int n1 = 0, n2 = 0;
        cin >> n1 >> n2;
        g[n1].push_back(make_pair(n2, 1));
        g[n2].push_back(make_pair(n1, 1));
    }

    int q = 0;
    cin >> q;

    for (int i = 0; i < q; i++)
    {

        vector<int> a(s + 1);
        vector<int> b(s + 1);
        vector<int> c(s + 1);

        
        int sa = 0, sb = 0, sc = 0;
        cin >> sa >> sb >> sc;
        
        dijsktra(g, sa, a, s + 1);
        dijsktra(g, sb, b, s + 1);
        dijsktra(g, sc, c, s + 1);


        int min = INT_MAX;
        for (int k = 1; k < s + 1; ++k) {
            int cur_max = max({a[k], b[k], c[k]});
            if (cur_max < min) {
            min = cur_max;
            }
        }

        cout << min << endl;
    }

    return 0;
}