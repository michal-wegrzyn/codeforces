#include <bits/stdc++.h>
using namespace std;

bitset<100> v;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size())
    {
        cout << "No\n";
        return 0;
    }
    v['a'] = 1;
    v['e'] = 1;
    v['u'] = 1;
    v['i'] = 1;
    v['o'] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (v[a[i]] ^ v[b[i]])
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
