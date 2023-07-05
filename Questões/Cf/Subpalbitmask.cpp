#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 8) + 20;
long long qtd[maxn];
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    qtd[0] = 1;
    int mask = 0;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        mask ^= (1 << (s[i] - 'a'));
        res += qtd[mask];

        for (int j = 0; j < 8; j++)
        {
            res += qtd[mask ^ (1 << j)];
        }
        qtd[mask]++;
    }
    cout << res;
}