class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == target) {
                nums[i] = i;
            }
            else {
                nums.erase(nums.begin() + i);
            }
        }

        return nums;
    }
};