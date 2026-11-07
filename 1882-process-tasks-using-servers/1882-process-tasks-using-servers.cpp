class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;
        using T = tuple<long long,int,int>;
        priority_queue<T, vector<T>, greater<T>> busy;

        for(int i = 0; i < n; i++)
            free.push({servers[i], i});

        vector<int> ans(m);
        long long time = 0;

        for(int i = 0; i < m; i++) {
            time = max(time, (long long)i);

            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [end, weight, idx] = busy.top();
                busy.pop();
                free.push({weight, idx});
            }

            if(free.empty()) {
                time = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) == time) {
                    auto [end, weight, idx] = busy.top();
                    busy.pop();
                    free.push({weight, idx});
                }
            }

            auto [weight, idx] = free.top();
            free.pop();

            ans[i] = idx;
            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};
