#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, c, t1, t2;
vector<int> arr;
int dp[2 * maxn][2 * maxn];

int solve(int x, int fim)
{
    if (dp[x][fim] != -1)
    {
        return dp[x][fim];
    }
    auto up1 = upper_bound(arr.begin(), arr.end(), arr[x] + t1);
    auto up2 = upper_bound(arr.begin(), arr.end(), arr[x] + t2);
    int pos1 = up1 - arr.begin();
    int pos2 = up2 - arr.begin();
    return dp[x][fim] = min(pos1 > fim ? t1 : t1 + solve(pos1, fim), pos2 > fim ? t2 : t2 + solve(pos2, fim));
}

int main()
{
    cin >> n >> c >> t1 >> t2;
    arr.assign((2 * n), 0);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n; i < 2 * n; i++)
    {
        arr[i] = c + arr[i - n];
    }
    int mn = 1000000000;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, solve(i, n - 1 + i));
    }
    cout << mn << endl;
}