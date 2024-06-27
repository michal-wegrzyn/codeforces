#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int deg_in[200003];
long long a[200003];
int b[200003];
vector <int> front_order;
vector <int> end_order;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, num; cin >> n;
    long long num2;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        cin >> num;
        b[i] = num;
        if(num > 0) deg_in[num]++;
    }

    queue<int> q;

    for(int i=1; i<=n; i++) if(!deg_in[i]) q.push(i);

    long long ans = 0;

    while(!q.empty()){
        num = q.front();
        q.pop();
        ans += a[num];
        if(b[num]!=-1){
            deg_in[b[num]]--;
            if(!deg_in[b[num]]) q.push(b[num]);
            if(a[num]>=(long long)0){
                a[b[num]] += a[num];
                front_order.push_back(num);
            }
            else end_order.push_back(num);
        }
        else front_order.push_back(num);
    }

    cout << ans << '\n';

    for(int i:front_order) cout << i << ' ';
    for(int i=end_order.size()-1; i>=0; i--) cout << end_order[i] << ' ';

    return 0;
}