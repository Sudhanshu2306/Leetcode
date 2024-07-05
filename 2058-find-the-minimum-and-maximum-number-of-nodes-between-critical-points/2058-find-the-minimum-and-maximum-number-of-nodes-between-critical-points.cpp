// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return {-1, -1};
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        vector<int> criticalPoints;
        int dist = 1;

        while(next != nullptr) {
            if((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(dist);
            }
            dist++;
            prev = curr;
            curr = next;
            next = next->next;
        }

        if(criticalPoints.size() < 2) return {-1, -1};

        int mini = INT_MAX;
        for(size_t i = 1; i < criticalPoints.size(); ++i) {
            mini = min(mini, criticalPoints[i] - criticalPoints[i - 1]);
        }
        int maxi = criticalPoints.back() - criticalPoints.front();
        
        return {mini, maxi};
    }
};
