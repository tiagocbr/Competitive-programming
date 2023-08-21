#include <bits/stdc++.h>
using namespace std;
int n, m, I;
int age[501];
vector<int> viz[501];
vector<int> visitados(501);
int mn = 200;
int kr[501], id[501];

void dfs(int x, int qry)
{
    visitados[x] = 1;
    if (id[x] != qry)
    {
        mn = min(mn, age[id[x]]);
    }
    for (int i = 0; i < viz[x].size(); i++)
    {
        int atual = viz[x][i];
        if (visitados[atual] == 0)
        {
            dfs(atual, qry);
        }
    }
}

int main()
{
    cin >> n >> m >> I;
    for (int i = 1; i <= n; i++)
    {
        kr[i] = i;
        id[i] = i;
        cin >> age[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        viz[y].push_back(x);
    }
    for (int i = 1; i <= I; i++)
    {
        char c;
        cin >> c;
        if (c == 'T')
        {
            int a, b;
            cin >> a >> b;
            int na = kr[a], nb = kr[b];
            kr[a] = nb;
            kr[b] = na;
            id[na] = b;
            id[nb] = a;
        }
        else
        {
            int e;
            cin >> e;
            visitados.assign(n + 1, 0);
            mn = 200;
            dfs(kr[e], e);
            if (mn == 200)
                cout << "*" << endl;
            else
                cout << mn << endl;
        }
    }
}