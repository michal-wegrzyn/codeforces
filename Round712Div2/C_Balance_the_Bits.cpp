#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, count1, count0, c1, c0;
    string s, s1, s2;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> s;
        s1.clear(); s2.clear();
        count1 = 0; count0 = 0; c0 = 0; c1 = 0;
        for(char c:s){
            if(c=='1') count1++;
            else count0++;
        }
        if(count1%2 || count0%2 || s[0]=='0' || s.back()=='0'){
            cout << "NO\n";
            continue;
        }
        for(char c:s){
            if(c=='1'){
                c1++;
                if(c1 <= count1/2){
                    s1.push_back('(');
                    s2.push_back('(');
                }
                else{
                    s1.push_back(')');
                    s2.push_back(')');
                }
            }
            if(c=='0'){
                c0++;
                if(c0%2){
                    s1.push_back('(');
                    s2.push_back(')');
                }
                else{
                    s1.push_back(')');
                    s2.push_back('(');
                }
            }
        }
        cout << "YES\n" << s1 << '\n' << s2 << '\n';
    }
}
