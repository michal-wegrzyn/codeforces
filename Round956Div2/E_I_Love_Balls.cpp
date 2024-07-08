// clang-format off
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<typename T,typename = typename enable_if<!is_same<T,string>::value>::type>
auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...);}(x),cerr<<'\n'
#else
#define debug(...) {}
#endif
// clang-format on

#define MOD 1000000007

ll inverse(ll num)
{
    int e = MOD - 2;
    ll res = 1;
    while (e)
    {
        if (e & 1)
        {
            res *= num;
            res %= MOD;
        }
        e /= 2;
        num *= num;
        num %= MOD;
    }
    return res;
}

inline ll frac(ll a, ll b)
{
    return (a % MOD) * inverse(b) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, k;
    ll a, b, ans1, ans2, sum1 = 0LL, sum2 = 0LL;

    cin >> t;
    while (t--)
    {
        sum1 = 0;
        sum2 = 0;
        cin >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> a;
            sum1 += a;
        }

        for (int i = k; i < n; i++)
        {
            cin >> b;
            sum2 += b;
        }

        a = (n - k + 1) / 2;
        b = (n - k) / 2;
        ans1 = frac(sum2 * a, n - k);
        ans2 = frac(sum2 * b, n - k);

        a = (n - k + 2) / 2;
        b = (n - k + 1) / 2;

        ans1 += frac(sum1 * a, n - k + 1);
        ans2 += frac(sum1 * b, n - k + 1);

        ans1 %= MOD;
        ans2 %= MOD;

        cout << ans1 << ' ' << ans2 << '\n';
    }

    return 0;
}
