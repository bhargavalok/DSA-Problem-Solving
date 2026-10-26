class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                long long sum = grid[i][j];
                stack<pair<int,int>> st;
                st.push({i, j});
                grid[i][j] = 0;
                while(!st.empty()) {
                    auto [r, c] = st.top();
                    st.pop();
                    for(int d = 0; d < 4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] > 0) {
                            sum += grid[nr][nc];
                            grid[nr][nc] = 0;
                            st.push({nr, nc});
                        }
                    }
                }
                if(sum % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};
