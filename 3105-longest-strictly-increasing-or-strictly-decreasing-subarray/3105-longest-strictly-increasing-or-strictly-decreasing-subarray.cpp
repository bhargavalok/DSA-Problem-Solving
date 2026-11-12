class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increase_ = 1;
        int decrease_ = 1;
        int ans = 1;

        for(int i=1;i<nums.size();i++) {
            if(nums[i]>nums[i-1]) {
                increase_++;
                decrease_ = 1;
            }
            else if(nums[i]<nums[i-1]) {
                decrease_++;
                increase_ = 1;
            }
            else {
                increase_ = 1;
                decrease_ = 1;
            }
            ans=max(ans,max(increase_,decrease_));
        }
        return ans;
    }
};