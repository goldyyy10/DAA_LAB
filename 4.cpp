#include <bits/stdc++.h>

using namespace std;

// Time Complexity : O(nodes * edges) OR O(N^2)

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &vec){
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int u = vec[j][0];
            int v = vec[j][1];
            int wt = vec[j][2];

            if((dist[u] != 1e9) && (dist[u] + wt < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }

    bool flag = false;

    for(int j = 0; j < m; ++j){
        int u = vec[j][0];
        int v = vec[j][1];
        int wt = vec[j][2];

        if((dist[u] != 1e9) && (dist[u] + wt < dist[v])){
            flag = true;
            break;
        }
    }

    if(flag == false)
        return dist;

    vector<int> temp;
    temp.push_back(-1);

    return temp;
}

int main(){
    cout << "Enter number of nodes and edges : ";

    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> vec;

    for(int i = 0; i < edges; ++i){
        cout << "Enter u v and wt for edge " << i + 1 << " : ";

        int u, v, wt;
        cin >> u >> v >> wt;

        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);

        vec.push_back(temp);
    }

    vector<int> ans;
    ans = bellmanFord(nodes, edges, 0, vec);

    if(ans.size() == 1 && ans[0] == -1){
        cout << "Negative cycle is present hence solution not possible.\n";
    }
    else{
        cout << "Solution is : " << endl;
        cout << "Node\tDistance from source" << endl;
        int i = 1;

        for(auto value: ans){
            cout << " " << i++ << "\t\t" << value << endl;
        }
    }

    return 0;
}