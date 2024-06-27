#include <bits/stdc++.h>
using namespace std;

int num_index[200007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, a, min_i, max_i;
    long long res;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a;
            num_index[a] = i;
        }
        min_i = num_index[0];
        max_i = num_index[0];
        res = 0;
        for(int i=1; i<=n; i++){
            min_i = min(min_i, num_index[(i-1)/2]);
            max_i = max(max_i, num_index[(i-1)/2]);
            if(max_i-min_i<i){
                // cout << min(i-max_i+min_i, min(min_i+1, n-max_i)) << ' ';
                res += min(i-max_i+min_i, min(min_i+1, min(n-max_i, n-i+1)));
            }
        }
        cout << res << '\n';
    }
}