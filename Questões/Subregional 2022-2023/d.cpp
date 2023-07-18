#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 3;
int n, x, y;

int main()
{
    cin >> n >> x >> y;

    int menos = x & (-x);
    int res = 0;
    for (int i = 0; (1 << i) <= menos; i++)
    {
        if ((1 << i) == menos)
        {
            res = (n - 1 - i);
        }
    }
    cout << res << endl;
}