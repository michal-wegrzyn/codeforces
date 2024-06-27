#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, x, y;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> x >> y;
        if(x>y) swap(x,y);
        if(x==0 && y==0){
            cout << -1 << '\n';
            continue;
        }
        if(x || ((n-1)%y)){
            cout << -1 << '\n';
            continue;
        }
        for(int i=0; i<n-1; i++){
            cout << i/y*y+2 << ' ';
        }
        cout << '\n';
    }
}