#include <iostream>
#include <string>
using namespace std;

int total_count[11];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    char curr_min;
    string s;
    cin >> T;
    for(int t=0; t<T; t++){
        for(int i=0; i<=10; i++) total_count[i] = 0;
        cin >> s;
        curr_min = s.back();
        for(int i=s.size()-1; i>=0; i--){
            if(curr_min < s[i]) total_count[s[i]-'0'+1]++;
            else{
                total_count[s[i]-'0']++;
                curr_min = s[i];
            }
        }
        total_count[9] += total_count[10];
        for(int i=0; i<10; i++) for(int j=0; j<total_count[i]; j++) cout << i;
        cout << '\n';
    }
}