#include <bits/stdc++.h>
using namespace std;
int arr[10];

int main()
{
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        if (x == 9)
        {
            cout << 'F' << endl;
            return 0;
        }
    }
    cout << "S" << endl;
}