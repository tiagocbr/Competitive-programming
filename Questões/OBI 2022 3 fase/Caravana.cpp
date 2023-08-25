#include <bits/stdc++.h>
using namespace std;
int camelo[1001];

int main()
{
    int n;
    cin >> n;
    int media = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> camelo[i];
        media += camelo[i];
    }
    media /= n;
    for (int i = 0; i < n; i++)
    {
        cout << media - camelo[i] << endl;
    }
}