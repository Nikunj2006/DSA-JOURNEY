class Solution {
public:
    int day(string s) {
        static int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int m = stoi(s.substr(0, 2));
        int d = stoi(s.substr(3, 2));

        for (int i = 1; i < m; i++)
            d += days[i];

        return d;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int start = max(day(arriveAlice), day(arriveBob));
        int finish = min(day(leaveAlice), day(leaveBob));

        return max(0, finish - start + 1);
    }
};