#include <bits/stdc++.h>
using namespace std;

vector<long long> div_a;
vector<long long> div_b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    long long a, b, c, d, x, y;
    bool sstop;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> a >> b >> c >> d;
        div_a.clear(); div_b.clear();
        for(long long i=1; i*i<=a; i++){
            if(a%i == 0){
                div_a.push_back(i);
                if(i*i<a) div_a.push_back(a/i);
            }
        }
        for(long long i=1; i*i<=b; i++){
            if(b%i == 0){
                div_b.push_back(i);
                if(i*i<b) div_b.push_back(b/i);
            }
        }
        sort(div_a.begin(), div_a.end());
        sort(div_b.begin(), div_b.end());
        sstop = false;
        for(long long i:div_a){
            for(long long j:div_b){
                x = a/i*j;
                y = b/j*i;
                if(x>c || y>d) continue;
                if(c/x > 1 || d/y>1){
                    x *= c/x; y *= d/y;
                    if(x<=a || y<=b) continue;
                    sstop = true;
                    break;
                }
            }
            if(sstop) break;
        }
        if(sstop) cout << x << ' ' << y << '\n';
        else cout << -1 << ' ' << -1 << '\n';
    }
}