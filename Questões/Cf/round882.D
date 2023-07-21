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
          int direita = intervalo[i].first;
          int esquerda = intervalo[i].second;
          if (ai.lower_bound(direita) == ai.end())
          {
               continue;
          }
          direita = *ai.lower_bound(direita);
          while (direita <= esquerda)
          {
               arr.push_back(direita);
               idx[direita] = arr.size() - 1;
               ai.erase(direita);
               if (ai.lower_bound(direita) == ai.end())
               {
                    break;
               }
               direita = *ai.lower_bound(direita);
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
          if (idx[x] == -1)
          {
               size += s[x] == '0';
               size -= s[x] == '1';
               s[x] = (s[x] == '0' ? '1' : '0');
               int temp = sizereal;
               sizereal = size <= arr2.size() ? size : arr2.size();
               if (sizereal != temp)
               {
                    if (sizereal > temp)
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
               continue;
          }
          int c = arr2[idx[x]];
          if (idx[x] <= sizereal - 1)
          {
               qtd += (c == 0);
               qtd -= (c == 1);
          }
          size += (c == 0);
          size -= (c == 1);
          int temp2 = sizereal;
          sizereal = size <= arr.size() ? size : arr.size();
          arr2[idx[x]] = !arr2[idx[x]];
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
