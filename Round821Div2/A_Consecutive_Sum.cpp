#include <bits/stdc++.h>
using namespace std;

int best_num[107];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, k, a;
    long long res;
    cin >> T;
    for(int t=0; t<T; t++){
        res = 0LL;
        cin >> n >> k;
        for(int i=0; i<k; i++) best_num[i] = 0;
        for(int i=0; i<n; i++){
            cin >> a;
            best_num[i%k] = max(best_num[i%k], a);
        }
        for(int i=0; i<k; i++) res += (long long)best_num[i];
        cout << res << '\n';
    }
}