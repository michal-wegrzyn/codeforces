#include <iostream>
using namespace std;

int orbits[107];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, c, a, res;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> c;
        for(int i=0; i<=100; i++) orbits[i] = 0;
        for(int i=0; i<n; i++){
            cin >> a;
            orbits[a]++;
        }
        res = 0;
        for(int i=0; i<=100; i++) res += min(c, orbits[i]);
        cout << res << '\n';
    }
}