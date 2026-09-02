class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX, first = -1, last = -1;
        for (int i = 0; head->next->next; head = head->next, ++i) {
            int a = head->val, b = head->next->val, c = head->next->next->val;
            if (b < min(a, c) || b > max(a, c)) {
                if (last == -1) {
                    first = last = i;
                } else {
                    minDist = min(minDist, i - last);
                    last = i;
                }
            }
        }
        return first == last ? vector<int>{-1, -1}
                             : vector<int>{minDist, last - first};
    }
};   