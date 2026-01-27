#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 12; 
    vector<vector<int>> adj(N+1);

    auto addEdge = [&](int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    // edge
    addEdge(1,2);
    addEdge(2,11);
    addEdge(11,10);
    addEdge(1,10);
    addEdge(1,4);
    addEdge(1,8);
    addEdge(1,7);
    addEdge(1,6);
    addEdge(6,5);
    addEdge(5,12);
    addEdge(6,12);
    addEdge(12,3);
    addEdge(2,3);

    for(int i = 1; i <= N; i++){
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    vector<string> name(N+1, "");
    name[1]="Ha Noi"; name[2]="Hai Duong"; name[3]="Hai Phong"; name[4]="Hoa Binh";
    name[5]="Bac Giang"; name[6]="Bac Ninh"; name[7]="Thai Nguyen"; name[8]="Son Tay";
    name[10]="Phu Ly"; name[11]="Hung Yen"; name[12]="Uong Bi";

    int start = 1;
    vector<bool> vis(N+1, false);
    queue<int> q;

    vis[start] = true;
    q.push(start);

    cout << "BFS tu " << start << ":\n";
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << " - " << name[u] << "\n";

        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return 0;
}
