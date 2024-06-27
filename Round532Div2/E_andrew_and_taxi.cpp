#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100003];
int deg_in[100003];
vector <int> toposort;
queue <int> q;
pair<pair<int,int>,pair<int,int>> edges[100003];
int toposort_index[100003];
vector<int> result;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        edges[i] = {{c,i+1},{a,b}};
    }
    sort(edges, edges+m);
    int start, end, middle, num1, min_ok = m-1;
    start = 0; end = m; middle = m>>1;
    bool is_ok = false;
    while(start<end){
        for(int i=1; i<=n; i++){
            graph[i].clear(); deg_in[i] = 0;
        }
        toposort.clear();
        while(!q.empty()) q.pop();
        for(int i=middle; i<m; i++){
            graph[edges[i].second.first].push_back(edges[i].second.second);
            deg_in[edges[i].second.second]++;
        }
        for(int i=1; i<=n; i++) if(!deg_in[i]){
            q.push(i);
            toposort.push_back(i);
        }
        while(!q.empty()){
            num1 = q.front();
            q.pop();
            for(int i:graph[num1]){
                deg_in[i]--;
                if(!deg_in[i]){
                    q.push(i);
                    toposort.push_back(i);
                };
            }
        }

        if(toposort.size()!=n) start = middle+1;
        else{ end = middle; min_ok = min(min_ok, middle);}
        middle = (start+end) >> 1;
    }

    if(min_ok) cout << edges[min_ok-1].first.first << ' ';
    else cout << 0 << ' ';
    
    for(int i=1; i<=n; i++){
        graph[i].clear(); deg_in[i] = 0;
    }
    toposort.clear();
    while(!q.empty()) q.pop();
    for(int i=min_ok; i<m; i++){
        graph[edges[i].second.first].push_back(edges[i].second.second);
        deg_in[edges[i].second.second]++;
    }
    for(int i=1; i<=n; i++) if(!deg_in[i]){
        q.push(i);
        toposort.push_back(i);
    }
    while(!q.empty()){
        num1 = q.front();
        q.pop();
        for(int i:graph[num1]){
            deg_in[i]--;
            if(!deg_in[i]){
                q.push(i);
                toposort.push_back(i);
            };
        }
    }
    for(int i=0; i<toposort.size(); i++) toposort_index[toposort[i]] = i;
    for(int i=0; i<min_ok; i++){
        if(toposort_index[edges[i].second.second]<toposort_index[edges[i].second.first]) result.push_back(edges[i].first.second);
    }

    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for(int i:result) cout << i << ' ';
}