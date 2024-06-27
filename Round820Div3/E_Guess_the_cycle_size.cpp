#include <iostream>
using namespace std;

int main(){
    long long num, a=-10, b = -10;
    for(int i=2; i<27; i++){
        cout << "? 1 " << i << '\n';
        cin >> a;
        cout << "? " << i << " 1\n";
        cin >> b;
        if(a==-1){ cout << '!' << ' ' << i-1 << '\n'; return 0;}
        if(a != b) break;
    }
    cout << '!' << ' ' << a + b << '\n';
    return 0;
}