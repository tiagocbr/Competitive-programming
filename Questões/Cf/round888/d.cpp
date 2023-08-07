#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ct = 0;
        bool ok = true;
        vector<long long> arr;
        vector<long long> v;
        arr.assign(n, 0);
        set<long long> perm;
        for (int i = 1; i <= n; i++)
        {
            perm.insert(i);
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
        }
        if (arr[0] > 2 * n - 1 || arr[0] <= 0)
        {
            cout << "no" << endl;
            continue;
        }
        if (arr[0] > n)
        {
            ct++;
            v.push_back(arr[0]);
        }
        else
        {
            perm.erase(arr[0]);
        }
        for (int i = 1; i < n - 1; i++)
        {
            long long dif = arr[i] - arr[i - 1];
            if (perm.find(dif) != perm.end())
            {
                perm.erase(dif);
            }
            else
            {
                ct++;
                if (ct > 1)
                {
                    break;
                }
                v.push_back(dif);
            }
        }

        if (ct > 1)
        {
            cout << "no" << endl;
            continue;
        }
        if (!v.empty())
        {
            long long dif = v[0];
            auto it = prev(perm.end());
            ok = true;
            while (it != perm.begin())
            {
                if (perm.find(dif - *it) != perm.end() && dif - *it != *it)
                {
                    int m = *it;
                    perm.erase(dif - m);
                    perm.erase(m);
                    ok = false;
                    break;
                }
                it = prev(it);
            }
            if (ok)
            {
                ct = 2;
            }
        }

        if (ct > 1)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
}