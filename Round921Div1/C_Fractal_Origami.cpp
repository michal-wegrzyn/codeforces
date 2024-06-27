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

#define MOD 999999893LL

ll pow2[33];

ll get_inverse(ll num)
{
    int e = MOD - 2;
    ll ans = 1;
    while (e)
    {
        if (e & 1)
        {
            ans *= num;
            ans %= MOD;
        }
        num *= num;
        num %= MOD;
        e /= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pow2[0] = 1;
    for (int i = 1; i <= 30; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    ll a, b, p, q;
    int t, n, e;
    cin >> t;
    while (t--)
    {
        a = 1;
        b = 1;
        cin >> n;
        e = (n - 1) / 2 + 1;
        for (int i = 1; i <= 30; i++)
        {
            if (e & 1)
            {
                b *= pow2[i];
                b %= MOD;
            }
            e /= 2;
        }
        b += MOD - 2;
        b %= MOD;
        if (n % 2 == 0)
            a = (b * 2 + 2) % MOD;
        else
            a = b;
        p = a * 2 % MOD;
        q = (b + 2) * (b + 2) * 2 - a * a;
        q %= MOD;
        q += MOD;
        q %= MOD;
        cout << p * get_inverse(q) % MOD << '\n';
    }

    return 0;
}
