#include <bits/stdc++.h>
using namespace std;

pair<int,int> A[100007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, a;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a;
            A[i] = {a, i+2};
        }
        for(int i=0; i<n-1; i++){
            A[i].first = max(0, A[i].first-A[i+1].first);
        }
        sort(A, A+n-1);
        cout << n << ' ';
        for(int i=0; i<n-1; i++) cout << A[i].second << ' ';
        cout << '\n';
    }
}