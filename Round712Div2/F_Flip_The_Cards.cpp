#include <bits/stdc++.h>
using namespace std;

bitset<200007> is_reversed;
bitset<200007> rev;
bitset<200007> smaller;
int biggest_on_sufix[200007];
int cards[200007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    bool is_ok;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(a>b){
            swap(a, b);
            is_reversed[a] = true;
        }
        if(a>n || b<=n){
            cout << -1 << '\n';
            return 0;
        }
        cards[a] = b;
    }

    int smallest = cards[1];
    for(int i=1; i<=n; i++){
        if(smallest<cards[i]) smaller[i] = true;
        else smallest = cards[i];
    }
    int biggest = cards[n];
    biggest_on_sufix[n+1] = -1;
    biggest_on_sufix[n] = cards[n];
    for(int i=n-1; i>0; i--){
        if(biggest > cards[i] && smaller[i]){
            cout << -1 << '\n';
            return 0;
        }
        biggest = max(biggest, cards[i]);
        biggest_on_sufix[i] = biggest;
    }
    cards[0] = 2*n+7;
    smallest = cards[0];
    int res = 0;
    /*for(int i=1; i<=n; i++){
        if(biggest_on_sufix[i]<smallest){
            smallest = cards[i];
            res += min(curr_res, curr_seq_len-curr_res);
            curr_seq_len = 0; curr_res=0;
        }
        else if(cards[i-1]<cards[i]) rev[i] = !rev[i-1];
        curr_res += (is_reversed[i] ^ rev[i]);
        smallest = min(smallest, cards[i]);
        curr_seq_len += 1;
    }*/
    int s1, s2, size1=0, size2=0, rev1=0, rev2=0;
    for(int i=1; i<=n; i++) {
        smallest = min(smallest, cards[i]);
        if(size1==0 || cards[s1] > cards[i]) {
            s1 = i;
            size1++;
            rev1 += is_reversed[i];
        }else if(size2==0 || cards[s2] > cards[i]) {
            s2 = i;
            size2++;
            rev2 += is_reversed[i];
        }else {
            cout << -1 << '\n';
            return 0;
        }
        if(smallest > biggest_on_sufix[i+1]) {
            res += min(rev1 + size2 - rev2, size1 - rev1 + rev2);
            size1 = size2 = rev1 = rev2 = 0;
        }
    }
    // res += min(curr_res, curr_seq_len-curr_res);
    cout << res << '\n';

    return 0;
}