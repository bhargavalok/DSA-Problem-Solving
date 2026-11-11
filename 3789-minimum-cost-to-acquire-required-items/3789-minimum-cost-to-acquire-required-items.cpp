class Solution {
public:
long long minimumCost(int cost1, int cost2, int costBoth,int need1, int need2) {
        long long mn_=min(need1,need2);
        long long mx_=max(need1,need2);
        long long ans1=1LL*need1*cost1+1LL*need2*cost2;
        long long ans2=mn_*costBoth+1LL*(need1 - mn_)*cost1+1LL*(need2-mn_)*cost2;
        long long ans3=mx_*costBoth;
        return min({ans1,ans2,ans3});
    }
};
