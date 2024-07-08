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

int rows[507][2];
int cols[507][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m;
    char a;
    bool ok;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < 2; i++)
        {
            for (int r = 0; r < n; r++)
                rows[r][i] = 0;

            for (int c = 0; c < m; c++)
                cols[c][i] = 0;

            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < m; c++)
                {
                    cin >> a;
                    rows[r][i] += a - '0';
                    cols[c][i] += a - '0';
                }
            }
        }

        ok = 1;

        for (int r = 0; r < n; r++)
            if (rows[r][0] % 3 != rows[r][1] % 3)
            {
                ok = 0;
                break;
            }

        for (int c = 0; c < m; c++)
            if (cols[c][0] % 3 != cols[c][1] % 3)
            {
                ok = 0;
                break;
            }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
