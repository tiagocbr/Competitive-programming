//A questao da um vetor e pede o valor K que maximiza a soma total do vetor.A soma de um prefixo nao pode cair abaixo de K,uma vez que ela
//Chega a um valor maior que K, se ela for cair pra um valor menor do que K ,ela só cai até K.A questao pede o K que maximiza a soma total
// -1e9<=arr[i]<=1e9     -1e18<=k<=1e18
//Um valor é um possivel valor se ele for o prefixo anterior de um elemento negativo do array
//Usei uma ideia pra armazenar a quantidade numerica que um  possivel valor K impede a soma de cair
//Nessa ideia, pra achar essa quantidade eu uso DP e acho a quantidade com base no possivel valor posterior
//dessa forma eu so preciso percorrer o vetor 1 vez
//Após computar todas as dp,pego a maior dela e imprimo o index do possivel valor relativo a essa dp

#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 5;
long long n;
long long arr[maxn];
long long pre[maxn];
vector<long long> possiveis;
vector<long long> idx;
vector<long long> dp(maxn);

long long solve(long long x)
{
     if (x == possiveis.size() - 1)
     {
          return dp[x] = arr[idx[x] + 1];
     }
     long long y = solve(x + 1) + pre[idx[x + 1]] - pre[idx[x] + 1];
     if (y < 0)
          return dp[x] = arr[idx[x] + 1] + y;
     return dp[x] = arr[idx[x] + 1];
}

int main()
{
     long long t;
     cin >> t;
     while (t--)
     {
          cin >> n;
          long long sum = 0;
          possiveis.clear();
          idx.clear();
          for (long long i = 1; i <= n; i++)
          {
               cin >> arr[i];
               if (arr[i] < 0)
               {
                    possiveis.push_back(sum);
                    idx.push_back(i - 1);
               }
               sum += arr[i];
               pre[i] = sum;
          }
          if (possiveis.size() == 0)
          {
               cout << 0 << endl;
               continue;
          }
          dp.assign(possiveis.size() + 3, 1);
          solve(0);
          long long mx = 0;
          long long index;
          for (long long i = 0; i < possiveis.size(); i++)
          {
               mx = max(mx, abs(dp[i]));
               if (mx == abs(dp[i]))
               {
                    index = i;
               }
          }
          cout << possiveis[index] << endl;
     }
}
