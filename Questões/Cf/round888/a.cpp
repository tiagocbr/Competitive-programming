#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, H;
        cin >> n >> m >> k >> H;
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;
            int dif = abs(h - H);
            if (dif % k == 0 && dif <= k * (m - 1) && dif != 0)
            {
                ct++;
            }
        }
        cout << ct << endl;
    }
}