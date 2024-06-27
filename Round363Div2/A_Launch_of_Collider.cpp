#include <bits/stdc++.h>
using namespace std;

string s;
int a[200007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            res = min(res, (a[i + 1] - a[i]) / 2);
        }
    }
    if (res == INT_MAX)
        cout << -1 << '\n';
    else
        cout << res << '\n';
}
