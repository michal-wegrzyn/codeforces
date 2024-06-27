#include <bits/stdc++.h>
using namespace std;

char pos_to_char(int pos){
    return 'a'+pos-1;
}

int char_to_int(char c){
    return (int)(c-'0');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, res;
    int T, N;
    cin >> T;
    // cout << pos_to_char(char_to_int('1'));
    // return 0;
    for(int t=0; t<T; t++){
        cin >> N >> s;
        res.clear();
        s.push_back('!');
        s.push_back('!');
        s.push_back('!');
        for(int i=0; i<N; i++){
            if(s[i+2]=='0' && s[i+3] != '0'){
                res.push_back(pos_to_char(char_to_int(s[i])*10 + char_to_int(s[i+1])));
                i += 2;
            }
            else res.push_back(pos_to_char(char_to_int(s[i])));
        }
        cout << res << '\n';
    }
}