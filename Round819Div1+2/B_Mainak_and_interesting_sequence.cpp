#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t, n, m;
    cin >> t;
    for(int T=0; T<t; T++){
        cin >> n >> m;
        if(n>m){
            cout << "No\n";
            continue;
        }
        if(n%2==1){
            cout << "Yes\n";
            for(int i=0; i<n-1; i++) cout << 1 << ' ';
            cout << m-n+1 << '\n';
            continue;
        }
        if(m%2==0){
            cout << "Yes\n";
            for(int i=0; i<n-2; i++) cout << 1 << ' ';
            cout << (m-n+2)/2 << ' ' << (m-n+2)/2 << '\n';
        }
        else cout << "No\n";
    }
}