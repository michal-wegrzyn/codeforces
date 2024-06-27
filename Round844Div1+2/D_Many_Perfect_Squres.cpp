#include <bits/stdc++.h>
using namespace std;

long long nums[55];

map<long long, long long> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n;
    long long diff, x, c2;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                diff = nums[j] - nums[i];
                for(long long c=1; c*c<=diff; c++){
                    if(diff%c) continue;
                    x = diff/c - c;
                    if(x%2) continue;
                    x /= 2;
                    if(x*x >= nums[i]){
                        mp[x*x-nums[i]] ++;
                        // cout << nums[i] << ' ' << nums[j] << ' ' << c << ' ' << x*x-nums[i] << '\n';
                    }

                    if(c*c == diff) continue;
                    c2 = diff/c;
                    x = diff/c2 - c2;
                    if(x%2) continue;
                    x /= 2;
                    if(x*x >= nums[i]){
                        mp[x*x-nums[i]] ++;
                        // cout << nums[i] << ' ' << nums[j] << ' ' << c << ' ' << x*x-nums[i] << '\n';
                    }
                }
            }
        }

        // cout << '!';

        x = 1;

        for(pair<long long, long long> i:mp){
            if(i.second > x) x = i.second;
        }
        
        cout << (long long)(ceil(sqrt(x))) << '\n';
        // cout << '\n';
        mp.clear();
    }
}