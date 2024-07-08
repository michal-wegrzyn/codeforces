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

int value[200007][3];
int min_r[200006][3];

int order[3] = {0, 1, 2};
int solution[6];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, r;
    ll total, min_value, s;
    bool skip;
    cin >> t;
    while (t--)
    {
        cin >> n;
        total = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> value[j][i];
                if (i == 0)
                    total += value[j][i];
            }
            if (i == 0)
                min_value = (total + 2) / 3;
            r = 0;
            s = 0;
            for (int j = 1; j <= n; j++)
            {
                s -= value[j - 1][i];
                while (s < min_value)
                {
                    if (r == n)
                        break;
                    r += 1;
                    s += value[r][i];
                }
                if (s < min_value)
                    min_r[j][i] = -1;
                else
                    min_r[j][i] = r;
            }
            min_r[n + 1][i] = -1;
        }

        skip = 0;

        for (int o = 0; o < 6; o++)
        {
            next_permutation(order, order + 3);
            if (skip)
                continue;
            r = 0;
            for (int i = 0; i < 3; i++)
            {
                solution[order[i] * 2] = r + 1;
                if (r != -1)
                    r = min_r[r + 1][order[i]];
                solution[order[i] * 2 + 1] = r;
            }
            if (r != -1)
            {
                for (int i = 0; i < 6; i++)
                    cout << solution[i] << ' ';
                cout << '\n';
                skip = 1;
            }
        }

        if (!skip)
            cout << -1 << '\n';
    }

    return 0;
}
