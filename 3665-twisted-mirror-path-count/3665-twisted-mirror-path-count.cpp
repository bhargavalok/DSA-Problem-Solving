class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    const int MOD = 1e9 + 7;
    vector<vector<int>> fromLeft(m, vector<int>(n, 0));
    vector<vector<int>> fromTop(m, vector<int>(n, 0));
    fromLeft[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                int ways = (fromLeft[i][j] + fromTop[i][j]) % MOD;

                if(j + 1 < n)
                    fromLeft[i][j + 1] = (fromLeft[i][j + 1] + ways) % MOD;

                if(i + 1 < m)
                    fromTop[i + 1][j] = (fromTop[i + 1][j] + ways) % MOD;
            }
            else {
                if(i + 1 < m)
                    fromTop[i + 1][j] = (fromTop[i + 1][j] + fromLeft[i][j]) % MOD;

                if(j + 1 < n)
                    fromLeft[i][j + 1] = (fromLeft[i][j + 1] + fromTop[i][j]) % MOD;
            }
        }
    }
    return (fromLeft[m - 1][n - 1] + fromTop[m - 1][n - 1]) % MOD;
}
};
