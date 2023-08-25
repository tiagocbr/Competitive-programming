#include <bits/stdc++.h>
using namespace std;
int n;
string s;

string add1(string p)
{
    char c = p[p.size() - 1];
    if (c < '9')
    {
        c++;
        p.pop_back();
        p.push_back(c);
        return p;
    }
    int pointer = p.size() - 1;
    while (p[pointer] == '9' && pointer >= 0)
    {
        p[pointer] = '0';
        pointer--;
    }
    if (pointer == -1)
    {
        p[0] = '1';
        for (int i = 1; i < p.size() - 1; i++)
        {
            p[i] = '0';
        }
        p.push_back('0');
    }
    else
        p[pointer]++;

    return p;
}

bool comp(string a, string b)
{
    int size_a = a.size();
    int size_b = b.size();
    if (size_a != size_b)
        return false;

    for (int i = 0; i < size_a; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    s.assign(n + 1, '0');
    bool ok;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ok = true;
        int pointer = 1;
        string atual = s.substr(1, i);
        while (pointer <= n && ok)
        {

            if (pointer + atual.size() > n + 1)
            {
                ok = false;
                break;
            }
            string compara = s.substr(pointer, atual.size());
            ok = comp(atual, compara);
            pointer += atual.size();
            atual = add1(atual);
        }
        if (ok)
        {
            cout << s.substr(1, i) << endl;
            return 0;
        }
    }
}