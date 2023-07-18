#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 3;
vector<int> h;
set<int> idx[maxn];
vector<int> estourado(maxn);
int n;
int res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.push_back(x);
        idx[x].insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (!estourado[i])
        {
            res++;
            estourado[i] = 1;
            int val = h[i];
            set<int>::iterator it2 = idx[val].begin();
            while (1)
            {
                int x = *it2;
                idx[val].erase(x);
                if (val == 1)
                    break;
                if (idx[val - 1].size() > 0)
                {
                    it2 = idx[val - 1].lower_bound(x);
                    if (it2 != idx[val - 1].end())
                    {
                        estourado[*it2] = 1;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
                val--;
            }
        }
    }
    cout << res;
}
