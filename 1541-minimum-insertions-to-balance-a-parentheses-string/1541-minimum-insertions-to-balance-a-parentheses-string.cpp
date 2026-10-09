class Solution {
public:
    int minInsertions(string s) {
        int need=0;
        int ans=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                need += 2;
                if(need%2!=0){
                    ans++;
                    need--;
                }
            }
            else{
                need--;
                if(need<0){
                    ans++;
                    need=1;
                }
            }
        }
        return {ans+need};
    }
};