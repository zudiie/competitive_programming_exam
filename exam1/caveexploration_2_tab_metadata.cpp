#include <bits/stdc++.h>

using namespace std;

int main(){
    // ---- process input ----
    int size, val;
    vector<vector<int>> grid;
    cin >> size;
    for (int i = 0; i < size; i++){
        grid.push_back({});
        for (int j = 0; j < size; j++){
            cin >> val;
            grid[i].push_back(val);
        }
    }

    int cells = size*size;
    vector<vector<pair<int, int>>> adj(cells);
    int dist;

    //filling in edges and adj
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (i != size -1  && j != size - 1){
                dist = max(grid[i][j],grid[i][j+1]);
                adj[size*i+j].push_back({size*i+j+1, dist});
                adj[size*i+j+1].push_back({size*i+j, dist});
                dist = max(grid[i][j],grid[i+1][j]);
                adj[size*i+j].push_back({size*(i+1)+j, dist});
                adj[size*(i+1)+j].push_back({size*i+j, dist});
            } 
            else if (i == size - 1 && j != size -1){
                dist = max(grid[i][j],grid[i][j+1]);
                adj[size*i+j].push_back({size*i+j+1, dist});
                adj[size*i+j+1].push_back({size*i+j, dist});
            }
            else if (j == size -1 && i != size -1 ) { // j == size - 1
                dist = max(grid[i][j],grid[i+1][j]);
                adj[size*i+j].push_back({size*(i+1)+j, dist});
                adj[size*(i+1)+j].push_back({size*i+j, dist});
            }
        }
    }

    // algorithm - we always start at 0, 0 and try to get to (size - 1, size - 1)

    std::vector<int> d(cells, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    d[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > d[u]) continue;
        if (u == cells-1) break;
        for (auto [v, w]: adj[u]){
            if (max(d[u], w) < d[v]) {
                d[v] = max(d[u], w);
                pq.push({d[v], v});
            }
        }
    }

    cout << d[cells-1] << '\n';

    return EXIT_SUCCESS;
}