// clang-format off
#include<bits/stdc++.h>
#include <climits>
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

set<int> s;
map<int, int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, a, ans = 0;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            s.insert(-a);
        }
        a = 0;
        for (int i : s)
        {
            a++;
            m[i] = a;
        }
        s.insert(INT_MAX / 2);
        for (int i : s)
        {
            if (i == INT_MAX / 2)
                continue;
            a = *s.lower_bound(i - n + 1);
            if (a != INT_MAX / 2)
                ans = max(ans, m[i] - m[a] + 1);
        }
        cout << ans << '\n';
        s.clear();
        m.clear();
    }

    return 0;
}
