#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 3;
int n;
pair<int, int> john, mary;
int card[10];
int idx[14];

int main()
{
    for (int i = 1; i < 14; i++)
    {
        idx[i] = 4;
    }
    cin >> n;
    cin >> john.first >> john.second >> mary.first >> mary.second;
    idx[john.first]--;
    idx[john.second]--;
    idx[mary.first]--;
    idx[mary.second]--;
    int com = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
        com += min(card[i], 10);
        idx[card[i]]--;
    }
    int marysum = com + min(10, mary.first) + min(10, mary.second);
    int johnsum = com + min(10, john.first) + min(10, john.second);
    int i = 1;
    while (i < 14)
    {
        if (idx[i] > 0)
        {
            if (min(i, 10) + marysum == 23 || ((min(10, i) + johnsum > 23) && (min(i, 10) + marysum <= 23)))
            {
                cout << i << endl;
                return 0;
            }
        }
        i++;
    }
    cout << -1 << endl;
}