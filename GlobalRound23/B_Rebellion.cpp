#include <bits/stdc++.h>
using namespace std;

bitset<100007> A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, a, st, en, res;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a;
            A[i] = (a==1);
        }
        st = 0; en = n; res = 0;
        for(st = 0; st<en; st++){
            if(A[st] == false) continue;
            while(A[--en] == true && en>st);
            if(en == st) break;
            else res++;
        }
        cout << res << '\n';
    }
}