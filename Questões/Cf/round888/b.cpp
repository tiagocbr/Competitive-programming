#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> arr1;
        vector<int> arr2;
        vector<int> position(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                arr2.push_back(arr[i]);
                position[i] = 2;
            }
            else
            {
                arr1.push_back(arr[i]);
                position[i] = 1;
            }
        }
        sort(arr2.begin(), arr2.end());
        sort(arr1.begin(), arr1.end());
        int pointer2 = 0, pointer1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (position[i] == 2)
            {
                arr[i] = arr2[pointer2];
                pointer2++;
            }
            else
            {
                arr[i] = arr1[pointer1];
                pointer1++;
            }
        }
        bool ok = true;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                ok = false;
            }
        }
        if (ok)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}