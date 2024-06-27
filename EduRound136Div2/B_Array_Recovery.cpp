#include <iostream>
using namespace std;

int a[107];
int d[107];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T, n;
    cin >> T;
    bool is_ok;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++) cin >> d[i];
        a[0] = d[0];
        is_ok = true;
        for(int i=1; i<n; i++) a[i] = a[i-1] + d[i];
        for(int i=1; i<n; i++){
            if(a[i] <= 2*a[i-1] && d[i] != 0) is_ok = false;
        }
        if(is_ok){
            for(int i=0; i<n; i++) cout << a[i] << ' ';
        }
        else cout << -1;
        cout << '\n';
    }
}