// clang-format off
#include<bits/stdc++.h>
#include <system_error>
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

bitset<30> occ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, k, m;
    cin >> t;
    string s, ans;
    while (t--)
    {
        cin >> n >> k >> m >> s;
        occ.reset();
        ans = "";
        for (char c : s)
        {
            occ[c - 'a'] = 1;
            if ((int)occ.count() == k)
            {
                ans += c;
                occ.reset();
                if (ssize(ans) == n)
                    break;
            }
        }
        if (ssize(ans) == n)
        {
            cout << "YES\n";
            continue;
        }
        for (int i = 0; i < k; i++)
        {
            if (!occ[i])
            {
                ans += (char)('a' + i);
                break;
            }
        }
        while (ssize(ans) < n)
            ans += 'a';
        cout << "NO\n" << ans << '\n';
    }

    return 0;
}
