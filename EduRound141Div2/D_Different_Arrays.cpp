#include <bits/stdc++.h>
using namespace std;

int nums[303];
int acc[200007][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    long long result;
    cin >> n;
    result = 1;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    acc[100000][0] = 1;
    for(int i=1; i<n-1; i++){
        for(int j=-99000; j<99000; j++){
            acc[j+100000][1] = acc[j-nums[i]+100000][0] + acc[-j+nums[i]+100000][0];
        }
        result = result*2 - acc[100000][1];
        result %= 998244353;
        for(int j=0; j<200000; j++){
            acc[j][0] = acc[j][1];
        }
    }
    cout << result << '\n';
}