class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(begin(s),end(s)))
            return 0;

        if(n==2) return -1;
        char mn = *min_element(begin(s),end(s));
        char mx = *max_element(begin(s),end(s));
        if(s[0]==mn || s[n-1]==mx) {
            return 1;
        }
        for(int i=1;i<n-1;i++) {
            if(s[i]==mn || s[i]==mx) {
                return 2;
            }
        }
        return 3;
    }
};
    