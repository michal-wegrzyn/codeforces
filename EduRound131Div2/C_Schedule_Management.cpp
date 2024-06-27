#include <bits/stdc++.h>
using namespace std;

int a[200007];
int cnt[200007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m, x, max_cnt, st, en, mid, balance;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cnt[i] = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> x;
            a[i] = x;
            cnt[x]++;
        }
        max_cnt = *(max_element(cnt + 1, cnt + n + 1));

        st = 0;
        en = max_cnt;

        while (st < en)
        {
            mid = (st + en) / 2;
            balance = 0;
            for (int i = 1; i <= n; i++)
            {
                x = min(mid, cnt[i]);
                balance += x + (mid - x) / 2 - cnt[i];
            }
            if (balance < 0)
                st = mid + 1;
            else
                en = mid;
        }
        cout << st << '\n';
    }
    return 0;
}