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

#define MOD 1000000007LL

ll factorial[4003];
ll inv_factorial[4003];

ll nCk(int n, int k)
{
    return (factorial[n] * inv_factorial[k] % MOD) * inv_factorial[n - k] % MOD;
}

ll f(int n, int m, int k)
{
    if (k >= min(n, m))
        return nCk(n + m, n);
    else
        return nCk(n + m, k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    factorial[0] = 1;
    for (int i = 1; i <= 4000; i++)
        factorial[i] = factorial[i - 1] * i % MOD;

    ll e = MOD - 2;
    ll fact = factorial[4000];
    ll inv = 1;
    while (e)
    {
        if (e & 1)
        {
            inv *= fact;
            inv %= MOD;
        }
        fact *= fact;
        fact %= MOD;
        e /= 2;
    }

    inv_factorial[4000] = inv;
    for (int i = 4000; i; i--)
        inv_factorial[i - 1] = inv_factorial[i] * i % MOD;

    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        cout << (f(n, m, k) - f(n, m, k - 1) % MOD + MOD) % MOD << '\n';
    }

    return 0;
}
