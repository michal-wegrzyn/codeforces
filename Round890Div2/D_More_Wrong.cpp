// clang-format off
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...);}(x),cerr<<'\n'
#else
#define debug(...) {}
#endif
// clang-format on

int rek(int pocz, int kon)
{
    if (pocz == kon - 1)
    {
        cout << "? " << pocz << " " << kon << endl;
        cout.flush();
        int c;
        cin >> c;
        if (c)
            return pocz;
        return kon;
    }
    if (pocz == kon)
        return pocz;
    int srodek = (pocz + kon) / 2;
    int jed = rek(pocz, srodek), dwa = rek(srodek + 1, kon);
    int a;
    if (jed + 1 != dwa)
    {
        cout << "? " << jed + 1 << " " << dwa << endl;
        cout.flush();
        cin >> a;
    }
    else
    {
        a = 0;
    }
    cout << "? " << jed << " " << dwa << endl;
    cout.flush();
    int b;
    cin >> b;
    if (a < 0 || b < 0)
        return -1;
    if (b - a == dwa - jed)
        return jed;
    return dwa;
}

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int k = rek(1, n);
        if (k == -1)
        {
            return 0;
        }
        cout << "! " << k << endl;
        cout.flush();
    }
    return 0;
}
