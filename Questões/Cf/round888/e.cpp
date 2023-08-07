#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
int n, k;
vector<int> price;
vector<vector<int>> viz;
vector<int> dp;

int dfs(int x)
{
    if (dp[x] != -1)
    {
        return dp[x];
    }
    int res = 0;
    for (int i = 0; i < viz[x].size(); i++)
    {
        int atual = viz[x][i];
        res += dfs(atual);
    }
    return dp[x] = viz[x].size() == 0 ? price[x] : min(price[x], res);
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        price.assign(n + 1, 0);
        dp.assign(n + 1, -1);
        viz.assign(n + 1, vector<int>(0));
        for (int i = 1; i <= n; i++)
        {
            cin >> price[i];
        }
        for (int i = 0; i < k; i++)
        {
            int p;
            cin >> p;
            price[p] = 0;
            dp[p] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int e;
                cin >> e;
                viz[i].push_back(e);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int x = dfs(i);
            cout << x << " ";
        }
        cout << endl;
    }
}