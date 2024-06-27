#include <bits/stdc++.h>
using namespace std;

bitset<200007> ok_end;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n=0, b;
    cin >> T;
    ok_end[0] = true;
    for(int t=1; t<=T; t++){
        for(int i=1; i<=n; i++) ok_end[i] = false;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> b;
            if(ok_end[i-1] && i+b<=n) ok_end[i+b] = true;
            if(i-b-1>=0 && ok_end[i-b-1]) ok_end[i] = true;
        }
        cout << (ok_end[n]?"YES\n":"NO\n");
    }
}