#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<vector<int>> viz(maxn);
vector<unordered_set<int>> adj(maxn);
vector<int> visitados;

void dfs(int x, int vertice, const unordered_set<int> &adj)
{
    visitados[x] = vertice;

    for (int i = 0; i < viz[x].size(); i++)
    {
        int atual = viz[x][i];
        if (visitados[atual] != vertice)
        {
            if (adj.find(atual) == adj.end())
            {
                cout << vertice << " " << atual << endl;
                exit(0);
            }
            dfs(atual, vertice, adj);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    visitados.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        viz[a].push_back(b);
        adj[a].insert(b);
    }

    for (int i = 1; i <= n; i++)
    {
        dfs(i, i, adj[i]);
    }
    cout << -1 << endl;
}