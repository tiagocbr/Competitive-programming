#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> in, out;

vector<int> dobra(const vector<int> &v, int i)
{
    int size = v.size();
    vector<int> res;
    int j = 0;
    while (i - (j + 1) >= 0 || i + j < size)
    {
        int soma = (i - j - 1 >= 0 ? v[i - j - 1] : 0) + (i + j < size ? v[i + j] : 0);
        res.push_back(soma);
        j++;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool solve(const vector<int> &vin, const vector<int> &vout)
{
    int size = vin.size();
    if (size == m)
    {
        bool ok2 = true;
        for (int i = 0; i < m; i++)
        {
            if (vin[i] != vout[i])
            {
                ok2 = false;
                break;
            }
        }
        if (ok2)
            return true;
        ok2 = true;
        for (int i = 0; i < m; i++)
        {
            if (vin[m - 1 - i] != vout[i])
            {
                ok2 = false;
                break;
            }
        }
        if (ok2)
            return true;
    }
    bool ok = false;
    for (int i = 1; i < size; i++)
    {
        vector<int> temp = dobra(vin, i);
        ok = solve(temp, vout);
        if (ok)
            return true;
    }
    return false;
}

int main()
{
    cin >> n;
    in.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    cin >> m;
    out.assign(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> out[i];
    }
    if (solve(in, out))
        cout << "S" << endl;
    else
        cout << "N" << endl;
}