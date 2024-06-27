#include <bits/stdc++.h>
using namespace std;

bitset<100007> to_change;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, x, y, count, i1, i2;
    string a, b;
    cin >> T;
    for(int t=0; t<T; t++){
        count = 0, i1=-1, i2=-1;
        cin >> n >> x >> y;
        cin >> a >> b;
        for(int i=0; i<n; i++){
            to_change[i] = (a[i]!=b[i]);
            if(to_change[i]){
                count++;
                if(i1==-1) i1=i;
                else{
                    if(i2==-1) i2 = i;
                }
            }
        }
        if(count == 0){
            cout << 0 << '\n';
            continue;
        }
        if(count&1){
            cout << -1 << '\n';
            continue;
        }
        if(count > 2 || i2-i1 != 1){
            cout << (long long)y*count/2 << '\n';
            continue;
        }
        if(x<=y*2) cout << x << '\n';
        else if(i1>1 || i2<n-2) cout << 2*y << '\n';
        else cout << x << '\n';
    }
}