#include <bits/stdc++.h>
using namespace std;

int nums[60];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }
        sort(nums, nums+n);
        if(nums[0] == nums[n-1]){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        cout << nums[n-1] << ' ';
        for(int i=0; i<n-1; i++) cout << nums[i] << ' ';
        cout << '\n';
    }
}