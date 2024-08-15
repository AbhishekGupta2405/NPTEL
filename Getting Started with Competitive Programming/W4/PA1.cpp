#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y, int m, int n) {
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
        return 0;
    }
    
    grid[x][y] = 0;
    
    int population = 1; 
    population += dfs(grid, x + 1, y, m, n);
    population += dfs(grid, x - 1, y, m, n);
    population += dfs(grid, x, y + 1, m, n);
    population += dfs(grid, x, y - 1, m, n);
    
    return population;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int m, n;
        cin >> m >> n;
        
        vector<vector<int>> grid(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        int max_population = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    
                    int population = dfs(grid, i, j, m, n);
                    max_population = max(max_population, population);
                }
            }
        }
        
        cout << max_population << endl;
    }
}
