#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> arr(n + 1);
        map<long long, set<long long>> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            m[arr[i]].insert(i);
        }
        sort(next(arr.begin()), arr.end());
        long long mn = pow(2, 30);
        pair<int, int> p;
        long long numb;
        for (int i = 1; i < n; i++)
        {
            long long value = arr[i] ^ arr[i + 1];
            mn = min(mn, value);
        }
        for (int i = 1; i < n; i++)
        {
            long long value = arr[i] ^ arr[i + 1];
            if (value == mn)
            {
                auto it1 = m[arr[i]].begin();
                auto it2 = prev(m[arr[i + 1]].end());
                p = {*it1, *it2};
                numb = arr[i];
            }
        }
        long long x = 0;
        for (int i = 0; i < k; i++)
        {
            if ((numb & (1 << i)) == 0)
            {
                x += (1 << i);
            }
        }
        cout << p.first << " " << p.second << " " << x << endl;
    }
}