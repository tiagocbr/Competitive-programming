// Questao que da uma matriz com dimensao 10^9 e colunas que serao molhadas pela chuva tem que achar o numero de quadrados molhados

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
map<int, int> pref;
vector<int> col;
struct square
{
     pair<int, int> baixo;
     pair<int, int> cima;
};
square ret[maxn];

int main()
{
     int n, m;
     cin >> n >> m;
     long long remain = 0;
     for (int i = 1; i <= n; i++)
     {
          long long a, b, c, d;
          cin >> a >> b >> c >> d;
          ret[i].baixo = {a, b};
          ret[i].cima = {c, d};
          remain += (d - b + 1) * (c - a + 1);
     }
     for (int i = 1; i <= m; i++)
     {
          int x;
          cin >> x;
          col.push_back(x);
     }
     sort(col.begin(), col.end());
     pref[col[0]] = 1;
     for (int i = 1; i < col.size(); i++)
     {
          pref[col[i]] = 1 + pref[col[i - 1]];
     }

     for (int i = 1; i <= n; i++)
     {
          vector<int>::iterator it1 = prev(upper_bound(col.begin(), col.end(), ret[i].cima.second));
          vector<int>::iterator it2 = prev(upper_bound(col.begin(), col.end(), ret[i].baixo.second - 1));
          long long h = ret[i].cima.first - ret[i].baixo.first + 1;
          long long n_col = pref[*it1] - pref[*it2];
          remain -= h * n_col;
     }
     cout << remain;
}
