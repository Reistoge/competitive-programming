#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);
        vector<int> degree(n + 1, 0);
        vector<pair<int, int>> edges;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            edges.push_back({u, v});

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        map<int, int> degree_count;
        
        for (int i = 1; i <= n; i++) {
            degree_count[degree[i]]++;
        }

    //     for (const auto& [k, v] : degree_count) {
    //     cout << k << ": " << v << endl;
    // }

        degree_count.erase(1);

        int x, y;

        if (degree_count.size() == 1) {
          int d = degree_count.begin()->first;
          x = d;
          y = d - 1;
        }
        else {
          auto a = degree_count.begin();
          auto b = prev(degree_count.end());

          if (a->second == 1) {
            x = a->first;
            y = b->first - 1;
          } else {
            x = b->first;
            y = a->first - 1;
          }
        }
        cout << x << " " << y << endl;
      }

    return 0;
}