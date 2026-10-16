class Solution {
    static constexpr long long MOD = 1'000'000'007LL;
    struct Node {
        long long sum = 0;
        long long sq = 0;
        int lazy = 0;
    };
    int n;
    vector<Node> seg;
    void apply(int node, int l, int r, int delta) {
        long long len = r - l + 1;
        long long oldSum = seg[node].sum;
        seg[node].sq =
            (seg[node].sq
             + 2LL * delta * oldSum
             + 1LL * delta * delta * len) % MOD;
        seg[node].sum =
            (oldSum + 1LL * delta * len) % MOD;
        seg[node].lazy += delta;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r) {
            return;
        }
        int mid = l + (r - l) / 2;
        int delta = seg[node].lazy;
        apply(node * 2, l, mid, delta);
        apply(node * 2 + 1, mid + 1, r, delta);
        seg[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            update(node * 2, l, mid, ql, qr);
        }
        if (qr > mid) {
            update(node * 2 + 1, mid + 1, r, ql, qr);
        }
        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, Node{});
        vector<int> last(100001, -1);
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            int x = nums[r];
            int previous = last[x];
            update(1, 0, n - 1, previous + 1, r);
            last[x] = r;
            ans = (ans + seg[1].sq) % MOD;
        }
        return static_cast<int>(ans);
    }
};
