class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum = 0;
        int digit_sum = 0;
        for(int i=0;i<nums.size();i++) {
            element_sum+=nums[i];
// Here We have not modified the original array like we did in previous approach
            int num = nums[i]; 
            while(num>0) {
                int rem = num%10;
                digit_sum+=rem;
                num/=10;
            }
        }
        return abs(element_sum-digit_sum);
    }
};