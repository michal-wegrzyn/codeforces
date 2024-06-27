#include <bits/stdc++.h>
using namespace std;

bitset<100007> parity;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, a, last_same;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a;
            parity[i] = (a&1);
        }
        last_same = 0;
        for(int i=1; i<n; i++){
            if(parity[i] == parity[0]) last_same = i;
        }
        cout << n-1 << '\n';
        if(last_same) cout << 1 << ' ' << last_same+1 << '\n';
        for(int i=1; i<n; i++){
            if(parity[i] != parity[0]) cout << 1 << ' ' << i+1 << '\n';
            else if(i!=last_same){
                cout << i+1 << ' ' << last_same+1 << '\n';
            }
        }
    }
}