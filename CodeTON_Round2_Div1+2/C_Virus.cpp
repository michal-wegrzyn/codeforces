#include <bits/stdc++.h>
using namespace std;

vector<int> zyje;
int nums[200007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, m, a, subtracter, res;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> m;
        for(int i=0; i<m; i++){
            cin >> a;
            nums[i] = a;
        }
        sort(nums, nums+m);
        for(int i=1; i<m; i++){
            zyje.push_back(nums[i]-nums[i-1]-1);
        }
        zyje.push_back(n+nums[0]-nums[m-1]-1);
        // for(auto i : zyje) cout << i.first << ' ' << i.second << '\n';
        sort(zyje.begin(), zyje.end());
        reverse(zyje.begin(), zyje.end());
        subtracter = 0; res = 0;
        for(int i:zyje){
            if(i-2*subtracter<=0) break;
            if(i-2*subtracter<3){
                res += 1;
                break;
            }
            res += i-2*subtracter-1;
            subtracter += 2;
        }
        cout << n-res << '\n';
        zyje.clear();
    }
}