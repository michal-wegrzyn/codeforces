#include <bits/stdc++.h>
using namespace std;

pair<pair<char,char>,int> t[200007]; 
vector<int> res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    bool reversed, collecting;
    string s;
    cin >> T;
    for(int tt=0; tt<T; tt++){
        cin >> s;
        reversed = true;
        if(s[0]>s.back()) reverse(s.begin(), s.end());
        else reversed = false;

        cout << (int)(s.back()-s[0]) << ' ';
        t[0] = {{s[0], 'a'}, 1};
        for(int i=1; i<s.size()-1; i++){
            t[i] = {{s[i], 'b'}, i+1};
        }
        t[s.size()-1] = {{s[s.size()-1], 'c'}, s.size()};
        sort(t, t+s.size());
        collecting = false;
        for(int i=0; i<s.size(); i++){
            if(t[i].first.second == 'a') collecting = true;
            if(collecting) res.push_back(t[i].second);
            if(t[i].first.second == 'c') collecting = false;
        }
        cout << res.size() << '\n';
        if(!reversed) for(int i:res) cout << i << ' ';
        else{
            reverse(res.begin(), res.end());
            for(int i:res) cout << s.size()+1-i << ' ';
        }
        cout << '\n';
        res.clear();
    }
}