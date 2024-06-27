#include <bits/stdc++.h>
using namespace std;

int nums[300007];
int pref_res[300007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, a, best_res;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        best_res = 0;
        for(int i=0; i<n; i++){
            cin >> a;
            nums[i] = a;
            pref_res[i] = 1;
            for(int j=(max(0,i-512)); j<i; j++){
                if((nums[j]^i) < (a^j)){
                    pref_res[i] = max(pref_res[i], pref_res[j]+1);
                }
            }
            best_res = max(best_res, pref_res[i]);
        }
        cout << best_res << '\n';
    }
}