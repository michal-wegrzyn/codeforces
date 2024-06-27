#include <bits/stdc++.h>
#include <climits>
#include <ios>
using namespace std;

int dist(char a, char b)
{
    if (a >= b)
        swap(a, b);
    int r = b - a;
    if (r > 13)
        r = 26 - r;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cr, cb = INT_MAX;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n - 3; i++)
    {
        cr = 0;
        cr += dist(s[i], 'A');
        cr += dist(s[i + 1], 'C');
        cr += dist(s[i + 2], 'T');
        cr += dist(s[i + 3], 'G');
        cb = min(cb, cr);
    }
    cout << cb << '\n';
}
