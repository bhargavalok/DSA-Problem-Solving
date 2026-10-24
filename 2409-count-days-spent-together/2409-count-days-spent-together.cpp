class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        auto convert = [&](string s) {
            int d = stoi(s.substr(0,2));
            int day = stoi(s.substr(3,2));
            for(int i = 0; i < d - 1; i++)
                day += days[i];
            return day;
        };

        int a = convert(arriveAlice);
        int b = convert(leaveAlice);
        int c = convert(arriveBob);
        int d = convert(leaveBob);

        return max(0, min(b,d) - max(a,c) + 1);
    }
};
