class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') {
                st.push(0);
            }
            else {
                // top element inside stack at that particular moment ! 
                int innertop = st.top(); 
                st.pop();
                int value = max(1,2*innertop);
                st.top()+=value;
            }
        }
        return st.top();
    }
};