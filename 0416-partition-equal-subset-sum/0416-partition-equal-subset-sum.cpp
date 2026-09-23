class Solution {
public:
                        // Bottom Up Approach : THE Last Stage !!! 
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) {
            total += x;
        }
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;
        vector<vector<bool>> dp(nums.size() + 1,vector<bool>(target + 1, false));
        dp[0][0] = true;

        for (int i=1;i<=nums.size();i++) {
            for (int j=0;j<=target;j++) {
                                // notTaken !!! 
            bool notTaken = dp[i-1][j];
                                // taken !! 
            bool taken = false;
            if(nums[i-1]<=j) {
                taken = dp[i-1][j-nums[i-1]];
            }
            dp[i][j]=taken || notTaken;
            }
        }
        return dp[nums.size()][target];
    }
};