#include <bits/stdc++.h>
using namespace std;

int nums[10007];
vector<int> res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K, a;
    cin >> N >> K;
    for(int i=0; i<=max(N,10); i++) nums[i] = 0;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    for(int i=0; i<max(N,10); i++){
        nums[i] += K%4;
        nums[i+1] += nums[i]/4;
        nums[i] %= 4;
        K/=4;
    }
    for(int i=0; i<=max(N, 10); i++) res.push_back(nums[i]);
    while(!res.back()) res.pop_back();
    for(int i:res) cout << i << ' ';
    cout << '\n';
    
}