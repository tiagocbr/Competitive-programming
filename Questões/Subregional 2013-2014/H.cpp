#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000;

int n, k, l;

struct matrix
{

    int a11, a12, a21, a22;

    matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        this->a11 = a % MOD;
        this->a12 = b % MOD;
        this->a21 = c % MOD;
        this->a22 = d % MOD;
    }

    matrix operator*(const matrix &m)
    {
        matrix res;
        res.a11 = ((a11 * m.a11) % MOD + (a12 * m.a21) % MOD) % MOD;
        res.a12 = ((a11 * m.a12) % MOD + (a12 * m.a22) % MOD) % MOD;
        res.a21 = ((a21 * m.a11) % MOD + (a22 * m.a21) % MOD) % MOD;
        res.a22 = ((a21 * m.a12) % MOD + (a22 * m.a22) % MOD) % MOD;
        return res;
    }
};

matrix exp(matrix A, int e)
{

    matrix res = matrix(1, 0, 0, 1);
    while (e > 0)
    {
        if (e & 1)
            res = res * A;

        A = A * A;
        e >>= 1;
    }
    return res;
}

int32_t main()
{
    cin >> n >> k >> l;
    n = n / 5;
    matrix A = matrix(k, l, 1, 0);
    matrix R = exp(A, n);
    int resp = R.a11;
    vector<int> v;
    for (int i = 0; i < 6; i++)
    {
        v.push_back(resp % 10);
        resp /= 10;
    }
    for (int i = 5; i >= 0; i--)
    {
        cout << v[i];
    }
    cout << endl;
}