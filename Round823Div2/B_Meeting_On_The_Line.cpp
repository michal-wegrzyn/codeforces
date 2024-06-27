#include <bits/stdc++.h>
using namespace std;

int X[100007];
int T[100007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TT, n, x, most_on_left, most_on_right;
    cin >> TT;
    for(int t=0; t<TT; t++){
        cin >> n;
        most_on_left = INT_MAX;
        most_on_right = INT_MIN;
        for(int i=0; i<n; i++) cin >> X[i];
        for(int i=0; i<n; i++) cin >> T[i];
        for(int i=0; i<n; i++){
            most_on_left = min(most_on_left, X[i]-T[i]);
            most_on_right = max(most_on_right, X[i]+T[i]);
        }
        most_on_left += most_on_right;
        cout << most_on_left/2;
        if(most_on_left&1) cout << ".5";
        cout << '\n';
    }
}