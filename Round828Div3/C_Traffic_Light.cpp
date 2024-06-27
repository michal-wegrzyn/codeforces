#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, first_g, first_index, res;
    char c;
    string s;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> c >> s;
        if(c == 'g'){
            cout << 0 << '\n';
            continue;
        }
        first_g = -1; first_index = -1; res = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'g'){
                if(first_g == -1) first_g = i;
                if(first_index != -1) res = max(res, i-first_index);
                first_index = -1;
            }
            if(s[i] == c && first_index == -1) first_index = i;
        }
        if(first_index != -1) res = max(res, n-first_index+first_g);
        cout << res << '\n';
    }
}