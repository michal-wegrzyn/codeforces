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

ll a[1007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    ll n, k, k2, mx, best_mx, cnt, req;
    while (t--)
    {
        best_mx = -1;
        cin >> n >> k;
        mx = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int st = 1; st <= n; st++)
        {
            cnt = 1;
            mx = a[st];
            req = mx;
            k2 = k;
            for (int en = st + 1; en <= n; en++)
            {
                req--;
                if (a[en] <= req)
                {
                    k2 -= req - a[en];
                    if (k2 < 0)
                        break;
                }
                else
                {
                    if (k2 - (en - st) * (a[en] - req) >= 0)
                    {
                        k2 -= (en - st) * (a[en] - req);
                        mx += a[en] - req;
                        req = a[en];
                    }
                    else
                    {
                        mx += k2 / (en - st);
                        break;
                    }
                }
            }
            best_mx = max(best_mx, mx);
        }
        cout << best_mx << '\n';
    }

    return 0;
}
