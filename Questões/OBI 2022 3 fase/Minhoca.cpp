#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> viz(300010, vector<int>(0));
vector<int> visitados;
int radar;

pair<int, int> dfs(int x, int r)
{
    visitados[x] = r;
    pair<int, int> res = {100000000, 0};

    for (int i = 0; i < viz[x].size(); i++)
    {
        int atual = viz[x][i];
        if (visitados[atual] != r)
        {
            pair<int, int> prox = dfs(atual, r);
            res.first = min(res.first, prox.first + 1);
            res.second = max(res.second, prox.second + 1);
        }
    }
    if (res.first + res.second <= r)
    {
        res.second = -1;
        return res;
    }
    if (res.second == r)
    {
        res.second = -1;
        res.first = 0;
        radar++;
        return res;
    }
    return res;
}

int check(int r)
{
    radar = 0;

    pair<int, int> ans = dfs(1, r);
    if (ans.second != -1)
        radar++;

    return radar;
}

int bb()
{
    int ini = 1;
    int fim = n / k;
    int res = -1;

    while (ini <= fim)
    {
        int meio = (ini + fim) / 2;
        int r = check(meio);
        if (r <= k)
        {
            fim = meio - 1;
            res = meio;
        }
        else
        {
            ini = meio + 1;
        }
    }
    return res;
}

int main()
{
    cin >> n >> k;
    visitados.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        viz[a].push_back(b);
        viz[b].push_back(a);
    }
    int res = bb();
    cout << res << endl;
}