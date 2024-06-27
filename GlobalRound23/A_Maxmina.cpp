#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, k, a;
    bool only0;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> k;
        only0 = true;
        for(int i=0; i<n; i++){
            cin >> a;
            if(a==1) only0 = false;
        }
        cout << (only0?"NO\n":"YES\n");
    }
}