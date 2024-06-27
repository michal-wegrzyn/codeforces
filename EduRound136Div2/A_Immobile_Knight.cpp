#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, m;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> m;
        if(n==1 || m==1) cout << "1 1\n";
        else cout << "2 2\n";
    }
}