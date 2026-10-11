class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int>countDiff(1e5+1,0);
        for(int i=0; i<nums1.size(); i++) {
            int d = abs(nums1[i]-nums2[i]);
            countDiff[d]++;
        }
        int k = k1+k2;
        for(int currDiff=1e5; k>0 && currDiff>0; currDiff--) {
        int countoperations = min(countDiff[currDiff], k);
        countDiff[currDiff] -= countoperations;
        countDiff[currDiff-1] += countoperations;
        k-=countoperations;
        }
        long long result = 0;
        for(long long d=1; d<=1e5; d++) {
            result+=(countDiff[d]* d*d);
        }
        return result;
    }
};