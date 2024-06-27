#include <bits/stdc++.h>
using namespace std;

pair<int,bool> values[100007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, a, v, res, pl;
    cin >> T;
    for(int t=0; t<T; t++){
        v = 0; res = 0; pl = 0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a;
            values[i] = {-a,1};
        }
        for(int i=0; i<n; i++){
            cin >> a;
            values[i].first += a;
            if(values[i].first<0){
                values[i].first *= -1;
                values[i].second = 0;
            }
        }
        sort(values, values+n);
        for(int i=0; i<n; i++){
            if(values[i].second){
                if(v>0){ res++; v--;}
                else pl++;
            }
            else v++;
            // cout << i << ' ' << v << ' ' << pl << ' ' << res << '\n';
        }
        res += pl/2;
        cout << res << '\n';
    }
}