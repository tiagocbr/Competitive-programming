#include <bits/stdc++.h>
using namespace std;

int mat[301][301];
int l, c;

void change(int a, int b)
{
    for (int i = 1; i <= l; i++)
    {
        int x = mat[i][b];
        mat[i][b] = mat[i][a];
        mat[i][a] = x;
    }
}

void change_col(int a, int b)
{
    for (int i = 1; i <= c; i++)
    {
        int x = mat[a][i];
        mat[a][i] = mat[b][i];
        mat[b][i] = x;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> l >> c;
    bool ok = true;
    int linha = 0;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (mat[i][j] == 1)
            {
                linha = i;
            }
        }
    }

    for (int i = 1; i <= l; i++)
    {
        int mn = 1000000000;
        int mx = 0;
        for (int j = 1; j <= c; j++)
        {
            mn = min(mn, mat[i][j]);
            mx = max(mx, mat[i][j]);
        }
        if (mx - mn > c - 1)
        {
            ok = false;
        }
    }

    if (ok == false)
    {
        cout << '*' << endl;
        return 0;
    }

    int cnt = 0;
    while (1)
    {
        bool ok2 = true;
        for (int i = 1; i <= c; i++)
        {
            if (mat[linha][i] != i)
            {
                int x = mat[linha][i];
                change(i, x);
                cnt++;
                ok2 = false;
                break;
            }
        }
        if (ok2)
            break;
    }
    for (int i = 1; i <= l; i++)
    {
        if (mat[i][1] % c != 1)
        {
            ok = false;
        }
    }
    if (c == 1)
        ok = true;
    if (ok == false)
    {
        cout << '*' << endl;
        return 0;
    }
    while (1)
    {
        bool ok2 = true;
        for (int i = 1; i <= l; i++)
        {
            if (mat[i][1] != (i - 1) * c + 1)
            {
                int x = ((mat[i][1] - 1) / c) + 1;
                change_col(x, i);
                cnt++;
                ok2 = false;
                break;
            }
        }
        if (ok2)
            break;
    }
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (mat[i][j] != j + ((i - 1) * c))
                ok = false;
        }
    }
    if (ok == false)
    {
        cout << '*' << endl;
    }
    else
        cout << cnt << endl;