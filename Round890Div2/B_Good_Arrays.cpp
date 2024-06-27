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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    ll n, a, cnt1, sum;
    while (t--)
    {
        cin >> n;
        sum = 0;
        cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a == 1)
                cnt1++;
            sum += a - 1;
        }
        if (sum >= cnt1 && n != 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
