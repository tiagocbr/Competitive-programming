#include <bits/stdc++.h>
using namespace std;
int n, cnt, res;
string s;
int main()
{
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            cnt++;
            if (i == n - 1)
            {
                if (cnt >= 2)
                {
                    res += cnt;
                }
            }
        }
        else
        {
            if (cnt >= 2)
            {
                res += cnt;
            }
            cnt = 0;
        }
    }
    cout << res;
}