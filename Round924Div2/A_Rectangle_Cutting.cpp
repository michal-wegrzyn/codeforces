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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, a, b;
    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        if (a % 2 == 1 && b % 2 == 1)
        {
            cout << "No\n";
            continue;
        }
        if (a % 2 == 0 && b % 2 == 0)
        {
            cout << "Yes\n";
            continue;
        }
        if (b % 2 == 0)
            swap(a, b);
        cout << (a / 2 == b ? "No\n" : "Yes\n");
    }

    return 0;
}
