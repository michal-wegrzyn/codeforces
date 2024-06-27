#include <bits/stdc++.h>
using namespace std;

pair<int,int> dominos[100007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, c, mx, cnt = 0, start_a;
    long long res=0LL;
    cin >> n;
    cin >> a >> c;
    dominos[0] = {a, c};
    start_a = a;
    res += c;
    for(int i=1; i<n; i++){
        cin >> a >> c;
        dominos[i] = {a, c};
        res += c;
    }
    sort(dominos, dominos+n);
    mx = dominos[0].first;
    for(int i=0; i<n; i++){
        if(mx < dominos[i].first){
            // cout << dominos[i].first << ' ' << mx << '\n';
            res += dominos[i].first - mx;
        }
        if(dominos[i].first+dominos[i].second>mx){
            mx = dominos[i].first+dominos[i].second;
        }
    }
    cout << res << '\n';
}