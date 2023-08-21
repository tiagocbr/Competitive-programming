#include <bits/stdc++.h>
using namespace std;
int n, m, s;
const int maxn = 2e4 + 3;
const int maxl = 20;
const int maxx = 100000000;
typedef pair<int, int> pii;
vector<vector<pii>> viz(maxn, vector<pii>(0));
vector<pair<int, pii>> aresta(maxn);
vector<int> pai(maxn), peso(maxn);

void ini_uf()
{
    for (int i = 1; i <= n; i++)
    {
        pai[i] = i;
    }
}

int find(int x)
{
    if (pai[x] == x)
    {
        return x;
    }
    return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (peso[a] == peso[b])
    {
        pai[a] = b;
        peso[b]++;
        return;
    }
    if (peso[a] > peso[b])
    {
        pai[b] = a;
    }
    else
        pai[a] = b;
}

void create_mst()
{

    for (int i = 0; i < aresta.size(); i++)
    {
        int x = aresta[i].second.first;
        int y = aresta[i].second.second;
        int w = aresta[i].first;
        if (find(x) != find(y))
        {
            join(x, y);
            viz[x].push_back({w, y});
            viz[y].push_back({w, x});
        }
    }
}

vector<vector<int>> anc(maxn, vector<int>(maxl));
vector<vector<int>> minor(maxn, vector<int>(maxl));
vector<int> visitados(maxn);
vector<int> height(maxn);

void dfs(int x)
{
    visitados[x] = 1;
    for (int i = 0; i < viz[x].size(); i++)
    {
        int atual = viz[x][i].second;
        if (visitados[atual] == 0)
        {
            anc[atual][0] = x;
            minor[atual][0] = viz[x][i].first;
            height[atual] = height[x] + 1;
            dfs(atual);
        }
    }
}

void inic_lca()
{
    for (int i = 0; i <= n; i++)
    {
        anc[i][0] = 0;
        minor[i][0] = maxx;
        height[i] = -1;
    }
    height[1] = 0;
    dfs(1);
    for (int j = 1; j < maxl; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
            minor[i][j] = min(minor[i][j - 1], minor[anc[i][j - 1]][j - 1]);
        }
    }
}

int lca(int a, int b)
{
    int res = maxx;
    if (height[a] < height[b])
        swap(a, b);
    for (int i = maxl - 1; i >= 0; i--)
    {
        if (height[anc[a][i]] >= height[b])
        {
            res = min(res, minor[a][i]);
            a = anc[a][i];
        }
        if (height[a] == height[b])
        {
            break;
        }
    }
    if (a == b)
        return res;
    for (int i = maxl - 1; i >= 0; i--)
    {
        if (anc[a][i] != anc[b][i])
        {
            res = min(res, min(minor[b][i], minor[a][i]));
            a = anc[a][i];
            b = anc[b][i];
        }
        if (anc[a][0] == anc[b][0])
        {
            return min(res, min(minor[a][0], minor[b][0]));
        }
    }
}
int main()
{
    cin >> n >> m >> s;
    ini_uf();
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        aresta.push_back({w, {a, b}});
    }
    sort(aresta.rbegin(), aresta.rend());
    create_mst();
    inic_lca();
    for (int i = 0; i < s; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}