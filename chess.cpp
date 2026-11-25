#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, -1, 1, 1};
int dc[] = {1, -1, 1, -1};

bool isValid (int r, int c){
    return r >= 0 && c >= 0 && r < 8 && c < 8;
}

void find(int c, int r, vector<vector<int>>& grid, vector<pair<char, int>>& path, vector<vector<pair<char,int>>>& res, pair<char,int>& end){
    if (r == end.second && c+'A' == end.first){
        res.push_back(path);
        return;
    }
    grid[r][c] = 1;

    for (int i = 0; i < 4; i++){
        for (int j = 1; j < 8; j++){
            int nr = r + dr[i] * j;
            int nc = c + dc[i] * j;
            if (isValid(nr, nc)){
                cout << "nr: " << nr << " nc: " << nc << '\n';
                path.push_back({nc, nr});
                find(nc, nr, grid, path, res, end);
                path.pop_back();
            }
       }
    }

    grid[r][c] = 0;
}

int main(){

    int tc;
    cin >> tc;
    while (tc--){
        vector<vector<int>> grid(8, vector<int>(8));
        vector<pair<char, int>> path;
        vector<vector<pair<char,int>>> res;
        pair<char, int> start, end;
        char a;
        int b;
        cin >> a >> b;
        start = {a, b};
        cin >> a >> b;
        end = {a, b};

        find(start.first-'A', start.second, grid, path, res, end);
        if (res.size() == 0) cout << "Impossible\n";
        
    }

    return EXIT_SUCCESS;
}