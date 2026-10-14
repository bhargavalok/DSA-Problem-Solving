class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        int nines = sum/9;
        int remain = sum%9;
        string answer(nines,'9');
        if(remain>0) {
            answer.push_back(remain+'0');
        }
        answer.append(num-answer.length(),'0');
        return answer;
    }
};