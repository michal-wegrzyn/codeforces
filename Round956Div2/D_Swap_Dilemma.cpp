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

map<int, int> ind_a;
int a[100007];
int b[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, parity, x, pos;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            a[i] = x;
            ind_a[x] = i;
        }
        for (int i = 1; i <= n; i++)
            cin >> b[i];

        parity = 0;

        for (int i = 1; i <= n; i++)
        {
            pos = ind_a[b[i]];
            if (pos == 0)
            {
                parity = 1;
                break;
            }
            if (pos != i)
            {
                parity = 1 - parity;
                x = a[i];
                ind_a[a[i]] = pos;
                ind_a[a[pos]] = i;
                a[i] = a[pos];
                a[pos] = x;
            }
        }

        cout << (parity ? "NO\n" : "YES\n");
        ind_a.clear();
    }

    return 0;
}
