#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, w, d, h, a, b, f, g, best;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> w >> d >> h >> a >> b >> f >> g;
        best = abs(a-f) + min(b+g, 2*d-b-g) + h;
        best = min(best, abs(b-g) + min(a+f, 2*w-a-f) + h);
        cout << best << '\n';
    }
}