#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/group/TY5qlgX1RN/contest/626280/problem/E
typedef vector<vector<pair<int, int>>> graph;
graph g;
vector<int> numbers;
vector<bool> visited;
map<pair<int, int>, int> m;
vector<int> ans;
void dfs(int node)
{
    visited[node] = true;

    for (auto &edge : g[node])
    {

        int neighbor = edge.first;
        int w = edge.second;

        if (!visited[neighbor])
        {
            //  cout << "node: " <<neighbor << " id:"<<numbers[neighbor] <<" weight:" <<edge.second << endl;

            if (w <= numbers[neighbor])
            {
                m[{numbers[node], numbers[neighbor]}] = 1;

                // ans[node]++;
                // pair<int, int> p = make_pair(node, neighbor);
                // m[p] = 1;
                cout << "node " << numbers[node] << " controls " << numbers[neighbor] << " w: "<<w <<  endl;
            }
            dfs(neighbor);
        }
    }
}
int main()
{

    int n = 0;
    cin >> n;

    g = graph(n + 1);
    numbers.assign(n + 1, 0);
    visited.assign(n + 1, false);
    ans.assign(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 1; i < n; i++)
    {
        int n1 = 0, w = 0;
        cin >> n1 >> w;
        g[n1].push_back({i + 1, w});
        // g[i+1].push_back({n1, w});
    }
    for (int i = 1; i < n + 1; i++)
    {
        visited.assign(n + 1, false);
        // cout << "node " << i << " id "<<numbers[i]<< " connects with" << endl;
        dfs(i);
        // cout << endl;
    }
    //int pair_num = 1;
    // for (auto it : m)
    // {
    //     cout << it.first.first << " " << it.first.second<< " " << endl;
    // }
    // cout << endl;
    // for (const auto &entry : m) {

    //     if (entry.second == 0) {
    //         cout << "0 ";
    //     }
    //     else{
    //         cout << entry.second << " ";

    //     }
    //     pair_num++;
    // }
    cout <<endl;
    for(auto it : m){
        cout << it.first.first <<" "<< it.first.second<< endl;
        // ans[it.first.first]++;
    }

    // for (int i = 1; i < n + 1; i++)
    // {
    //     cout << ans[i];
    //     if (i != n) cout << " ";
    // }
    //cout << endl;
}