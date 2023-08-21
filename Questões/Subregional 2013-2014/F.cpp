#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> pref;

bool bb(int ini, int fim, int val)
{

    while (ini <= fim)
    {
        int meio = (ini + fim) / 2;
        if (pref[meio] == val)
        {
            return true;
        }
        if (pref[meio] < val)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return false;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(2 * n + 1);
    pref.assign(2 * n + 1, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        pref[i] = sum;
    }
    int sum2 = sum;
    for (int i = n + 1; i <= 2 * n; i++)
    {
        arr[i] = arr[i - n];
        sum2 += arr[i];
        pref[i] = sum2;
    }
    int cnt = 0;
    if (sum % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int ini = i, fim = i + n - 1;
        int valor1 = (sum / 3) + pref[i - 1];
        int valor2 = (2 * sum / 3) + pref[i - 1];
        if (bb(ini, fim, valor1) && bb(ini, fim, valor2))
        {
            cnt++;
        }
    }
    cout << cnt / 3 << endl;
}