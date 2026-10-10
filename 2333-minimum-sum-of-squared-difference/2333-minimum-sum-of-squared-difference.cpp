class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<int> diff;
        int maxi = 0;
        long long total = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            maxi = max(maxi, d);
            total += d;
        }
        if (total <= k) return 0;
        int left = 0, right = maxi;
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;
            for (int d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
            }
            if (need <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        long long ans = 0;
        long long used = 0;
        for (int d : diff) {
            int value = min(d, left);
            ans += 1LL * value * value;
            if (d > left) {
                used += d - left;
            }
        }
        long long remaining = k - used;
        ans -= remaining * (2LL * left - 1);
        return ans;
    }
};