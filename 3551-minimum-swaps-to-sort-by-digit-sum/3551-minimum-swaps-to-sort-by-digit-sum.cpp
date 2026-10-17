class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        auto digitSum = [](int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);
            if (sumA == sumB) {
                return a < b;
            }
            return sumA < sumB;
        });
        unordered_map<int, int> position;
        for (int i = 0; i < n; i++) {
            position[nums[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[i]) {
                continue;
            }
            int j = position[sorted[i]];
            position[nums[i]] = j;
            position[sorted[i]] = i;
            swap(nums[i], nums[j]);
            swaps++;
        }
        return swaps;
    }
};