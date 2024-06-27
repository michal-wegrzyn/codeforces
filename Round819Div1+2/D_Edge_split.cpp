#include <bits/stdc++.h>
using namespace std;

bitset<200007> marked;
int dist[200007];
int edge_num[200007];
vector<pair<int,int>> graph[200007];
vector<int> unmarked;
pair<int,int> edges[200007];
vector<int> v;

void dfs(int v){
    for(auto i:graph[v]){
        if(dist[i.first]==-1){
            dist[i.first] = dist[v]+1;
            marked[i.second] = true;
            edge_num[i.first] = i.second;
            dfs(i.first);
        }
        else{
            if(dist[v]>dist[i.first] && marked[i.second]==false) unmarked.push_back(i.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T, n, m, a, b, min_v;
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> n >> m;
        for(int i=2; i<=n; i++) dist[i] = -1;
        for(int i=1; i<=n; i++) graph[i].clear();
        marked.reset();
        unmarked.clear();
        for(int i=0; i<m; i++){
            cin >> a >> b;
            edges[i] = {a,b};
            graph[a].push_back({b,i});
            graph[b].push_back({a,i});
        }
        dfs(1);
        // cout << unmarked.size();
        if(unmarked.size()==3){
            // cout << "HERE";
            v.clear();
            for(int i:unmarked){
                v.push_back(edges[i].first);
                v.push_back(edges[i].second);
            }
            sort(v.begin(), v.end());
            if(v[0]==v[1] && v[2]==v[3] && v[4]==v[5]){
                min_v = v[0];
                if(dist[v[2]] > dist[min_v]) min_v = v[2];
                if(dist[v[4]] > dist[min_v]) min_v = v[4];
                marked[edge_num[min_v]] = false;
                if(edges[unmarked[0]].first == min_v || edges[unmarked[0]].second == min_v) marked[unmarked[0]] = true;
                else marked[unmarked[1]] = true;
            }
        }
        for(int i=0; i<m; i++) cout << marked[i];
        cout << '\n';
    }
}