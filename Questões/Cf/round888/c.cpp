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
        vector<vector<int>> color(n + 1);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            int cor;
            cin >> cor;
            arr[i] = cor;
            color[cor].push_back(i);
        }
        int cor_ini = arr[0];
        int cor_fim = arr[n - 1];

        int pointer_ini = 0;
        int pointer_fim = 0;
        if (cor_ini == cor_fim && color[cor_ini].size() >= k)
        {
            cout << "yes" << endl;
            continue;
        }

        if (color[cor_ini].size() >= k && color[cor_fim].size() >= k)
        {
            auto it = lower_bound(color[cor_fim].begin(), color[cor_fim].end(), color[cor_ini][k - 1]);
            int p = it - color[cor_fim].begin();
            if (color[cor_fim].size() - p >= k)
            {
                cout << "yes" << endl;
                continue;
            }
        }
        cout << "no" << endl;
    }
}