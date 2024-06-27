#include <bits/stdc++.h>
using namespace std;

bitset<300003> is_ok;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T, n, count0, count1;
    bool rev, breaked;
    string s1, s2;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> s1 >> s2;
        is_ok.reset();
        count0=0; count1=0;
        rev = false; breaked = false;
        for(int i=0; i<n; i++){
            if(s1[i]=='0') count0++;
            else count1++;
            if(count0 == count1){
                is_ok[i] = true;
            }
        }
        for(int i= n-1; i>=0; i--){
            if(!((s1[i]==s2[i])^rev)){
                if(is_ok[i]) rev = !rev;
                else{
                    breaked = true;
                    break;
                }
            }
        }
        cout << (breaked?"NO\n":"YES\n");
    }
}