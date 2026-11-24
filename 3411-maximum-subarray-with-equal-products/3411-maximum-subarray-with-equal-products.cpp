class Solution {
public:
    int calcGcd(vector<int>& arr) {
        int ans = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            ans = gcd(ans, arr[i]);
        }
        return ans;
    }

    long long calcLcm(vector<int>& arr) {
    long long ans = arr[0];
    for(int i=1; i<arr.size(); i++) {
        ans = (ans/gcd(ans,(long long)arr[i]))*arr[i];
        }
        return ans;
    }

    long long calcProd(vector<int>& arr, long long limit) {
    long long ans = 1;
    for(int i = 0; i < arr.size(); i++) {
        if(ans > limit / arr[i]) {
            return limit + 1;
        }
        ans *= arr[i];
    }
    return ans;
    }

    int maxLength(vector<int>& nums) {
        int len_ = 2;
        for(int i=0;i<nums.size();i++) {
            for(int j=i;j<nums.size();j++) {
                vector<int>arr(nums.begin()+i,nums.begin()+j+1);
                int gcdvalue = calcGcd(arr);
                long long lcmvalue = calcLcm(arr);
                long long target = lcmvalue * gcdvalue;
                long long prodvalue = calcProd(arr, target);
                if(prodvalue == target) {
                    len_ = max(len_, (int)arr.size());
                }
            }
        }
        return len_;
    }
};

