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

bool used[200007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, num, d = 2;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << d << '\n';
        for (int i = 1; i <= n; i++)
        {
            num = i;
            while (!used[num])
            {
                used[num] = 1;
                cout << num << ' ';
                num *= d;
                if (num > n)
                    break;
            }
            used[i] = 0;
        }
        cout << '\n';
    }

    return 0;
}
