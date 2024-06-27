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

set<int> d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, x, a;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        n--;
        x--;
        d.clear();
        a = n - x;
        for (int i = 1; i * i <= a; i++)
        {
            if (a % i)
                continue;
            if (i % 2 == 0 && i > x * 2 - 2 && i <= n * 2 - 2)
                d.insert(i);
            if ((a / i) % 2 == 0 && (a / i) > x * 2 - 2 && (a / i) <= n * 2 - 2)
                d.insert(a / i);
        }
        a = n + x;
        for (int i = 1; i * i <= a; i++)
        {
            if (a % i)
                continue;
            if (i % 2 == 0 && i > x * 2 - 2 && i <= n * 2 - 2)
                d.insert(i);
            if ((a / i) % 2 == 0 && (a / i) > x * 2 - 2 && (a / i) <= n * 2 - 2)
                d.insert(a / i);
        }
        cout << ssize(d) << '\n';
    }

    return 0;
}
