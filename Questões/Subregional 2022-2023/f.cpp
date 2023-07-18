#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 3;
int n, c;
vector<string> arr;
map<string, int> mp;
int p[maxn];

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
        int pos;
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == '*')
            {
                pos = j;
            }
        }

        for (char c = 'a'; c <= 'z'; c++)
        {
            arr[i][pos] = c;
            mp[arr[i]]++;
        }
        arr[i][pos] = '*';
        p[i] = pos;
    }
    int mx = 0;
    string ans;
    for (int i = 0; i < n; i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            arr[i][p[i]] = c;
            if (mp[arr[i]] > mx)
            {
                mx = mp[arr[i]];
                ans = arr[i];
            }
            else if (mp[arr[i]] == mx)
            {
                if (ans > arr[i])
                {
                    ans = arr[i];
                }
            }
        }
    }
    cout << ans << " " << mx;
}