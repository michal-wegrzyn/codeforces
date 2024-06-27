#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

vector<int> graph[100007];
bitset<100007> is_black;
long long dp[100007][2];

long long multMOD(long long a, long long b){
    return (a*b)%MOD;
}

long long divMOD(long long a, long long b){
    long long b_inv = 1;
    long long exp = MOD - 2;
    while(exp){
        if(exp&1){
            b_inv *= b;
            b_inv %= MOD;
        }
        b = multMOD(b,b);
        exp >>= 1;
    }
    return multMOD(a, b_inv);
}

void dfs(int v){
    for(int u: graph[v]) dfs(u);
    if(is_black[v]){
        dp[v][1] = 1LL;
        for(int u:graph[v]){
            dp[v][1] *= (dp[u][0] + dp[u][1]);
            dp[v][1] %= MOD;
        }
    }
    else{
        dp[v][0] = 1LL;
        for(int u:graph[v]){
            dp[v][0] *= (dp[u][0] + dp[u][1]);
            dp[v][0] %= MOD;
        }
        for(int u:graph[v]){
            dp[v][1] += multMOD(divMOD(dp[v][0], dp[u][0]+dp[u][1]), dp[u][1]);
        }
        dp[v][1] %= MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,a;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> a;
        graph[a].push_back(i);
    }
    for(int i=0; i<n; i++){
        cin >> a;
        is_black[i] = (a==1);
    }

    dfs(0);
    cout << dp[0][1] << '\n';
}