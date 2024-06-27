#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long T, a, b, c, time1, time2;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> a >> b >> c;
        time1 = a-1;
        time2 = abs(b-c) + c-1;
        if(time1 < time2) cout << 1 << '\n';
        if(time1 > time2) cout << 2 << '\n';
        if(time1 == time2) cout << 3 << '\n';
    }
}