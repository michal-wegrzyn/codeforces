#include <bits/stdc++.h>
using namespace std;

int add[33];

int c2(int a){
    int r=0;
    while((!(a&1)) && a>0){
        r++;
        a >>= 1;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, a, count2, op_count;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        count2 = 0;
        for(int i=0; i<n; i++){
            cin >> a;
            count2 += c2(a);
        }
        // cout << count2 << ' ';
        for(int i=1; i<=29; i++){
            add[i] = n/(1<<(i)) - n/(1<<(i+1));
            // cout << add[i] << ' ';
        }
        if(count2 >= n){
            cout << 0 << '\n';
            continue;
        }
        op_count = 0;
        for(int i=29; i>0; i--){
            if(count2 + add[i]*i >= n){
                op_count += (n-count2-1)/i+1;
                count2 += ((n-count2-1)/i+1)*i;
                break;
            }
            op_count += add[i];
            count2 += add[i]*i;
        }
        if(count2 < n) cout << -1 << '\n';
        else cout << op_count << '\n';
    }
}