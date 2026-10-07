class Solution {
public:

    vector<string> ans;

    void dfs(string &s,
             int index,
             int leftRemove,
             int rightRemove,
             int open,
             string &path,
             bool prevRemoved) {

        // Base case
        if (index == s.size()) {

            if (leftRemove == 0 &&
                rightRemove == 0 &&
                open == 0) {

                ans.push_back(path);
            }

            return;
        }

        char ch = s[index];

        // ---------------------------------
        // CASE 1: '('
        // ---------------------------------
        if (ch == '(') {
            // option1: remove '('
            if (leftRemove > 0) {
                if (!(index > 0 &&
                      s[index] == s[index - 1] &&
                      !prevRemoved)) {
                    dfs(s,
                        index + 1,
                        leftRemove - 1,
                        rightRemove,
                        open,
                        path,
                        true);
                }
            }

            // option2: keep '('
            path.push_back('(');

            dfs(s,
                index + 1,
                leftRemove,
                rightRemove,
                open + 1,
                path,
                false);

            path.pop_back();
        }
        // case2: ')'
        else if (ch == ')') {
            // option1: remove ')'
            if (rightRemove > 0) {
                // Skip duplicate removal
                // ONLY if previous identical character
                // was NOT removed
                if (!(index > 0 &&
                      s[index] == s[index - 1] &&
                      !prevRemoved)) {
                    dfs(s,
                        index + 1,
                        leftRemove,
                        rightRemove - 1,
                        open,
                        path,
                        true);
                }
            }

            // Option2: keep ')'
            if (open > 0) {
                path.push_back(')');
                dfs(s,
                    index + 1,
                    leftRemove,
                    rightRemove,
                    open - 1,
                    path,
                    false);
                path.pop_back();
            }
        }
        // case3: letter
        else {
            path.push_back(ch);
            dfs(s,
                index + 1,
                leftRemove,
                rightRemove,
                open,
                path,
                false);

            path.pop_back();
        }
    }


    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        int leftRemove = 0;
        int rightRemove = 0;
        // step1: Calculate minimum removals
        for (char ch : s) {
            if (ch == '(') {
                leftRemove++;
            }

            else if (ch == ')') {
                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        string path;
        // backtracking part 
        dfs(s,
            0,
            leftRemove,
            rightRemove,
            0,
            path,
            false);

        return ans;
    }
};