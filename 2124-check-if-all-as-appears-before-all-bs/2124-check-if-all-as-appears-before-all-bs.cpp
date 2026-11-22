class Solution {
public:
    bool checkString(string s) {
        vector<int> a_indices;
        vector<int> b_indices;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a') {
                a_indices.push_back(i);
            }
            else {
                b_indices.push_back(i);
            }
        }

        if(a_indices.empty() || b_indices.empty()) {
            return true;
        }

        if(a_indices.back() < b_indices.front()) {
            return true;
        }

        return false;
    }
};