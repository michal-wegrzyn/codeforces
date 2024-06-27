#include <bits/stdc++.h>
using namespace std;

pair<int, char> acc[30];
int lvl[30];
string to_low;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, changes, best_res, best_l;
    string s;

    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n; cin >> s;
        for(int i=0; i<26; i++) acc[i] = {0, 'a'+i};
        for(char c : s){
            acc[c-'a'].first++;
        }
        sort(acc, acc+26);

        best_res = n;
        best_l = 1;

        for(int l=1; l<=26; l++){
            if(n%l) continue;
            changes = 0;
            for(int i=0; i<26-l; i++) changes += acc[i].first;
            for(int i=26-l; i<26; i++){
                if(acc[i].first - n/l > 0) changes += acc[i].first - n/l;
            }

            if(changes < best_res){
                best_res = changes;
                best_l = l;
            }
        }

        cout << best_res << '\n';
        for(int i=0; i<26-best_l; i++){
            lvl[acc[i].second-'a'] = acc[i].first;
        }

        to_low.clear();

        for(int i=26-best_l; i<26; i++){
            lvl[acc[i].second-'a'] = acc[i].first - n/best_l;
            if(lvl[acc[i].second-'a'] < 0) to_low.push_back(acc[i].second);
        }

        for(int i=0; i<n; i++){
            if(lvl[s[i]-'a'] <= 0) continue;
            lvl[s[i] - 'a'] --;
            s[i] = to_low.back();
            lvl[to_low.back()-'a'] ++;
            if(lvl[to_low.back()-'a'] == 0) to_low.pop_back();
        }

        cout << s << '\n';

    }
}