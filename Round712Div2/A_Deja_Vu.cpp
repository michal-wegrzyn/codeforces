#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T, b, e;
    string s;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> s;
        for(b=0; s[b]=='a'; b++);
        for(e=0; s[s.size()-1-e]=='a'; e++);
        if(b==s.size()) cout << "NO\n";
        else{
            cout << "YES\n";
            if(b>=e) cout << 'a' << s << '\n';
            else cout << s << 'a' << '\n';
        }
    }
}