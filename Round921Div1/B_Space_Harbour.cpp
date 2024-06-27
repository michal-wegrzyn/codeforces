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

constexpr int base = (1 << 19);
ll tree[base * 2 + 7];
pair<ll, ll> lazy[base * 2 + 7];

inline void push(int v, int s)
{
    s /= 2;
    tree[v * 2] += lazy[v].first * s + lazy[v].second * (s - 1) * s / 2;
    lazy[v * 2].first += lazy[v].first;
    lazy[v * 2].second += lazy[v].second;
    lazy[v].first += lazy[v].second * s;
    tree[v * 2 + 1] += lazy[v].first * s + lazy[v].second * (s - 1) * s / 2;
    lazy[v * 2 + 1].first += lazy[v].first;
    lazy[v * 2 + 1].second += lazy[v].second;
    lazy[v] = {0, 0};
}

void add(int ql, int qr, pair<ll, ll> value, int v, int l, int r)
{
    if (ql > r || qr < l)
        return;
    if (ql <= l && r <= qr)
    {
        int s = r - l + 1;
        value.first += value.second * (l - ql);
        tree[v] += value.first * s + value.second * (s - 1) * s / 2;
        lazy[v].first += value.first;
        lazy[v].second += value.second;
        return;
    }
    push(v, r - l + 1);
    int m = (l + r + 1) / 2;
    add(ql, qr, value, v * 2, l, m - 1);
    add(ql, qr, value, v * 2 + 1, m, r);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

ll query(int ql, int qr, int v, int l, int r)
{
    if (ql > r || qr < l)
        return 0;
    if (ql <= l && r <= qr)
        return tree[v];
    push(v, r - l + 1);
    int m = (l + r + 1) / 2;
    return query(ql, qr, v * 2, l, m - 1) + query(ql, qr, v * 2 + 1, m, r);
}

#ifdef DEBUG
void print_tree()
{
    int a;
    for (int i = base; i < base * 2; i++)
    {
        a = tree[i];
        for (int j = i / 2, s = 1; j; j /= 2, s++)
            a += lazy[j].first + lazy[j].second * (i - (j << s));
        cout << a << ' ';
    }
    cout << '\n';
    for (int s = 1; s <= base; s *= 2)
    {
        for (int i = s; i < s * 2; i++)
            cout << tree[i] << ' ';
        cout << '\n';
    }

    for (int s = 1; s <= base; s *= 2)
    {
        for (int i = s; i < s * 2; i++)
            cout << lazy[i] << ' ';
        cout << '\n';
    }
}
#else
void print_tree()
{
}
#endif

set<int> harbours;
set<int> n_harbours;
ll values[300007];
vector<int> h;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q, t, l, r, x;
    ll p, v;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        h.push_back(p);
        harbours.insert(p);
        n_harbours.insert(-p);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> v;
        values[h[i]] = v;
    }

    for (int i = 1; i <= n; i++)
    {
        l = -*(n_harbours.lower_bound(-i));
        r = *(harbours.lower_bound(i));
        tree[base + i] = values[l] * (r - i);
    }

    for (int i = base - 1; i; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];

    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> v;
            l = -*(n_harbours.lower_bound(-x));
            r = *(harbours.lower_bound(x));
            values[x] = v;
            add(l + 1, x, {-values[l] * (r - x), 0}, 1, 0, base - 1);
            debug(l + 1, x, -values[l] * (r - x), 0);
            add(x + 1, r, {(values[x] - values[l]) * (r - x - 1), values[l] - values[x]}, 1, 0, base - 1);
            debug(x + 1, r, (values[x] - values[l]) * (r - x - 1), values[l] - values[x]);
            harbours.insert(x);
            n_harbours.insert(-x);
        }
        else
        {
            cin >> l >> r;
            cout << query(l, r, 1, 0, base - 1) << '\n';
        }
        print_tree();
        debug("--------------");
    }

    return 0;
}
