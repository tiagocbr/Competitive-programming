#include <bits/stdc++.h>
using namespace std;
int quadrado[50][50];
int media_l[50];
int media_c[50];

int main()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << "-1";
        return 0;
    }
    int soma = 0;
    for (int j = 1; j <= n - 1; j++)
    {
        quadrado[1][j] = j;
        soma += quadrado[1][j];
    }
    quadrado[1][n] = n * quadrado[1][n - 1] - soma;

    for (int i = 2; i <= n - 1; i++)
    {
        soma = 0;
        quadrado[i][1] = quadrado[i - 1][n] + 1;
        soma += quadrado[i][1];
        for (int j = 2; j <= n - 1; j++)
        {
            quadrado[i][j] = quadrado[i][j - 1] + 1;
            soma += quadrado[i][j];
        }
        quadrado[i][n] = n * quadrado[i][n - 1] - soma;
    }
    for (int i = 1; i <= n; i++)
    {
        soma = 0;
        for (int j = 1; j <= n - 1; j++)
        {
            soma += quadrado[j][i];
        }
        quadrado[n][i] = n * quadrado[n - 1][i] - soma;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << quadrado[i][j] << " ";
            media_l[i] += quadrado[i][j];
        }

        cout << endl;
    }
}
