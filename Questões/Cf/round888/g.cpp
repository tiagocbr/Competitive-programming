#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<long long> pai;
vector<long long> peso;
vector<long long> height;
vector<pair<long long, long long>> edge;
struct querie
{
    long long a, b, e;
};
vector<querie> queries, queries2;
map<pair<pair<long long, long long>, long long>, bool> mp;

long long find(long long x)
{
    if (pai[x] == x)
        return x;

    return pai[x] = find(pai[x]);
}

void join(long long a, long long b)
{
    a = find(a);
    b = find(b);
    if (peso[a] > peso[b])
    {
        pai[b] = a;
        return;
    }
    if (peso[b] > peso[a])
    {
        pai[a] = b;
        return;
    }
    if (peso[b] == peso[a])
    {
        pai[a] = b;
        peso[b]++;
        return;
    }
}

void build(long long n)
{
    pai.assign(n + 1, 0);
    for (long long i = 0; i < n + 1; i++)
    {
        pai[i] = i;
    }
    peso.assign(n + 1, 0);
}

bool compara_querie(querie a, querie b)
{
    return height[a.a] + a.e < height[b.a] + b.e;
}

bool compara_edge(pair<long long, long long> a, pair<long long, long long> b)
{
    return max(height[a.first], height[a.second]) < max(height[b.first], height[b.second]);
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        height.assign(n, 0);
        for (long long i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        edge.clear();
        for (long long i = 0; i < m; i++)
        {
            long long x, y;
            cin >> x >> y;
            x--;
            y--;
            edge.push_back({x, y});
        }
        long long q;
        cin >> q;
        queries.clear();
        queries2.clear();
        for (long long i = 0; i < q; i++)
        {
            querie x;
            cin >> x.a >> x.b >> x.e;
            x.a--;
            x.b--;
            queries.push_back(x);
            queries2.push_back(x);
        }
        sort(queries.begin(), queries.end(), compara_querie);
        sort(edge.begin(), edge.end(), compara_edge);
        mp.clear();
        long long pointer = 0;
        build(n);
        for (long long i = 0; i < q; i++)
        {
            querie atual = queries[i];
            long long valor = height[atual.a] + atual.e;
            while (pointer < edge.size() && max(height[edge[pointer].first], height[edge[pointer].second]) <= valor)
            {
                join(edge[pointer].first, edge[pointer].second);
                pointer++;
            }
            if (find(atual.a) == find(atual.b))
            {
                mp[{{atual.a, atual.b}, atual.e}] = true;
            }
            else
            {
                mp[{{atual.a, atual.b}, atual.e}] = false;
            }
        }
        for (long long i = 0; i < q; i++)
        {
            querie atual = queries2[i];
            if (mp[{{atual.a, atual.b}, atual.e}])
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }
}