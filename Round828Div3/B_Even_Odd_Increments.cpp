#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, q, a, b;
    long long odd_count, even_count, res;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> q;
        res = 0LL; odd_count = 0; even_count = 0;
        for(int i=0; i<n; i++){
            cin >> a;
            res += a;
            if(a&1) odd_count++;
            else even_count++;
        }
        for(int i=0; i<q; i++){
            cin >> a >> b;
            if(a==1){
                res += odd_count*b;
                if(b&1){
                    even_count += odd_count;
                    odd_count = 0;
                }
            }
            else{
                res += even_count*b;
                if(b&1){
                    odd_count += even_count;
                    even_count = 0;
                }
            }
            cout << res << '\n';
        }
    }
}