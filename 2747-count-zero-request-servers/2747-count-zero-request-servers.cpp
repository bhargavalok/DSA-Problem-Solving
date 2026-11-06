class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int q = queries.size();
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> freq(n + 1, 0);
        vector<int> ans(q);
        int l = 0, r = 0;
        int active = 0;
        int m = logs.size();
        for (auto [time, idx] : sortedQueries) {
            int start = time - x;
            while (r < m && logs[r][1] <= time) {
                int id = logs[r][0];
                if (freq[id] == 0) active++;
                freq[id]++;
                r++;
            }
            while (l < r && logs[l][1] < start) {
                int id = logs[l][0];
                freq[id]--;
                if (freq[id] == 0) active--;
                l++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};
