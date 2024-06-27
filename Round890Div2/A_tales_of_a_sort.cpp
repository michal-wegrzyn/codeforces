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

int a[57];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int n, v, m;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[n + 1] = INT_MAX / 2;
        for (v = n - 1; v > 0; v--)
        {
            if (a[v] > a[v + 1])
                break;
        }
        m = 0;
        for (int i = 1; i <= v; i++)
            m = max(m, a[i]);
        cout << m << '\n';
    }

    return 0;
}
