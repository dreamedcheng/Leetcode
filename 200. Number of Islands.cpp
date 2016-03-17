class Solution {
public:
    int ans = 0;
    int directx[4] = {0,0,-1,1};
    int directy[4] = {-1,1,0,0};
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        
        if (m == 0)
            return 0;
        
        int n = grid[0].size();
        vector<vector<bool>> visited;
        
        for (int i = 0; i < m; i++) {
            vector<bool> tmp(n,false);
            visited.push_back(tmp);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //cout << "j:" << j <<endl;
                if (grid[i][j] == '0')  continue;
                if (visited[i][j])  continue;
                dfs(grid, visited, i, j, m, n);
                ans += 1;
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
        visited[i][j] = true;
        //if (m == 1)
           // cout << "visit:" << i << " " << j << endl;
        
        for (int k = 0; k < 4; k++) {
            //if (m == 1)
               // cout << i + directy[k] << " " << j + directx[k] << endl;
            if (i + directy[k] >= 0 && i + directy[k] < m && j + directx[k]  >= 0 && j + directx[k] < n) {
                if (grid[i + directy[k]][j + directx[k]] == '0') continue;
                if (visited[i + directy[k]][j + directx[k]]) continue;
                dfs(grid, visited, i + directy[k], j + directx[k], m, n);
            }
        }
    }
};
