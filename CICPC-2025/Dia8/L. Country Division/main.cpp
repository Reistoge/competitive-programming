#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> used;
vector<int> comp;
vector<vector<int>> adj;
void dfs(int v)
{
    stack<int> st;
    st.push(v);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (!used[curr])
        {
            used[curr] = true;
            comp.push_back(curr);
            for (int i = adj[curr].size() - 1; i >= 0; i--)
            {
                st.push(adj[curr][i]);
            }
        }
    }
}

void find_comps()
{
    fill(used.begin(), used.end(), 0);
    for (int v = 1; v < n; ++v)
    {
        if (!used[v])
        {
            comp.clear();
            dfs(v);
            cout << "Component:";
            for (int u : comp)
                cout << ' ' << u;
            cout << endl;
        }
    }
}

int main()
{
    n = 0;
    cin >> n;
    used.assign(n, false);
    comp.assign(n, 0);
    adj.assign(n, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int n1 = 0, n2 = 0;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    int q = 0;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int r = 0, b = 0;
        cin >> r >> b;
        vector<int> rn(r);
        vector<int> bn(b);
        for (int j = 0; j < r; j++)
        {
            cin >> rn[j];
        }
        for (int j = 0; j < b; j++)
        {
            cin >> bn[j];
        }
        for (int j = 1; j < n-1; j++)
        {
            if(rn[j] != j && bn[j] != j){

                int temp = adj[j][1];
                cout << temp<< endl;
                adj[j].erase(adj[j].begin()+1);
                find_comps();
                adj[j].push_back(temp);
            }
        }
        
       
    }
    
    for (int j = 0; j < adj.size(); j++)
    {
        for (int i = 0; i < adj[j].size(); i++)
        {
            cout << "node " << j << " connects with " << " node: " << adj[j][i] << endl;
        }
    }

    return 0;
}