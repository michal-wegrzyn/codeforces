// clang-format off
#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...);}(x),cerr<<'\n'
#else
#define debug(...) {}
#endif
// clang-format on

ll cnt_poss(ll t, ll m)
{
    if (t < m)
        return 0;
    return (t - m + 1) * (t - m + 2) / 2;
}

int a[200007];

ll solve()
{
    ll n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = INT_MAX;
    ll res = 0;
    int st = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i] <= q && st == -1)
            st = i;
        if (a[i] > q && st != -1)
        {
            res += cnt_poss(i - st, k);
            st = -1;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';

    return 0;
}

