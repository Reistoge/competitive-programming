    #include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/group/TY5qlgX1RN/contest/625831/problems
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
void print(vector<int> v, int s)
{
    for (int i = s; i < v.size(); i++)
    {

        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int t = 0;
    cin >> t;
    while (t)
    {

        int s = 0, n = 0;
        cin >> s >> n;

        graph g(s + 1);
        for (int i = 0; i < n; i++)
        {
            int n1 = 0, n2 = 0, w = 0;
            cin >> n1 >> n2 >> w;
            g[n1].push_back(make_pair(n2, w));
            g[n2].push_back(make_pair(n1, w));
        }
        int maxPath = -INT_MAX;
        int minPath = INT_MAX;
        int nextNode = 1; 
        for (int i = 1; i < s+1; i++)
        {

            vector<int> d(s + 1, INT_MAX);
            dijsktra(g, i, d, s + 1);
            print(d,1);
            // la soluci    on ahora es ir viajando desde 0 al 
            // numero más pequeño de esa fila, despues ir al index de ese numero
            // y de nuevo encontrar el valor pequeño de esa fila, determinar si el numero fue mayor o menor de los caminos encontrados
            //, asi hasta visitar a todos los nodos, no se debe volver a calcular dijsktra sobre un nodo el cual ya fue calculado.



        }
        cout << minPath + maxPath << endl;
        t--;
    }
}