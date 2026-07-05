// https://codeforces.com/gym/106178/problem/I
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<pair<int, int>>> graph;
typedef pair<int, int> pii;

queue<int> q;
// void print(graph g)
// {
//     for (int j = 0; j < g.size(); j++)
//     {
//         for (int i = 0; i < g[j].size(); i++)
//         {
//             cout << "node " << j << " connects with " << " node: " << g[j][i].first << " weight: " << g[j][i].second << endl;
//         }
//     }
// }
void dfs(int u, graph &g, vector<bool> &visited)
{

    visited[u] = true;
    if (visited[visited.size() - 1])
    {
        cout << q.size() << endl;
        while (!q.empty())
        {

            cout << q.front() << " ";
            q.pop();
        }
        exit(0);
    }

    // process node u here
    for (auto v : g[u])
    {

        if (!visited[v.first])
        {


            q.push(v.first);

            dfs(v.first, g, visited);
        }
    }
}
int main()
{

    int n = 0;
    int c = 0;
    cin >> n >> c;
    graph g(2 * n + 1);
    vector<bool> v(2 * n + 1);

    for (int i = 0; i < c; i++)
    {
        int x1 = 0;
        int x2 = 0;
        cin >> x1 >> x2;
        if (x2 - x1 != 1)
        {
            g[x1].push_back(make_pair(x2, 1));
        }
    }
    // print(g);
    q.push(1);
    dfs(1, g, v);

    if (v[2 * n] == false || q.size() >= c)
    {
        cout << "*";
    }

    cout << endl;

    return 0;
}
