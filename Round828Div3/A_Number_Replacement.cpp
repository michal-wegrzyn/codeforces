#include <bits/stdc++.h>
using namespace std;

int A[53];
char nums[53];

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T, n, a;
    bool is_ok;
    string s;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> A[i];
        }
        cin >> s;
        for(int i=0; i<n; i++){
            nums[A[i]] = s[i];
        }
        is_ok = true;
        for(int i=0; i<n; i++){
            if(nums[A[i]] != s[i]) is_ok = false;
        }
        cout << (is_ok?"YES\n":"NO\n");
    }
}