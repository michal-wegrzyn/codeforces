#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, n, a, prev, mn, mx, curr_res, first_num;
    cin >> t;
    for(int T=0; T<t; T++){
        cin >> n;
        cin >> a;
        curr_res = INT_MIN;
        if(n==1){
            cout << 0 << '\n';
            continue;
        }
        first_num = a;
        mn = a;
        mx = INT_MIN;
        for(int i=1; i<n; i++){
            prev = a;
            cin >> a;
            curr_res = max(curr_res, prev-a);
            if(i!=n-1) mn = min(mn, a);
            mx = max(mx, a);
        }
        curr_res = max(max(curr_res, a-first_num), max(a-mn, mx-first_num));
        cout << curr_res << '\n';
    }
}