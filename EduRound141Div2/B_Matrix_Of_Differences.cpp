#include <bits/stdc++.h>
using namespace std;

int nums[500005];
pair<int,int> pref[500005];
bitset<500005> chosen;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, m, s, best;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> m;
        chosen.reset();

        for(int i=0; i<n; i++){
            cin >> nums[i];
            pref[i] = {nums[i], i};
        }
        sort(pref, pref+n);
        s = 0; best = 0;
        chosen[n] = true;

        for(int i=0; i<n; i++){
            if(s + (chosen[i+1]?0:nums[i+1]) <= m){
                best = i+2;
                s += pref[i].first;
                chosen[pref[i].second] = true;
            }
            else{
                s += pref[i].first;
                chosen[pref[i].second] = true;
                if(s <= m){
                    best = max(best,i+1);
                    if(chosen[i+1]) best = i+2;
                }
            }

            if(s>m) break;
        }

        if(best == n+1) cout << 1 << '\n';
        else cout << n+1 - best << '\n';
    }
}