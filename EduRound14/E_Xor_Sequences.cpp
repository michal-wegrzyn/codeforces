#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll nums[103];

ll matrices[103][103][80];

int n;
ll aux;
void mult_matrices(int pos1, int pos2, int posr){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            aux = 0LL;
            for(int pp=0; pp<n; pp++){
                aux += matrices[i][pp][pos1]*matrices[pp][j][pos2];
                aux %= 1000000007LL;
            }
            matrices[i][j][posr] = aux;
        }
    }
}

void printMatrix(int pos){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << matrices[i][j][pos] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    ll k; cin >> k;
    for(int i=0; i<n; i++) cin >> nums[i];
    if(k==1){
        cout << n << '\n';
        return 0;
    }
    k--;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(__builtin_popcountll(nums[i]^nums[j]) % 3 == 0) matrices[i][j][0] = 1;
        }
    }
    // printMatrix(0);

    for(int i=0; i<n; i++) matrices[i][i][65] = 1;

    for(int i=1; (1LL<<i)<=k; i++){
        mult_matrices(i-1,i-1,i);
        // printMatrix(i);
    }

    for(int i=0; i<60; i++){
        if(k & (1LL<<i)){
            // cout << i << '\n';
            mult_matrices(65, i, 64);
            for(int x=0; x<n; x++){
                for(int y=0; y<n; y++) matrices[x][y][65] = matrices[x][y][64];
            }
            // printMatrix(65);
        }
    }

    long long res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) res += matrices[i][j][65];
    }

    res %= 1000000007;
    cout << res << '\n';
}