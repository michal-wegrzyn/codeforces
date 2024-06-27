#include <bits/stdc++.h>
using namespace std;

int A[200007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, res;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> A[i];
        }
        sort(A, A+n);
        res = 1;
        if(A[0] > 0) res++;
        for(int i=1; i<n; i++){
            if(i < A[i] && i > A[i-1]) res++;
        }
        cout << res << '\n';
    }
}