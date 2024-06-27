#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> groups[100003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t, n, value, max_value, res, end;
    char a;
    cin >> t;
    for(int T=0; T<t; T++){
        cin >> n;
        value = 0; max_value = 0;
        for(int i=1; i<=n*2; i++){
            cin >> a;
            if(a=='('){
                groups[value].push_back({i,-1});
                value++;
            }
            else{
                value--;
                groups[value].back().second = i;
            }
            max_value = max(max_value, value);
        }
        res = 0;
        for(int i=0; i<=max_value; i++){
            end=-10;
            for(auto j : groups[i]){
                if(j.first != end+1) res ++;
                end = j.second;
                // cout << j.first << ' ' << j.second << '\n';
            }
            groups[i].clear();
        }
        cout << res << '\n';
    }
}