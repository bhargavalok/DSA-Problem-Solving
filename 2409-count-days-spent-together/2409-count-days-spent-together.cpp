class Solution {
public:
        // Here We have declared a Helper Function !! 
        int getDay(string date) {
            vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
            int m = stoi(date.substr(0,2));
            int d = stoi(date.substr(3,2));

            int total_day = d;
            for(int i=0;i<m-1;i++) {
                total_day+=days[i];
            }
            return total_day;
        }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(getDay(arriveAlice),getDay(arriveBob));
        int end = min(getDay(leaveBob),getDay(leaveAlice));
        return max(0,end-start+1);
    }
};