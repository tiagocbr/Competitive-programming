#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
long long front[maxn];
long long back[maxn];
long long n, l, k;
typedef pair<long long, long long> pii;
vector<pii> pref, suf, arr;
vector<bool> dentro(10000000);

int main()
{
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> front[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> back[i];
    }
    cin >> k >> l;
    for (long long i = 0; i < k; i++)
    {
        pref.push_back({front[i], back[i]});
    }
    for (long long i = 0; i < k; i++)
    {
        suf.push_back({front[n - 1 - i], back[n - 1 - i]});
    }
    for (long long i = 0; i < k; i++)
    {
        arr.push_back(pref[k - 1 - i]);
    }
    for (long long i = 0; i < k; i++)
    {
        arr.push_back(suf[i]);
    }
    set<pii> inL;
    set<pii> outL;
    long long valor = 0, mx = 0;
    for (long long i = 0; i < k + 1; i++)
    {
        if (i == 0)
        {
            vector<pii> arr2(k);

            for (long long j = 0; j < k; j++)
            {
                valor += arr[j].first;
                arr2[j] = {arr[j].second, j};
                outL.insert(arr2[j]);
            }
            sort(arr2.rbegin(), arr2.rend());
            for (long long j = 0; j < l; j++)
            {
                valor += arr2[j].first;
                dentro[arr2[j].second] = true;
                inL.insert(arr2[j]);
                outL.erase(arr2[j]);
            }
        }
        else
        {
            outL.insert({arr[i + k - 1].second, i + k - 1});
            bool ok = dentro[i - 1];
            if (ok)
            {
                inL.erase({arr[i - 1].second, i - 1});
            }
            else
            {
                outL.erase({arr[i - 1].second, i - 1});
            }
            set<pii>::iterator it1, it2;

            it1 = prev(outL.end());
            if (!inL.empty())
                it2 = inL.begin();
            if (!inL.empty())
            {
                valor += arr[i + k - 1].first - arr[i - 1].first - (ok ? arr[i - 1].second : 0) + (ok ? (*it1).first : (max((*it1).first, (*it2).first) == (*it1).first ? (*it1).first - (*it2).first : 0));
                if (ok)
                {
                    dentro[(*it1).second] = true;
                    inL.insert(*it1);
                    outL.erase(it1);
                }
                else
                {
                    if (max((*it1).first, (*it2).first) == (*it1).first)
                    {
                        dentro[(*it1).second] = true;
                        dentro[(*it2).second] = false;
                        pii guardait1 = *it1;
                        pii guardait2 = *it2;
                        inL.insert(guardait1);
                        outL.insert(guardait2);
                        outL.erase(guardait1);
                        inL.erase(guardait2);
                    }
                }
            }
            else
            {
                valor += arr[i + k - 1].first - arr[i - 1].first - arr[i - 1].second + (*it1).first;
                dentro[(*it1).second] = true;
                inL.insert(*it1);
                outL.erase(it1);
            }
            dentro[i - 1] = false;
        }
        mx = max(mx, valor);
    }
    cout << mx;
}