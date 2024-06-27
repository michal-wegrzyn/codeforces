#include <iostream>
using namespace std;

long long factorial[63];

long long rev(long long num){
    int w = 998244351;
    long long res = 1;
    long long curr_pow = num;
    while(w){
        if(w&1){
            res *= curr_pow;
            res %= 998244353;
        }
        w >>= 1;
        curr_pow *= curr_pow;
        curr_pow %= 998244353;
    }
    return res;
}

int nk_mod(int n, int k){
    return (((factorial[n]*rev(factorial[k]))%998244353)*rev(factorial[n-k])%998244353);
}

int w[32];
int p[32];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    factorial[0] = 1LL;
    for(int i=1; i<62; i++) factorial[i] = (factorial[i-1]*i) % 998244353;

    w[1] = 1; p[1] = 0;
    for(int i=2; i<=30; i++){
        w[i] = p[i-1] + nk_mod(2*i-1, i);
        p[i] = w[i-1] + nk_mod(2*i-2, i);
        w[i] %= 998244353;
        p[i] %= 998244353;
    }
    
    int T, n;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        n /= 2;
        cout << w[n] << ' ' << p[n] << " 1\n";
    }
}