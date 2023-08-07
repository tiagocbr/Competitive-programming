#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
pair<int, int> intervalo[maxn];
int pref[maxn];
int idx[maxn];
int buracos[maxn];
vector<int> arr;

int main()
{
     memset(idx, -1, sizeof(idx));
     int n, m, q;
     cin >> n >> m >> q;
     string s;
     cin >> s;
     for (int i = 0; i < m; i++)
     {
          cin >> intervalo[i].first >> intervalo[i].second;
          intervalo[i].first--;
          intervalo[i].second--;
     }
     set<int> ai;
     for (int i = 0; i < n; i++)
          ai.insert(i);

     for (int i = 0; i < m; i++)
     {
          int esquerda = intervalo[i].first;
          int direita = intervalo[i].second;
          auto it = ai.lower_bound(esquerda);
          while (it != ai.end() && *it <= direita)
          {
               arr.push_back(*it);
               idx[*it] = arr.size() - 1;
               int guard = *it;
               it++;
               ai.erase(guard);
          }
     }
     int sobra = 0;
     for (auto it = ai.begin(); it != ai.end(); it++)
     {
          sobra += s[*it] - '0';
     }
     vector<int> arr2;
     int sum = 0;
     for (int i = 0; i < arr.size(); i++)
     {
          arr2.push_back(s[arr[i]] - '0');
          sum += arr2[i];
          pref[i] = sum;
     }
     int size = pref[arr2.size() - 1] + sobra;
     int qtd = size <= arr2.size() ? pref[size - 1] : pref[arr2.size() - 1];
     int sizereal = size <= arr2.size() ? size : arr2.size();
     for (int i = 0; i < q; i++)
     {
          int x;
          cin >> x;
          x--;
          int c = idx[x] == -1 ? s[x] - '0' : arr2[idx[x]];
          if (idx[x] != -1 && idx[x] <= sizereal - 1)
          {
               qtd += (c == 0);
               qtd -= (c == 1);
          }
          size += (c == 0);
          size -= (c == 1);
          int temp2 = sizereal;
          sizereal = size <= arr.size() ? size : arr.size();
          if (idx[x] != -1)
               arr2[idx[x]] = !arr2[idx[x]];
          else
               s[x] = s[x] == '0' ? '1' : '0';
          if (sizereal != temp2)
          {
               if (sizereal > temp2)
               {
                    if (arr2[sizereal - 1] == 1)
                    {
                         qtd++;
                    }
               }
               else
               {
                    if (arr2[sizereal] == 1)
                    {
                         qtd--;
                    }
               }
          }
          cout << sizereal - qtd << endl;
     }
}
