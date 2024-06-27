#include <bits/stdc++.h>
using namespace std;

int pref_sum[4007][4007];
int dp[4007][807];

inline int C(int a, int b){
    return pref_sum[b][b] - pref_sum[a-1][b] - pref_sum[b][a-1] + pref_sum[a-1][a-1];
}

void compute(int layer, int st, int en, int l, int r){
    if(st>en) return;
    int mid = (st+en)/2;
    int bestPos = l, val = 0;
    for(int i = l; i<=min(r,mid); i++){
        val = dp[i-1][layer-1] + C(i, mid);
        if(val < dp[mid][layer]){
            bestPos = i;
            dp[mid][layer] = val;
        }
    }

    compute(layer, st, mid-1, l, bestPos);
    compute(layer, mid+1, en, bestPos, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    char a;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a;
            pref_sum[i][j] = pref_sum[i-1][j] + pref_sum[i][j-1] - pref_sum[i-1][j-1] + a - '0';
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++) dp[i][j] = INT_MAX/4;
    }
    dp[0][0] = 0;

    for(int i=1; i<=k; i++){
        compute(i, 1, n, 1, n);
    }

    cout << dp[n][k]/2 << '\n';
    return 0;
}